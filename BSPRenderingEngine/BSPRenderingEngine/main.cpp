#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

static int WIDTH = 800;
static int HEIGHT = 600;

void OnResize(GLFWwindow* window, int width, int height)
{
	//resize the viewport
	WIDTH = width;
	HEIGHT = height;
	glViewport(0, 0, WIDTH, HEIGHT);
}

void ProcessInput(GLFWwindow* window)
{
	// if escape key is pressed , send the signal to close the window and stop
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}


int main()
{

	//Initializing GLFW and Setting OpenGL versions to use
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//creating window
	GLFWwindow* window =  glfwCreateWindow(WIDTH, HEIGHT, "BSPRenderingEngine", NULL, NULL);

	if (!window)
	{
		std::cout << "Failed to Create Window " << std::endl;
		glfwTerminate();
		return -1;
	}
	//making the current window as render context
	glfwMakeContextCurrent(window);


	//initializing GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize GLAD " << std::endl;
		return -1;
	}
	
	//creating viewport
	glViewport(0, 0, WIDTH, HEIGHT);

	//setting up callback function to call when window is resized
	glfwSetFramebufferSizeCallback(window, OnResize);

	//main rendering loop
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		glClearColor(1.0f, 0.0f,0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	//terminating and cleaning up
	glfwTerminate();

	return 0;
}