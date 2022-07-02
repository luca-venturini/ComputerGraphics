// This has been adapted from the Vulkan tutorial

#include "MyProject.hpp"

const float LINEAR_VEL = 2.5f;
const float ANGULAR_VEL = 0.2f;
const float CAMERA_VEL = 0.5f;

const std::string TRUCK_PATH = "models/Hummer.obj";
const std::string TRUCK_TEXTURE = "textures/HummerDiff.png";


const std::string GROUND_PATH = "models/BOTW.obj"; //TerrainCenter.obj";
const std::string GROUND_TEXTURE = "textures/COLORED.png";//Terrain.jpg";

const std::string HEIGHT_MAP = "textures/BOTW2.png";//displacementtest.png";

glm::vec3 truckPose = glm::vec3(0.0, 0.0, 0.0);
glm::vec3 groundPose = glm::vec3(0.0, 0.0, 0.0);
glm::vec3 deltaCameraPose = glm::vec3(-2.0, 0.0, 1.0);
glm::vec3 startingDelta = glm::vec3(-2.0, 0.0, 1.0);

float yaw = 0.0f;
float pitch = 0.0f;
float roll = 0.0f;

float truckAngle = 0.0f;
float cameraAngle = 0.0f;

int pixRear;
int pixFront;

stbi_uc* heightMap;
int heightMapWidth, heightMapHeight;

// The uniform buffer object used in this example
struct UniformBufferObject {
	alignas(16) glm::mat4 model;
};

struct GlobalUniformBufferObject {
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};


// MAIN ! 
class MyProject : public BaseProject {
	protected:
	// Here you list all the Vulkan objects you need:
	
	// Descriptor Layouts [what will be passed to the shaders]
	DescriptorSetLayout globalDSL;
	DescriptorSetLayout modelDSL;

	// Pipelines [Shader couples]
	Pipeline P1;

	// Models, textures and Descriptors (values assigned to the uniforms)
	Model truckModel;
	Model groundModel;
	Texture truckTexture;
	Texture groundTexture;
	DescriptorSet globalDS;
	DescriptorSet truckDS;
	DescriptorSet groundDS;
	
	// Here you set the main application parameters
	void setWindowParameters() {
		// window size, titile and initial background
		windowWidth = 800;
		windowHeight = 600;
		windowTitle = "Monster Truck";
		initialBackgroundColor = {0.0f, 0.0f, 0.0f, 1.0f};
		
		// Descriptor pool sizes
		uniformBlocksInPool = 3;
		texturesInPool = 2;
		setsInPool = 3;
	}

	glm::mat4 LookAtMat(glm::vec3 cameraPos, glm::vec3 targetPos, float yaw, float pitch, float roll) {
		glm::vec3 up = glm::vec3(.0, 0, 1.0);
		glm::vec3 vz = glm::normalize(glm::vec3(cameraPos-targetPos));
		glm::vec3 vx = glm::normalize(glm::cross(up, vz));
		glm::vec3 vy = glm::normalize(glm::cross(vz, vx));

		glm::mat4 mc = glm::mat4(vx[0], vx[1], vx[2], .0, vy[0], vy[1], vy[2], .0, vz[0], vz[1], vz[2], .0, cameraPos[0], cameraPos[1], cameraPos[2], 1.0);

		return inverse(mc*glm::rotate(glm::mat4(1.0), pitch, glm::vec3(0,1,0))
			*glm::rotate(glm::mat4(1.0), roll, glm::vec3(1,0,0))
			*glm::rotate(glm::mat4(1.0), yaw, glm::vec3(0,0,1)));

	}

	
	// Here you load and setup all your Vulkan objects
	void localInit() {
		// Descriptor Layouts [what will be passed to the shaders]
		modelDSL.init(this, {
					// this array contains the binding:
					// first  element : the binding number
					// second element : the time of element (buffer or texture)
					// third  element : the pipeline stage where it will be used
					{0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT},
					{1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, VK_SHADER_STAGE_FRAGMENT_BIT}
				  });

		globalDSL.init(this, {
					// this array contains the binding:
					// first  element : the binding number
					// second element : the time of element (buffer or texture)
					// third  element : the pipeline stage where it will be used
					{0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_ALL_GRAPHICS},
				  });

		// Pipelines [Shader couples]
		// The last array, is a vector of pointer to the layouts of the sets that will
		// be used in this pipeline. The first element will be set 0, and so on..
		P1.init(this, "shaders/vert.spv", "shaders/frag.spv", {&globalDSL, &modelDSL});

		// Models, textures and Descriptors (values assigned to the uniforms)
		truckModel.init(this, TRUCK_PATH);
		truckTexture.init(this, TRUCK_TEXTURE);

		heightMap = stbi_load((HEIGHT_MAP).c_str(), &heightMapWidth, &heightMapHeight, NULL, 1);

		// int pixX = round(fmax(0.0f, fmin(heightMapWidth-1,  (truckPose[0]) * heightMapWidth  / 66.0)));
		// int pixY = round(fmax(0.0f, fmin(heightMapHeight-1, (truckPose[1]) * heightMapHeight / 66.0)));
		// int pix = (int)heightMap[heightMapWidth * pixY + pixX];

		
		

		truckDS.init(this, &modelDSL, {
		// the second parameter, is a pointer to the Uniform Set Layout of this set
		// the last parameter is an array, with one element per binding of the set.
		// first  elmenet : the binding number
		// second element : UNIFORM or TEXTURE (an enum) depending on the type
		// third  element : only for UNIFORMs, the size of the corresponding C++ object
		// fourth element : only for TEXTUREs, the pointer to the corresponding texture object
					{0, UNIFORM, sizeof(UniformBufferObject), nullptr},
					{1, TEXTURE, 0, &truckTexture}
				});

		groundModel.init(this, GROUND_PATH);
		
		groundTexture.init(this, GROUND_TEXTURE);
		groundDS.init(this, &modelDSL, {
					{0, UNIFORM, sizeof(UniformBufferObject), nullptr},
					{1, TEXTURE, 0, &groundTexture}
				});

		globalDS.init(this, &globalDSL, {
					{0, UNIFORM, sizeof(GlobalUniformBufferObject), nullptr},
				});

		
	}

