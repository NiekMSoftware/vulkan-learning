cmake_minimum_required(VERSION 3.28)
project(vulkan-learning)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs)

find_package(Vulkan REQUIRED)

add_executable(HelloVKWindow "src/hello_vkwindow.cpp")
target_link_libraries(HelloVKWindow
	glfw
	glm::glm
	Vulkan::Vulkan
)

add_executable(Drawing-a-Triangle "src/drawing_a_triangle/main.cpp")
target_link_libraries(Drawing-a-Triangle
	glfw
	glm::glm
	Vulkan::Vulkan
)