#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}

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

    VkInstance instance;
    VkSurfaceKHR surface = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT debugMessenger;

    void initWindow() {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        }

        if (!SDL_CreateWindowAndRenderer("Hello SDL", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        }
    }

    void initVulkan() {
        createInstance();
        setupDebugMessenger();
    }

    void mainLoop() {
        SDL_Event event;
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
        if (enableValidationLayers) {
            DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
        }
        vkDestroySurfaceKHR(instance, surface, NULL);
        vkDestroyInstance(instance, NULL);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
    }

    void createInstance() {
        if (enableValidationLayers && !checkValidationLayerSupport()) {
            throw std::runtime_error("validation layers requested, but not available!");
        }

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        auto extensions = getRequiredExtensions();
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        createInfo.ppEnabledExtensionNames = extensions.data();

        Uint32 count_instance_extensions;
        const char * const *instance_extensions = SDL_Vulkan_GetInstanceExtensions(&count_instance_extensions);

        int count_extensions = count_instance_extensions + 1;
        std::cout << "count_extensions: " << count_extensions << std::endl;
        const char **extensions = (const char**)SDL_malloc(count_extensions * sizeof(const char *));
        extensions[0] = VK_EXT_DEBUG_REPORT_EXTENSION_NAME;
        SDL_memcpy(&extensions[1], instance_extensions, count_instance_extensions * sizeof(const char*)); 

        VkResult result = vkCreateInstance(&create_info, NULL, &instance);
        SDL_free(extensions);

        SDL_Vulkan_CreateSurface(window, instance, NULL, &surface);
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
