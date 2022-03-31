#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 vertexNormal_modelspace;
uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform vec3 lightPosition;
out vec3 fragmentColor;

void main(){
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
    // Light color = white
    vec3 lightColor = vec3(1, 1, 1);
    float lightPower = 30;
    // Camera space vertex normal
    vec3 vertexNormal_cameraspace = (V * M * vec4(vertexNormal_modelspace, 0)).xyz;
    // Eyeposition (camera position - vertex_cameraspace)
    vec3 vertexPosition_cameraspace = (V * M * vec4(vertexPosition_modelspace, 1.0)).xyz;
    vec3 eyeDirection_cameraspace = vec3(0, 0, 0) - vertexPosition_cameraspace;
    // light direction to vertex
    vec3 lightPosition_cameraspace = (V * vec4(lightPosition, 1.0)).xyz;
    vec3 lightDirection_cameraspace = eyeDirection_cameraspace + lightPosition_cameraspace;
    // normalize value
    vec3 n = normalize(vertexNormal_cameraspace);
    vec3 l = normalize(lightDirection_cameraspace);
    float cosTheta = clamp(dot(n, l), 0, 1);
    // Distance between vertex and light
    vec3 vertexPosition_worldspace = (M * vec4(vertexPosition_modelspace, 1)).xyz;
    float dist = length(lightPosition - vertexPosition_worldspace);
    // Ambient color
    vec3 AmbientColor = 0.1 * vertexColor;
    // Specular color
    vec3 EyeVector = normalize(eyeDirection_cameraspace);
    vec3 R = reflect(-l, n);
    float cosAlpha = clamp(dot(EyeVector, R), 0, 1);
    vec3 MaterialSpecularColor = vec3(0.5, 0.5, 0.5);
    // Output color
    fragmentColor = (vertexColor * lightPower * lightColor * cosTheta) / (dist * dist) +
                    (MaterialSpecularColor * lightPower * lightColor * pow(cosAlpha, 5) / (dist * dist))
                    + AmbientColor;
    
}