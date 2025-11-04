#include "Input.h"
#include <GLFW/glfw3.h>
#include "Camera.h"

void Input::KeyCallback(GLFWwindow* window) {
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, true);
		});
}

void Input::MouseCallback(GLFWwindow* window, Camera* camera ) {
	glfwSetWindowUserPointer(window, camera);
	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
		Camera* cam = static_cast<Camera*>(glfwGetWindowUserPointer(window));
		cam->CameraMouseCallback(xpos, ypos);
		});
}

void Input::HandleKeyboardInput() {
    
}

