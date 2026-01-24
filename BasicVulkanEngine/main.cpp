#include <iostream>

#include "Configuration/VulkanConfig.h"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "src/PlatformLayer/WindowBackends/GLFWWindowSurfaceProvider.h"

#include "src/RenderLayer/Instance.h"
#include "src/RenderLayer/InstanceConfiguration.h"

#ifdef NDEBUG
const bool ENABLE_VALIDATION_LAYERS = false;
#else
const bool ENABLE_VALIDATION_LAYERS = true;
#endif

int main()
{
	std::shared_ptr<vrender::platform::WindowSurfaceProvider> surface_provider_ptr = std::make_shared<vrender::platform::GLFWWindowSurfaceProvider>();
	vrender::render::InstanceConfig config{
		.enable_validation = ENABLE_VALIDATION_LAYERS,
		.surface_provider = surface_provider_ptr
	};
	config.extensions = std::vector<std::string>{
		"VK_KHR_surface",
		"VK_KHR_win32_surface"
	};
	vrender::render::Instance instance(config);

	return 0;
}