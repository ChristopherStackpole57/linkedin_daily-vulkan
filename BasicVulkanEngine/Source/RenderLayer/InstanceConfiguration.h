#ifndef RENDER_INSTANCE_CONFIGURATION_H
#define RENDER_INSTANCE_CONFIGURATION_H

#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace vrender
{
	namespace render
	{
		struct InstanceConfig
		{
			// Configuration for Create Info
			std::vector<std::string> extensions;

			// Configuration for Application Info
			std::string application_name = "VulkanRendering";
			uint32_t application_version = VK_MAKE_VERSION(1, 0, 0);
			std::string engine_name = "BasicVulkanEngine";
			uint32_t engine_version = VK_MAKE_VERSION(1, 0, 0);
			uint32_t api_version = VK_API_VERSION_1_2;
		};
	};
};

#endif