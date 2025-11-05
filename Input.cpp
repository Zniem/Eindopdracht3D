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

glm::vec2 Input::HandleKeyboardInput(GLFWwindow* window) {

    glm::vec2 direction(0.0f);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        direction.y -= 1.0f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        direction.y += 1.0f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        direction.x += 1.0f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        direction.x -= 1.0f;
    /*if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        z -= 20 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        z += 20 * deltaTime;*/
    return direction;
}

