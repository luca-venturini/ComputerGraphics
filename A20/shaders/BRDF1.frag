#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
    vec3 lightPos;
	vec3 lightColor;
    vec4 lightParams;
	vec3 eyePos;
} gubo;



void main() {
	vec3 N = normalize(fragNorm);
    vec3  specColor = vec3(1.0f, 1.0f, 1.0f);
    vec4 color = texture(texSampler, fragTexCoord);
    vec3  diffColor = color.rgb;
    float specularPower = 200.0f * color.a;

    vec3 lightColorSpot = gubo.lightColor * clamp( (dot(normalize(gubo.lightPos - fragPos), gubo.lightDir ) - gubo.lightParams.y)/(gubo.lightParams.x - gubo.lightParams.y), 0.0f, 1.0f);

    vec3 diffuse  =  lightColorSpot * diffColor * clamp(dot(N,normalize(gubo.lightPos - fragPos)), 0.0f, 1.0f);

    vec3 refl = -reflect(normalize(gubo.lightPos - fragPos), N);
    vec3 phong = lightColorSpot * specColor * pow (clamp(dot(refl, normalize(gubo.eyePos - fragPos)), 0.0f, 1.0f), specularPower);
 	
	outColor = vec4(clamp(diffuse + phong, 0.0, 1.0), 1.0);
}