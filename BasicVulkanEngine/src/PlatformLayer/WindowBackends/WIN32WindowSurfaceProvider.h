#ifndef PLATFORM_WBACK_WIN32_WINDOW_SURFACE_PROVIDER
#define PLATFORM_WBACK_WIN32_WINDOW_SURFACE_PROVIDER

#include "WindowSurfaceProvider.h"

namespace vrender
{
	namespace platform
	{
		class WIN32WindowSurfaceProvider : public vrender::platform::WindowSurfaceProvider
		{
			std::vector<std::string> get_required_instance_extensions() const override;
			VkSurfaceKHR create_surface(VkInstance instance) const override;
		};
	};
};

#endif