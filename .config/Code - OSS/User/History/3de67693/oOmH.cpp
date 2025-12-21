// --- other includes ---
#include <vk_types.h>
#include <vk_initializers.h>

//bootstrap library
#include "VkBootstrap.h"

    Vulkan SpecGithub RepoTutorial code 📖

    1. Initializing VulkanVulkan Initialization Code

Initializing core Vulkan structures

The explanations assume that you start from the code of chapter-0. If you don’t have the project setup, please grab the code of chapter-0 and compile it.

The first thing to do, is to #include the vkBootstrap library that we will be using to simplify the initialization code. For that, go to the top of vk_engine.cpp, and just include the "VkBootstrap.h" header

// --- other includes ---
#include <vk_types.h>
#include <vk_initializers.h>

//bootstrap library
#include "VkBootstrap.h"

VkBootstrap will remove hundreds of lines of code from our engine, simplifying the startup code by a considerable amount. If you want to learn how to do that yourself without vkbootstrap, you can try reading the first chapter of vulkan-tutorial here

The first thing we are need to initialize is the Vulkan instance. For that, let’s start by adding a new function and the stored handles to the VulkanEngine class. Lets also add some extra functions to the engine class for the different stages of initialization.

vk_engine.h

class VulkanEngine {
public:

// --- omitted ---

	VkInstance _instance;// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger;// Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;// GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands
	VkSurfaceKHR _surface;// Vulkan window surface

private:

	void init_vulkan();
	void init_swapchain();
	void init_commands();
	void init_sync_structures();

We will now call those init functions in order from our engine init function

vk_engine.cpp

constexpr bool bUseValidationLayers = false;

void VulkanEngine::init()
{
	// We initialize SDL and create a window with it. 
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
	
	_window = SDL_CreateWindow(
		"Vulkan Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		_windowExtent.width,
		_windowExtent.height,
		window_flags
	);

	init_vulkan();

	init_swapchain();

	init_commands();

	init_sync_structures();

	//everything went fine
	_isInitialized = true;
}

void VulkanEngine::init_vulkan()
{
    //nothing yet
}
void VulkanEngine::init_swapchain()
{
    //nothing yet
}
void VulkanEngine::init_commands()
{
    //nothing yet
}
void VulkanEngine::init_sync_structures()
{
    //nothing yet
}
