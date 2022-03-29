#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <GL/glew.h>

#include <glfw3.h>


#include <glm/glm.hpp>
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

int main( void )
{
	GLfloat vertex[][3] = {{-1.0f, -1.0f, 0.0f},
							{1.0f, -1.0f, 0.0f},
							{0.0f, 1.0f, 0.0f}};
	GLfloat color[][3] = {{1.0f, 0.0f, 0.0f},
						{0.0f, 1.0f, 0.0f},
						{0.0f, 0.0f, 1.0f}};
	GLuint buff[2], program;
	map<GLchar*, GLuint> attr;
	GLchar *vert_modelspace = "vertexPosition_modelspace", *vertColor = "vertexColor";
	GLFWwindow* window = initGLFW_Window(1024, 768, "Playground");
	if (window == nullptr)
		return -1;
	if(!initGLEW(window))
		return -1;

	// Generate VBOs and bind
	glGenBuffers(2, buff);
	glBindBuffer(GL_ARRAY_BUFFER, buff[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buff[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

	// Load shaders
	program = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	attr[vert_modelspace] = glGetAttribLocation(program, vert_modelspace);
	attr[vertColor] = glGetAttribLocation(program, vertColor);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable shader
	glUseProgram(program);
    // Enable depth test
	glEnable(GL_DEPTH_TEST);
	do{
		// Clear previous screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Draw nothing, see you in tutorial 2 !
		glEnableVertexAttribArray(attr[vert_modelspace]);
		glBindBuffer(GL_ARRAY_BUFFER, buff[0]);
		glVertexAttribPointer(attr[vert_modelspace], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(attr[vertColor]);
		glBindBuffer(GL_ARRAY_BUFFER, buff[1]);
		glVertexAttribPointer(attr[vertColor], 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		// Draw triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
        // Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

