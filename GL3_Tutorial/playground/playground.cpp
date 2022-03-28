#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <glfw3.h>


#include <glm/glm.hpp>
using namespace glm;

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
	GLFWwindow* window = initGLFW_Window(1024, 768, "Playground");
	if (window == nullptr)
		return -1;
	if(!initGLEW(window))
		return -1;

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    do{
		// Draw nothing, see you in tutorial 2 !

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

