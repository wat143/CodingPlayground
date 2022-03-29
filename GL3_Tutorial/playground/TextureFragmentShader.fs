#version 330 core

in vec2 V_UV;
uniform sampler2D myTextureSampler;
// Ouput data
out vec3 color;

void main()
{

	color = texture(myTextureSampler, V_UV).rgb;

}