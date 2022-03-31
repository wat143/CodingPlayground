#version 330 core

in vec3 vertexPosition_worldspace;
in vec3 vertColor;
in vec3 vertexNormal_cameraspace;
in vec3 eyeDirection_cameraspace;
in vec3 lightDirection_cameraspace;
in vec3 lightPosition_vertex;
out vec3 color;

void main(){
    // Light color = white
    vec3 lightColor = vec3(1, 1, 1);
    float lightPower = 60;
    // Distance between vertex and light
    float dist = length(lightPosition_vertex - vertexPosition_worldspace);
    // Ambient color
    vec3 AmbientColor = 0.1 * vertColor;
    // normalize value
    vec3 n = normalize(vertexNormal_cameraspace);
    vec3 l = normalize(lightDirection_cameraspace);
    float cosTheta = clamp(dot(n, l), 0, 1);
    // Specular color
    vec3 EyeVector = normalize(eyeDirection_cameraspace);
    vec3 R = reflect(-l, n);
    float cosAlpha = clamp(dot(EyeVector, R), 0, 1);
    vec3 MaterialSpecularColor = vec3(0.5, 0.5, 0.5);
    // Output color
    color = (vertColor * lightPower * lightColor * cosTheta) / (dist * dist) +
            (MaterialSpecularColor * lightPower * lightColor * pow(cosAlpha, 5) / (dist * dist))
            + AmbientColor;
    
}