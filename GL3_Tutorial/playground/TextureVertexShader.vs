#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 UV;
uniform mat4 MVP;
out vec2 V_UV;

void main(){

    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
    V_UV = UV;

}