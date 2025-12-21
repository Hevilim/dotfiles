#include <bgfx/bgfx.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main(int argc, char const *argv[])
{
    std::cout << "Initializing GLFW\n";
    glfwInit();

    std::cout << "Creating window\n";
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);

    std::cout << "Initializing bgfx\n";
    bgfx::init();

    std::cout << "Exiting" << std::endl;
    return 0;
}