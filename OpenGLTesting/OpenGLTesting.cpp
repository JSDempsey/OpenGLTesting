// OpenGLTesting.cpp : Defines the entry point for the application.
//

#include "OpenGLTesting.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // update the opengl viewport with the new width and height
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
	cout << "Hello CMake." << endl;

    unsigned int defaultWidth = 800;
    unsigned int defaultHeight = 600;

    // glfw setup, set opengl version to 3.3
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create the initial window (empty by default, not even an opengl context yet)
    GLFWwindow* window = glfwCreateWindow(defaultWidth, defaultHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // make sure the window is the main context on the current thread
    glfwMakeContextCurrent(window);

    // make sure glad loads so we can use the opengl extensions easily
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // create the opengl context with the same size as the glfw window
    glViewport(0, 0, defaultWidth, defaultHeight);

    // set the callback for the glfw window being resized
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // main render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clean up glfw's resources
    glfwTerminate();
    return 0;
}
