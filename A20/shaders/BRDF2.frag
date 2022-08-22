#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightColor;
	vec3 eyePos;
} gubo;



void main() {
	vec3 N = normalize(fragNorm);


    vec3  specColor = vec3(1.0f, 1.0f, 1.0f);
    vec4 color = texture(texSampler, fragTexCoord);
    vec3  diffColor = color.rgb;
    float specularPower = 200.0f * color.a;

    vec3 ambient = gubo.lightColor * diffColor;

    vec3 H = normalize(gubo.lightDir + normalize(gubo.eyePos - fragPos));

    vec3 blinn = specColor * pow(clamp(dot(N, H), 0.0f, 1.0f), specularPower); 


	outColor = vec4(clamp(gubo.lightColor * blinn, 0.0, 1.0) + ambient, 1.0);
}