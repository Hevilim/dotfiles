class VulkanEngine {
public:
	// --- other code ---

	VkSwapchainKHR _swapchain;
	VkFormat _swapchainImageFormat;

	std::vector<VkImage> _swapchainImages;
	std::vector<VkImageView> _swapchainImageViews;
	VkExtent2D _swapchainExtent;

private: 
	void create_swapchain(uint32_t width, uint32_t height);
	void destroy_swapchain();
}
