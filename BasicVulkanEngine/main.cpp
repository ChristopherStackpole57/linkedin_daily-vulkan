#include <iostream>

#include "Configuration/VulkanConfig.h"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "Source/RenderLayer/Instance.h"
#include "Source/RenderLayer/InstanceConfiguration.h"

#ifdef NDEBUG
const bool ENABLE_VALIDATION_LAYERS = false;
#else
const bool ENABLE_VALIDATION_LAYERS = true;
#endif

int main()
{
	vrender::render::InstanceConfig config{
		.enable_validation = ENABLE_VALIDATION_LAYERS
	};
	config.extensions = std::vector<std::string>{
		"VK_KHR_surface",
		"VK_KHR_win32_surface"
	};
	vrender::render::Instance instance(config);

	return 0;
}