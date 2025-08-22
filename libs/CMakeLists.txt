message(STATUS "Processing libs/CMakeLists.txt")

# GLFW
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
add_subdirectory(glfw)

# glm
add_library(glm_interface INTERFACE)
add_library(glm::glm ALIAS glm_interface)
target_include_directories(glm_interface INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/glm
)