	// Here you destroy all the objects you created!		
	void localCleanup() {
		modelDSL.cleanup();
		globalDSL.cleanup();
		truckTexture.cleanup();
		groundTexture.cleanup();
		truckModel.cleanup();
		groundModel.cleanup();
		P1.cleanup();
		globalDS.cleanup();
		truckDS.cleanup();
		groundDS.cleanup();
	}
	
	// Here it is the creation of the command buffer:
	// You send to the GPU all the objects you want to draw,
	// with their buffers and textures
	void populateCommandBuffer(VkCommandBuffer commandBuffer, int currentImage) {
				
		vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
				P1.graphicsPipeline);

		vkCmdBindDescriptorSets(commandBuffer,
						VK_PIPELINE_BIND_POINT_GRAPHICS,
						P1.pipelineLayout, 0, 1, &globalDS.descriptorSets[currentImage],
						0, nullptr);
				




		VkBuffer truckVertexBuffers[] = {truckModel.vertexBuffer};
		// property .vertexBuffer of models, contains the VkBuffer handle to its vertex buffer
		VkDeviceSize truckOffsets[] = {0};
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, truckVertexBuffers, truckOffsets);
		// property .indexBuffer of models, contains the VkBuffer handle to its index buffer
		vkCmdBindIndexBuffer(commandBuffer, truckModel.indexBuffer, 0,
								VK_INDEX_TYPE_UINT32);

		// property .pipelineLayout of a pipeline contains its layout.
		// property .descriptorSets of a descriptor set contains its elements.
		vkCmdBindDescriptorSets(commandBuffer,
						VK_PIPELINE_BIND_POINT_GRAPHICS,
						P1.pipelineLayout, 1, 1, &truckDS.descriptorSets[currentImage],
						0, nullptr);
						
		// property .indices.size() of models, contains the number of triangles * 3 of the mesh.
		vkCmdDrawIndexed(commandBuffer,
					static_cast<uint32_t>(truckModel.indices.size()), 1, 0, 0, 0);





		VkBuffer groundVertexBuffers[] = {groundModel.vertexBuffer};
		// property .vertexBuffer of models, contains the VkBuffer handle to its vertex buffer
		VkDeviceSize groundOffsets[] = {0};
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, groundVertexBuffers, groundOffsets);
		// property .indexBuffer of models, contains the VkBuffer handle to its index buffer
		vkCmdBindIndexBuffer(commandBuffer, groundModel.indexBuffer, 0,
								VK_INDEX_TYPE_UINT32);

		// property .pipelineLayout of a pipeline contains its layout.
		// property .descriptorSets of a descriptor set contains its elements.
		vkCmdBindDescriptorSets(commandBuffer,
						VK_PIPELINE_BIND_POINT_GRAPHICS,
						P1.pipelineLayout, 1, 1, &groundDS.descriptorSets[currentImage],
						0, nullptr);
						
		// property .indices.size() of models, contains the number of triangles * 3 of the mesh.
		vkCmdDrawIndexed(commandBuffer,
					static_cast<uint32_t>(groundModel.indices.size()), 1, 0, 0, 0);
	}

	// Here is where you update the uniforms.
	// Very likely this will be where you will be writing the logic of your application.
	void updateUniformBuffer(uint32_t currentImage) {
		static auto startTime = std::chrono::high_resolution_clock::now();
		static float lastTime = 0.0f;
		
		auto currentTime = std::chrono::high_resolution_clock::now();
		float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
		float deltaT = time - lastTime;
		lastTime = time;


		if(glfwGetKey(window, GLFW_KEY_W)) {
			truckPose += deltaT * LINEAR_VEL * glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(truckAngle), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(1,0,0,1));

			std::cout  << "your pose: "<< truckPose[0] << " " << truckPose[1] << " " << truckPose[2] << "Angle: " << truckAngle  << " aaaa" << (int)heightMap[8000] << "width: " << heightMapWidth << " height: " << heightMapHeight <<"\n\n";
			
			int pixXFront = round(fmax(0.0f, fmin(heightMapWidth-1,  (truckPose[0]+24.0-0.35*cos(glm::radians(truckAngle))) * heightMapWidth  / 48.0)));
			int pixYFront = round(fmax(0.0f, fmin(heightMapHeight-1, (truckPose[1]+24.0-0.35*sin(glm::radians(truckAngle))) * heightMapHeight / 48.0)));

			pixFront = (int)heightMap[heightMapWidth * pixYFront + pixXFront];
			std::cout << "Terrain rear:  " << pixFront << "\n\n"; 

			int pixXRear = round(fmax(0.0f, fmin(heightMapWidth-1,  (truckPose[0]+24.0+0.35*cos(glm::radians(truckAngle))) * heightMapWidth  / 48.0)));
			int pixYRear = round(fmax(0.0f, fmin(heightMapHeight-1, (truckPose[1]+24.0+0.35*sin(glm::radians(truckAngle))) * heightMapHeight / 48.0)));

			pixRear = (int)heightMap[heightMapWidth * pixYRear + pixXRear];
			std::cout << "Terrain front: " << pixRear << "\n\n";  


		}
		if(glfwGetKey(window, GLFW_KEY_S)) {
			truckPose -= deltaT * LINEAR_VEL * glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(truckAngle), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::vec4(1,0,0,1));
			std::cout  << "your pose: "<< truckPose[0] << " " << truckPose[1] << " " << truckPose[2] << "Angle: " << truckAngle  << " aaaa" << (int)heightMap[8000] << "width: " << heightMapWidth << " height: " << heightMapHeight <<"\n\n";
			
			int pixXFront = round(fmax(0.0f, fmin(heightMapWidth-1,  (truckPose[0]+24.0-0.35*cos(glm::radians(truckAngle))) * heightMapWidth  / 48.0)));
			int pixYFront = round(fmax(0.0f, fmin(heightMapHeight-1, (truckPose[1]+24.0-0.35*sin(glm::radians(truckAngle))) * heightMapHeight / 48.0)));

			pixFront = (int)heightMap[heightMapWidth * pixYFront + pixXFront];
			std::cout << "Terrain rear:  " << pixFront << "\n\n"; 

			int pixXRear = round(fmax(0.0f, fmin(heightMapWidth-1,  (truckPose[0]+24.0+0.35*cos(glm::radians(truckAngle))) * heightMapWidth  / 48.0)));
			int pixYRear = round(fmax(0.0f, fmin(heightMapHeight-1, (truckPose[1]+24.0+0.35*sin(glm::radians(truckAngle))) * heightMapHeight / 48.0)));

			pixRear = (int)heightMap[heightMapWidth * pixYRear + pixXRear];
			std::cout << "Terrain front: " << pixRear << "\n\n"; 
		}
		if(glfwGetKey(window, GLFW_KEY_A)) {
			truckAngle += 1.0f * ANGULAR_VEL;
			cameraAngle += 1.0f * ANGULAR_VEL;
			deltaCameraPose = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(cameraAngle), glm::vec3(0,0,1)) * glm::vec4(startingDelta,1.0f));
		}
		if(glfwGetKey(window, GLFW_KEY_D)) {
			truckAngle -= 1.0f * ANGULAR_VEL;
			cameraAngle -= 1.0f * ANGULAR_VEL;
			deltaCameraPose = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(cameraAngle), glm::vec3(0,0,1)) * glm::vec4(startingDelta,1.0f));
		}
		if(glfwGetKey(window, GLFW_KEY_LEFT)) {
			cameraAngle -= 1.0f * ANGULAR_VEL;
			deltaCameraPose = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(cameraAngle), glm::vec3(0,0,1)) * glm::vec4(startingDelta,1.0f));
		}
		if(glfwGetKey(window, GLFW_KEY_RIGHT)) {
			cameraAngle += 1.0f * ANGULAR_VEL;
			deltaCameraPose = glm::vec3(glm::rotate(glm::mat4(1), glm::radians(cameraAngle), glm::vec3(0,0,1)) * glm::vec4(startingDelta,1.0f));
		}
		if(glfwGetKey(window, GLFW_KEY_UP)) {
			roll += deltaT * CAMERA_VEL;
		}
		if(glfwGetKey(window, GLFW_KEY_DOWN)) {
			roll -= deltaT * CAMERA_VEL;
		}
		// if(glfwGetKey(window, GLFW_KEY_LEFT)) {
		// 	pitch += deltaT * CAMERA_VEL;
		// }
		// if(glfwGetKey(window, GLFW_KEY_RIGHT)) {
		// 	pitch -= deltaT * CAMERA_VEL;
		// }
		if(glfwGetKey(window, GLFW_KEY_M)) {
			deltaCameraPose[2] -= deltaT * CAMERA_VEL;
			startingDelta[2] -= deltaT * CAMERA_VEL;
		}
		if(glfwGetKey(window, GLFW_KEY_N)) {
			deltaCameraPose[2] += deltaT * CAMERA_VEL;
			startingDelta[2] += deltaT * CAMERA_VEL;
		}
					
					
		UniformBufferObject ubo{};
		GlobalUniformBufferObject gubo{};

		gubo.view = LookAtMat(truckPose+deltaCameraPose,
							   truckPose,
							   yaw, pitch, roll);
		gubo.proj = glm::perspective(glm::radians(100.0f),
						swapChainExtent.width / (float) swapChainExtent.height,
						0.1f, 10.0f);
		gubo.proj[1][1] *= -1;
		
		void* data;

		// Here is where you actually update your uniforms
		// in DS1.uniformBuffersMemory[0][currentImage] -> Lo zero indica il binding
		vkMapMemory(device, globalDS.uniformBuffersMemory[0][currentImage], 0,
							sizeof(gubo), 0, &data);
		memcpy(data, &gubo, sizeof(gubo));
		vkUnmapMemory(device, globalDS.uniformBuffersMemory[0][currentImage]);

		ubo.model = 
			glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, (pixFront+pixRear)/4.0f/255.0f)) *
			glm::translate(glm::mat4(1.0f), truckPose) * 
			glm::scale(glm::mat4(1.0f), glm::vec3(0.2, 0.2, 0.2)) *
			glm::rotate(glm::mat4(1.0f), glm::radians(truckAngle+90.0f), glm::vec3(0.0f, 0.0f, 1.0f)) *
			glm::rotate(glm::mat4(1.0f), glm::atan((pixFront-pixRear)/255.0f, 0.8f), glm::vec3(1.0f, 0.0f, 0.0f));

		vkMapMemory(device, truckDS.uniformBuffersMemory[0][currentImage], 0,
							sizeof(ubo), 0, &data);
		memcpy(data, &ubo, sizeof(ubo));
		vkUnmapMemory(device, truckDS.uniformBuffersMemory[0][currentImage]);

		ubo.model = 
			// glm::translate(glm::mat4(1.0f), glm::vec3(-40.0, -40.0, -.8)) * 
			glm::scale(glm::mat4(1.0f), glm::vec3(.2, .2, .2))
			 *  glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

		vkMapMemory(device, groundDS.uniformBuffersMemory[0][currentImage], 0,
							sizeof(ubo), 0, &data);
		memcpy(data, &ubo, sizeof(ubo));

		vkUnmapMemory(device, groundDS.uniformBuffersMemory[0][currentImage]);
	}	
};

// This is the main: probably you do not need to touch this!
int main() {
    MyProject app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}