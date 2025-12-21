// --- other includes ---
#include <vk_types.h>
#include <vk_initializers.h>

//bootstrap library
#include "VkBootstrap.h"

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
