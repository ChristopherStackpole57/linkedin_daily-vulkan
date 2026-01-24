#ifdef VRENDER_HAS_GLFW

#include <stdexcept>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "GLFWWindowSurfaceProvider.h"

vrender::platform::GLFWWindowSurfaceProvider::GLFWWindowSurfaceProvider()
{
	if (!glfwInit())
	{
		throw std::runtime_error("ERROR: GLFW Failed to Initialize");
	}
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

vrender::platform::GLFWWindowSurfaceProvider::~GLFWWindowSurfaceProvider()
{
	if (glfw_window != nullptr)
	{
		glfwDestroyWindow(static_cast<GLFWwindow*>(glfw_window));
	}
	glfwTerminate();
}

std::vector<std::string> vrender::platform::GLFWWindowSurfaceProvider::get_required_instance_extensions() const
{
	uint32_t glfw_extension_count = 0;
	const char** raw_extension_pointers = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	std::vector<std::string> extensions;
	extensions.reserve(glfw_extension_count);

	for (int i = 0; i < glfw_extension_count; i++)
	{
		extensions.emplace_back(raw_extension_pointers[i]);
	}

	return extensions;
}

VkSurfaceKHR vrender::platform::GLFWWindowSurfaceProvider::create_surface(VkInstance instance) const
{
	if (glfw_window == nullptr)
	{
		GLFWwindow* window_attempt = glfwCreateWindow(1920, 1080, "GLFW Window", nullptr, nullptr);
		if (window_attempt == nullptr)
		{
			throw std::runtime_error("ERROR: GLFW Failed to Create Window");
		}

		glfw_window = static_cast<void*>(window_attempt);
	}

	VkSurfaceKHR surface;
	VkResult surface_creation_result = glfwCreateWindowSurface(
		instance,
		static_cast<GLFWwindow*>(glfw_window),
		nullptr,
		&surface
	);

	if (surface_creation_result != VK_SUCCESS)
	{
		throw std::runtime_error("ERROR: GLFW Window Failed to Create Vulkan Surface");
	}

	return surface;
}

#endif