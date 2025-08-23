# Picking a physical device
In Vulkan, a physical device represents a GPU that can be used for rendering and computation. 
When a developer create a Vulkan instance, they can query the available physical devices on the system and select one that meets their application's requirements.

To pick a physical device, you would typically follow these steps:
```cpp
// 1. Create a Vulkan instance
VkInstance instance;
VkInstanceCreateInfo createInfo = {};
createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
vkCreateInstance(&createInfo, nullptr, &instance);

// 2. Enumerate physical devices
uint32_t deviceCount = 0;
vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
std::vector<VkPhysicalDevice> devices(deviceCount);
vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

// 3. Select a suitable physical device
VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
for (const auto& device : devices) {
	VkPhysicalDeviceProperties deviceProperties;
	vkGetPhysicalDeviceProperties(device, &deviceProperties);
	// Check if the device meets your requirements (e.g., supports required features)
	if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
		physicalDevice = device;
		break;
	}
}

if (physicalDevice == VK_NULL_HANDLE) {
	throw std::runtime_error("Failed to find a suitable GPU!");
}

// 4. Use the selected physical device for further operations
// ...

// Clean up
vkDestroyInstance(instance, nullptr);
```

There is also another way to select a physical device by using a scoring system to evaluate each device based on various criteria, such as performance, features, and memory capacity.
This approach allows you to choose the best available device for your application's specific needs.  

Here's an example of how a developer might implement a scoring system to pick a physical device:
```cpp
int rateDeviceSuitability(VkPhysicalDevice device) {
	int score = 0;

	VkPhysicalDeviceProperties deviceProperties;
	vkGetPhysicalDeviceProperties(device, &deviceProperties);
	VkPhysicalDeviceFeatures deviceFeatures;
	vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

	// Prefer discrete GPUs
	if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
		score += 1000;
	}

	// Add points for maximum image dimension
	score += deviceProperties.limits.maxImageDimension2D;

	// Check for required features (e.g., geometry shader)
	if (!deviceFeatures.geometryShader) {
		return 0; // Disqualify if geometry shader is not supported
	}

	return score;
}

VkPhysicalDevice pickBestPhysicalDevice(VkInstance instance) {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	int bestScore = -1;
	VkPhysicalDevice bestDevice = VK_NULL_HANDLE;
	for (const auto& device : devices) {
		int score = rateDeviceSuitability(device);
		if (score > bestScore) {
			bestScore = score;
			bestDevice = device;
		}
	}
	if (bestDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("Failed to find a suitable GPU!");
	}
	return bestDevice;
}
```

This code defines a `rateDeviceSuitability` function that assigns a score to each physical device based on its properties and features.
The `pickBestPhysicalDevice` function then uses this scoring system to select the best available device.

By implementing a scoring system, a developer can ensure that their application selects the most appropriate physical device for its needs, leading to better performance and user experience.

## Sources
- [Vulkan Tutorial - Picking a Physical Device](https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Physical_devices_and_queue_families)
- [Vulkan Specification - Physical Devices](https://registry.khronos.org/vulkan/specs/latest/html/vkspec.html#devsandqueues-physical-device-enumeration)