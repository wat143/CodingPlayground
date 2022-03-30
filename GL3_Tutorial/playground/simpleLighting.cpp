#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <unistd.h>
#include <GL/glew.h>

#include <glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "common/shader.hpp"
using namespace glm;
using namespace std;

GLFWwindow* initGLFW_Window(int width, int height, char *window_name) {
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return nullptr;
	}

    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(width, height, window_name, NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	return window;
}

bool initGLEW(GLFWwindow *window) {
	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	return true;
}

void CalcFaceNormal(vec3 *norm, GLfloat v[][3], int numFace) {
    for (int i = 0, j = 0; i < numFace * 3; i+=3, j++) {
        vec3 a = vec3(v[i+1][0] - v[i][0], v[i+1][1] - v[i][1], v[i+1][2] - v[i][2]);
        vec3 b = vec3(v[i+2][0] - v[i][0], v[i+2][1] - v[i][1], v[i+2][2] - v[i][2]);
        vec3 normal = normalize(cross(a, b));
        cout << normal[0] << ", " << normal[1] << ", " << normal[2] << endl;
        norm[j] = normal;
    }
}

int main( void )
{
    int numFace = 4;
    vec3 faceNorm[numFace];
	GLuint cnt = 0;
    GLfloat vertex[][3] = {{0.0f, 1.0f, 0.0f},
                            {-1.0f, -1.0f, 1.0f},
							{1.0f, -1.0f, 1.0f},
                            {0.0f, 1.0f, 0.0f},
                            {1.0f, -1.0f, 1.0f},
							{1.0f, -1.0f, -1.0f},
                            {0.0f, 1.0f, 0.0f},
                            {1.0f, -1.0f, -1.0f},
                            {-1.0f, -1.0f, -1.0f},
                            {0.0f, 1.0f, 0.0f},
                            {-1.0f, -1.0f, -1.0f},
                            {-1.0f, -1.0f, 1.0f}};

	GLfloat color[][3] = {{1.0f, 0.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
                        {1.0f, 0.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f},
                        {1.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
                        {1.0f, 0.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f}};
    GLfloat vertexNormal[3 * numFace][3];
    GLfloat lightPosition[3] = {4, 4, 4};
    GLuint buff[2], program, umvp, uv, um, lightPos;
    map<GLchar*, GLuint> attr;
	GLchar *vert_modelspace = "vertexPosition_modelspace", *vertColor = "vertexColor",
            *vert_normal = "vertexNormal_modelspace";
	GLFWwindow* window = initGLFW_Window(1024, 768, "SimpleLighting");
	if (window == nullptr)
		return -1;
	if(!initGLEW(window))
		return -1;

    // Calculate normal
    CalcFaceNormal(faceNorm, vertex, numFace);
    vec3 all = normalize((faceNorm[0] + faceNorm[1] + faceNorm[2] + faceNorm[3]) / 4.0f);
    for (int i = 0, j = 0; i < 3 * numFace; i+=3, j++) {
        // Top of pyramid touches all faces
        vertexNormal[i][0] = all[0];
        vertexNormal[i][1] = all[1];
        vertexNormal[i][2] = all[2];
        // left and right bottom verties
        vec3 leftBottom = normalize((faceNorm[(j + 3) % numFace] + faceNorm[j % numFace]) / 2.0f);
        vertexNormal[i + 1][0] = leftBottom[0];
        vertexNormal[i + 1][1] = leftBottom[1];
        vertexNormal[i + 1][2] = leftBottom[2];
        vec3 rightBottom = normalize((faceNorm[j % numFace] + faceNorm[(j + 1) % numFace]) / 2.0f);
        vertexNormal[i + 2][0] = rightBottom[0];
        vertexNormal[i + 2][1] = rightBottom[1];
        vertexNormal[i + 2][2] = rightBottom[2];
    }
    for (int i = 0; i < 12; i++) cout << "(" << vertexNormal[i][0] << ", " << vertexNormal[i][1] << ", " << vertexNormal[i][2] << ")" << endl;
	// Generate VBOs and bind
	glGenBuffers(3, buff);
	glBindBuffer(GL_ARRAY_BUFFER, buff[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buff[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buff[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexNormal), vertexNormal, GL_STATIC_DRAW);

	// Load shaders and get attributes, uniform
	program = LoadShaders("LightingVertexShader.vs", "SimpleFragmentShader.fs");
	attr[vert_modelspace] = glGetAttribLocation(program, vert_modelspace);
	attr[vertColor] = glGetAttribLocation(program, vertColor);
    attr[vert_normal] = glGetAttribLocation(program, vert_normal);
	umvp = glGetUniformLocation(program, "MVP");
    um = glGetUniformLocation(program, "M");
    uv = glGetUniformLocation(program, "V");
    lightPos = glGetUniformLocation(program, "lightPosition");

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable shader
	glUseProgram(program);
    // Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Enable culling
    //glEnable(GL_CULL_FACE);
    do{
		cnt++;
		// Clear previous screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Calculate model matrix
		GLfloat rad = (cnt % 360) * M_PI / 180;
		mat4 m = rotate(mat4(1.0), rad, vec3(0, 1, 0));
		mat4 v = lookAt(vec3(-5, 0, 5), vec3(0, 0, 0), vec3(0, 1, 0));
		mat4 p = perspective(radians(45.0f), 4.0f/3.0f, 0.1f, 100.0f);
		mat4 mvp = p * v * m;
		// Apply mvp, m and v matrix to uniform location
		glUniformMatrix4fv(umvp, 1, GL_FALSE, &mvp[0][0]);
        glUniformMatrix4fv(um, 1, GL_FALSE, &m[0][0]);
        glUniformMatrix4fv(uv, 1, GL_FALSE, &v[0][0]);
		glUniform3f(lightPos, lightPosition[0], lightPosition[1], lightPosition[2]);
        // Draw nothing, see you in tutorial 2 !
		glEnableVertexAttribArray(attr[vert_modelspace]);
		glBindBuffer(GL_ARRAY_BUFFER, buff[0]);
		glVertexAttribPointer(attr[vert_modelspace], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(attr[vertColor]);
		glBindBuffer(GL_ARRAY_BUFFER, buff[1]);
		glVertexAttribPointer(attr[vertColor], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(attr[vert_normal]);
		glBindBuffer(GL_ARRAY_BUFFER, buff[2]);
		glVertexAttribPointer(attr[vert_normal], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		// Draw triangle
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
        // Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
		// Wait 8.3msec for 120fps
		usleep(8330);

    } // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

