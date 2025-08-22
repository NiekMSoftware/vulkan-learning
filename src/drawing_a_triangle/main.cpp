#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
public:
	void run() {
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	void initVulkan() {
		
	}

	void mainLoop() {
		
	}

	void cleanup() {
		
	}
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