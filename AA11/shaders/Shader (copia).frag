#version 450

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	if (gubo.time <= 0.33){
		outColor = vec4(.5, .5, 0.0, 1.0f);
	}
	if (gubo.time > 0.33 && gubo.time <= 0.66){
		outColor = vec4(0.0, 1.0, 0.0, 1.0f);
	}
	if (gubo.time > 0.66){
		outColor = vec4(0.1, 0.0, .3, 1.0f);
	}
	outColor = vec4(.5*cos(gubo.time), .5, 0.0, 1.0f);
}
