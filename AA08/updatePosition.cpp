glm::mat4 MakeWorldEuler(glm::vec3 pos, float yaw, float pitch, float roll) {
	glm::mat4 out = glm::translate(glm::mat4(1.0), pos)*
					glm::rotate(glm::mat4(1.0), glm::radians(yaw), glm::vec3(0,1,0))*
					glm::rotate(glm::mat4(1.0), glm::radians(pitch), glm::vec3(1,0,0))*
					glm::rotate(glm::mat4(1.0), glm::radians(roll), glm::vec3(0,0,1));
	return out;
}

glm::mat4 getRotation(glm::vec3 *pos, float yaw, float pitch, float roll, float mu, float dt, float mx, float my, float mz){

    glm::vec3 ux = glm::vec3(1,0,0);
    glm::vec3 uy = glm::vec3(0,1,0);
    glm::vec3 uz = glm::vec3(0,0,1);
	*pos += ux * mu * dt * mx;
    *pos += uy * mu * dt * my;
    *pos += uz * mu * dt * mz;
	return MakeWorldEuler(*pos, yaw, pitch, roll);
}

// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = .0f;

	
	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period> (currentTime - startTime).count();
	float dt = time - lastTime;

	lastTime = time;
	static float yaw = .0, pitch = .0, roll = .0;
	static glm::vec3 pos = glm::vec3(-3,0,2);

	float mu = 0.9;
	glm::mat4 out;

	if(glfwGetKey(window, GLFW_KEY_D)){
		yaw = 0.0;
		out = getRotation(&pos, yaw, pitch, roll, mu, dt, 1, 0, 0);
	}
	else if(glfwGetKey(window, GLFW_KEY_W)){
		yaw = 90.0;
		out = getRotation(&pos, yaw, pitch, roll, mu, dt, 0, 0, -1);
	}
	else if(glfwGetKey(window, GLFW_KEY_A)){
		yaw = 180.0;
		out = getRotation(&pos, yaw, pitch, roll, mu, dt, -1, 0, 0);
	}
	else if(glfwGetKey(window, GLFW_KEY_S)){
		yaw = 270.0;
		out = getRotation(&pos, yaw, pitch, roll, mu, dt, 0, 0, 1);
	}
	else{
		out = MakeWorldEuler(pos, yaw, pitch, roll);
	}
	return out;
}

