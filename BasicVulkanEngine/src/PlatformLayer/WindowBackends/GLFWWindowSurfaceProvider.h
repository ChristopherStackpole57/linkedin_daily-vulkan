#ifndef PLATFORM_WBACK_GLFW_WINDOW_SURFACE_PROVIDER
#define PLATFORM_WBACK_GLFW_WINDOW_SURFACE_PROVIDER

#include "WindowSurfaceProvider.h"

namespace vrender
{
	namespace platform
	{
		class GLFWWindowSurfaceProvider : public vrender::platform::WindowSurfaceProvider
		{
		public:
			GLFWWindowSurfaceProvider();
			~GLFWWindowSurfaceProvider();

			std::vector<std::string> get_required_instance_extensions() const override;
			VkSurfaceKHR create_surface(VkInstance instance) const override;

		private:
			mutable void* glfw_window = nullptr;
		};
	};
};

#endif