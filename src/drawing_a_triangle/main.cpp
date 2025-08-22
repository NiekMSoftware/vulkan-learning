#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	void initWindow() {
		glfwInit();

		// Tell GLFW to not create an OpenGL context
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		pWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	void initVulkan() {
		
	}

	void mainLoop() {
		while (!glfwWindowShouldClose(pWindow)) {
			glfwPollEvents();
		}
	}

	void cleanup() {
		glfwDestroyWindow(pWindow);

		glfwTerminate();
	}

	GLFWwindow* pWindow = nullptr;
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}