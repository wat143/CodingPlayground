#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 vertexNormal_modelspace;
uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform vec3 lightPosition;
out vec3 vertexPosition_worldspace;
out vec3 vertColor;
out vec3 vertexNormal_cameraspace;
out vec3 eyeDirection_cameraspace;
out vec3 lightDirection_cameraspace;
out vec3 lightPosition_vertex;

void main(){
	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

	// Vertex position in cameraspace. V * M * vertex
	vec3 vertexPosition_cameraspace = (V * M * vec4(vertexPosition_modelspace, 1.0)).xyz;

	// light direction to vertex
	vec3 lightPosition_cameraspace = (V * vec4(lightPosition, 1.0)).xyz;

	// Varing variables
	vertexPosition_worldspace = (M * vec4(vertexPosition_modelspace, 1)).xyz;
	vertColor = vertexColor;
	vertexNormal_cameraspace = (V * M * vec4(vertexNormal_modelspace, 0)).xyz;
	eyeDirection_cameraspace = vec3(0, 0, 0) - vertexPosition_cameraspace;
	lightDirection_cameraspace = eyeDirection_cameraspace + lightPosition_cameraspace;
	lightPosition_vertex = lightPosition;
}