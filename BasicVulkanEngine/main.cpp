#include <iostream>

#include "Configuration/VulkanConfig.h"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "Source/RenderLayer/Instance.h"
#include "Source/RenderLayer/InstanceConfiguration.h"

int main()
{
	std::cout << "Hello, LinkedIn" << std::endl;

	vrender::render::InstanceConfig config;
	config.extensions = std::vector<std::string>{
	
	};
	vrender::render::Instance instance(config);

	return 0;
}