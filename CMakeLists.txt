cmake_minimum_required(VERSION 3.28)
project(vulkan-learning)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs)

find_package(Vulkan REQUIRED)

add_executable(BasicProgram src/main.cpp)
target_link_libraries(BasicProgram
	glfw
	glm::glm
	Vulkan::Vulkan
)