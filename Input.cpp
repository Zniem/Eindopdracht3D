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

void Input::HandleKeyboardInput(GLFWwindow* window, glm::vec3& forward, glm::vec3& sideways, glm::vec3& moveDir, float deltaTime, float& z) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveDir -= forward;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveDir += forward;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveDir += sideways;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveDir -= sideways;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        z -= 20 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        z += 20 * deltaTime;
}

