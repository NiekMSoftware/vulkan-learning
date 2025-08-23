# Queue Family Indices | Vulkan
> Written by Niek Melet, notes improved by Github Copilot for clarity  
Date: 8/23/2025

In Vulkan, a queue family is a group of one or more queues that have the same capabilities.
Each queue family is identified by an index, which is used to specify which queue family to use when creating a command buffer or submitting commands to the GPU.

A queue family index is an integer value that represents the index of a queue family in the list of available queue families for a physical device. 
The index is used to identify which queue family to use when creating a command buffer or submitting commands to the GPU.

When creating a Vulkan application, you need to query the available queue families for the physical device you are using. 
You can do this by calling the `vkGetPhysicalDeviceQueueFamilyProperties` function,
which returns an array of `VkQueueFamilyProperties` structures that describe the properties of each queue family.

Each `VkQueueFamilyProperties` structure contains information about the capabilities of the queue family,
such as the number of queues in the family, the types of operations that can be performed on the queues,
and whether the queues support presentation to a surface.

## Sources
- [Vulkan Specification - Queue Family Properties](https://registry.khronos.org/vulkan/specs/latest/html/vkspec.html#devsandqueues-queues)
- [Vulkan Tutorial - Queue families](https://vulkan-tutorial.com/en/Drawing_a_triangle/Setup/Logical_device_and_queues)