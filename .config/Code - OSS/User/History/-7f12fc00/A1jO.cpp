
#include <GLFW/glfw3.h>
#include <glad/glad.h> // или другой GL loader

#include <iostream>
#include <string>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API); // будем использовать OpenGL
    GLFWwindow* window = glfwCreateWindow(800, 600, "Space (GLFW)", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to init GLAD\n";
        return 1;
    }

    // включаем обработку drop-файлов
    glfwSetDropCallback(window, [](GLFWwindow* win, int count, const char** paths) {
        for (int i = 0; i < count; i++) {
            std::cout << "Dropped file: " << paths[i] << "\n";
            int w, h, n;
            unsigned char* data = stbi_load(paths[i], &w, &h, &n, 4);
            if (!data) {
                std::cerr << "Failed to load image\n";
            } else {
                std::cout << "Loaded image " << w << "x" << h << " channels=" << n << "\n";
                stbi_image_free(data);
            }
        }
    });

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // простой фон
        glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
