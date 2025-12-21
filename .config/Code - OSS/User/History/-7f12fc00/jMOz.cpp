#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Указываем, что хотим Vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Создаем окно
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Vulkan Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Цикл событий
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // Очистка
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
