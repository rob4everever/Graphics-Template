/*
- Window.cpp
-
- Author: 100086865
-
- Entry point for the project. Creates a window, initialises the
- game and keeps it updated in the game loop. Keyboard input
- is also captured and appropiately handled here.
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Window.hpp"
#include "ResourceLoader.hpp"

//Screen dimensions
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

	//GLFW configuration
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFW window
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//Print current version of OpenGL
	printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

	//DeltaTime variables
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	//Game loop
	while (!glfwWindowShouldClose(window)) {

		//Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		
		//Process Input
		//game.processInput(deltaTime);

		//Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Swap buffers
		glfwSwapBuffers(window);

		//Vsync
		glfwSwapInterval(1);
		
	}

	//Deallocate resources
	ResourceLoader::clear();
	
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	//ESC: closes the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	/*
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			game.keys[key] = GL_TRUE;
		}
		else if (action == GLFW_RELEASE) {
			game.keys[key] = GL_FALSE;
			game.keysProcessed[key] = GL_FALSE;
		}
	}*/
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}