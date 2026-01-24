#ifdef _WIN32

#include "WIN32WindowSurfaceProvider.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vulkan/vulkan_win32.h>

std::vector<std::string> vrender::platform::WIN32WindowSurfaceProvider::get_required_instance_extensions() const
{
	return std::vector<std::string>{};
}

VkSurfaceKHR vrender::platform::WIN32WindowSurfaceProvider::create_surface(VkInstance intance) const
{

	return NULL;
}

#endif