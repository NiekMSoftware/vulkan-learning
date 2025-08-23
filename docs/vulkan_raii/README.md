# Vulkan RAII Design Patterns - Study Notes
## Overview
I will quickly introduce myself first.

My name is Niek, I am a bachelor student studying game engines and graphics programming at Breda's University of Applied Sciences.
I have a keen interest in C++ and Vulkan, and I am currently exploring best practices for resource management in Vulkan applications.

---

Now onto the topic at hand:

RAII (Resource Acquisition Is Initialization) is a fundamental C++ idiom for managing resources safely.
This document will try to cover different approaches to applying RAII principles to Vulkan API code, 
comparing custom RAII classes vs smart pointers.

That being said, I am not an expert in Vulkan or C++. 
I am actively studying these topics and trying to deepen my understanding,
therefore, these notes are based understanding of the topic.

## Key RAII Principles
1. **Resource Acquisition Is Initialization** - Resources are acquired in constructors and released in destructors.
2. **Automatic Cleanup** - Destructors handle all resource cleanup automatically, preventing leaks.
3. **Exception Safety** - Partially constructed objects are properly cleaned up.
4. **Deterministic Cleanup** - Resources are freed when objects go out of scope.

## RAII vs Smart Pointers Relationship
**Important Note**: To my understanding, smart pointers (like `std::unique_ptr` and `std::shared_ptr`) are a form of RAII.
But they are not the only way to implement RAII principles.  
Custom RAII classes can provide more control and flexibility for complex resources like Vulkan objects.

## Smart Pointers vs RAII
I will try to compare the two approaches based on various criteria.

| Criteria               | Smart Pointers                          | Custom RAII Classes                   |
|------------------------|-----------------------------------------|---------------------------------------|
| Type Safety            | Type-safe, but limited to pointer types | Fully type-safe for any resource type |
| Performance            | Slight overhead due to indirection      | Minimal overhead, direct resource management |
| Ease of Use            | Easy to use for simple cases            | More boilerplate, but flexible        |
| Move Semantics         | Supported via `std::move`               | Can implement custom move semantics   |
| Code readability       | Clear for simple ownership models       | Can be more verbose, but explicit     |
| Flexibility            | Limited to pointer semantics            | Full control over resource lifecycle  |
| STL Compatibility      | Fully compatible with STL containers    | Requires custom wrappers for STL use  |
| Error Handling         | Limited, relies on exceptions           | Can implement custom error handling   |
| Memory Overhead        | Extra memory for control blocks         | Minimal, only resource size           |
| Learning Curve         | Easier for beginners                    | Steeper learning curve, need to understand RAII |
| Debugging              | Easier with standard tools              | Custom debugging needed               |
| Testability            | Easy to mock different deleters         | May need virtual interfaces for testing |
| Code Maintenance	     | Easier with standard tools              | Custom maintenance needed             |

### Key Takeaways
Choosing between smart pointers and custom RAII classes depends on the specific use case:
- For simple ownership models, smart pointers are often sufficient and easier to use.
- For complex resources like Vulkan objects, custom RAII classes provide more control and flexibility.
- Consider the trade-offs in performance, readability, and maintainability when making a decision.

## Example Code Comparison
Here is a simple example by approached smart pointers:
```cpp
auto device = std::unique_ptr<VkDevice_T, VulkanDeviceDeleter>(rawDevice);
vkGetDeviceQueue(device.get(), queueFamily, 0, &queue);  // need .get()
```
And here is the same example using a custom RAII class:
```cpp
LogicalDevice device(physicalDevice, enableValidation);
vkGetDeviceQueue(device, queueFamily, 0, &queue);  // no .get() needed
```

There is however, a third approach that combines both:
```cpp
class VulkanDevice {
private:
	std::unique_ptr<VkDevice_T, VulkanDeviceDeleter> device;

public:
	// Clean public interface
	VkDevice get() const { return device.get(); }
	operator VkDevice() const { return device.get(); }  // Implicit conversion

	// Internal implementation uses smart pointers for safety
}
```
This hybrid approach leverages the safety of smart pointers while providing a clean RAII interface.

## Conclusion
Now that we've explored the differences between smart pointers and custom RAII classes for managing Vulkan resources,
the choice ultimately depends on the specific needs of your application.

---
*Once again, this document is a personal study note and may contain inaccuracies. Always refer to official documentation and expert resources for critical implementations.
If you find any mistakes or have suggestions, please feel free to reach out!*

*Last updated: 23/8/2025*  
*Topic: C++ RAII Patterns for Vulkan API*