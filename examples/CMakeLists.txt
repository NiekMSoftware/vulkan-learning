find_package(Vulkan REQUIRED)

add_executable(HelloVulkanWindow hello_vulkan_window/main.cpp)
target_link_libraries(HelloVulkanWindow
	glfw
	glm::glm
	Vulkan::Vulkan
)

add_executable(Drawing-a-Triangle drawing_a_triangle/main.cpp)
target_link_libraries(Drawing-a-Triangle
	glfw
	glm::glm
	Vulkan::Vulkan
)