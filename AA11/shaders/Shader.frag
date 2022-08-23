#version 450

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	vec3 a = vec3(0.8, 0.5, 0.4);
	vec3 b = vec3(0.2, 0.4, 0.2);
	vec3 c = vec3(2.0, 1.0, 1.0);
	vec3 d = vec3(0.00, 0.25, 0.25);
	outColor = vec4(a + b*cos( 6.28318*(c*gubo.time+d)), 1.0 );
}
