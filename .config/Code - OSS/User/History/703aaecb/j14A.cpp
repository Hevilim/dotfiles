#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    void initWindow() {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        }

        if (!SDL_CreateWindowAndRenderer("Hello SDL", 320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        }
    }

    void initVulkan() {
        Uint32 count_instance_extensions;
        const char * const *instance_extensions = SDL_Vulkan_GetInstanceExtensions(&count_instance_extensions);

        int count_extensions = count_instance_extensions + 1;
        std::cout << "count_extensions: " << count_extensions << std::endl;
        const char **extensions = (const char**)SDL_malloc(count_extensions * sizeof(const char *));
        extensions[0] = VK_EXT_DEBUG_REPORT_EXTENSION_NAME;
        SDL_memcpy(&extensions[1], instance_extensions, count_instance_extensions * sizeof(const char*)); 

        VkInstanceCreateInfo create_info = {};
        create_info.enabledExtensionCount = count_extensions;
        create_info.ppEnabledExtensionNames = extensions;

        VkInstance instance;
        VkResult result = vkCreateInstance(&create_info, NULL, &instance);
        SDL_free(extensions);

        VkSurfaceKHR surface;
        SDL_Vulkan_CreateSurface(window, instance, NULL, &surface);
    }

    void mainLoop() {
        while (1) {
            SDL_PollEvent(&event);
            if (event.type == SDL_EVENT_QUIT) {
                break;
            }
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    void cleanup() {
        vkDestroySurfaceKHR(instance, surface, NULL);
        vkDestroyInstance(instance, NULL);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }
};


int main(int argc, char *argv[]) {
        HelloTriangleApplication app;

        try {
            app.run();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }

    return EXIT_SUCCESS;
}
