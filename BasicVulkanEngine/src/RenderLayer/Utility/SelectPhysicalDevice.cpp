#include "SelectPhysicalDevice.h"

// Selection Utilities
bool satisfies_queue_requirements(
	const vrender::render::PhysicalDevice& device,
	const vrender::render::utility::physical_device::QueueRequirements& requirements
)
{
	for (const VkQueueFamilyProperties& family : device.get_queue_families())
	{
		if ((family.queueFlags & requirements.required) == requirements.required)
		{
			return true;
		}
	}
	return false;
}
bool satisfies_extension_requirements(
	const vrender::render::PhysicalDevice& device,
	const vrender::render::utility::physical_device::ExtensionRequirements& requirements
)
{
	const std::vector<VkExtensionProperties>& available = device.get_extensions();

	for (const std::string& required : requirements.required)
	{
		bool found = false;
		for (const VkExtensionProperties& extension : available)
		{
			if (required == extension.extensionName)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			return false;
		}
	}

	return true;
}
bool satisfies_feature_requirements(
	const vrender::render::PhysicalDevice& device,
	const vrender::render::utility::physical_device::FeatureRequirements& requirements
)
{
	return true;
}
bool satisfies_surface_requirements(
	const vrender::render::PhysicalDevice& device,
	const vrender::render::utility::physical_device::SurfaceRequirements& requirements
)
{
	return true;
}
bool satisfies_memory_requirements(
	const vrender::render::PhysicalDevice& device,
	const vrender::render::utility::physical_device::MemoryRequirements requirements
)
{
	if (!requirements.require_device_local)
	{
		return true;
	}

	return device.get_max_device_local_heap_size() >= requirements.min_device_local_bytes;
}

// Physical Device Selector
vrender::render::PhysicalDevice vrender::render::utility::physical_device::select_physical_device(
	std::vector<vrender::render::PhysicalDevice> options,
	vrender::render::utility::physical_device::PhysicalDeviceSelectionParameters selection_parameters
)
{
	const vrender::render::PhysicalDevice* last = nullptr;

	for (const vrender::render::PhysicalDevice& device : options)
	{
		// Hard Filtering
		if (!device.is_valid()) continue;
		if (!satisfies_queue_requirements(device, selection_parameters.queues)) continue;
		if (!satisfies_extension_requirements(device, selection_parameters.extensions)) continue;
		// features
		// surface
		if (!satisfies_memory_requirements(device, selection_parameters.memory)) continue;

		// Scoring
		// TODO: Add scoring

		last = &device;
	}

	// Selection Result
	return *last;
}