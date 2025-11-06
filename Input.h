#pragma once
#include <GLFW/glfw3.h>
#include "Camera.h"

class Input
{
public:
	void KeyCallback(GLFWwindow* window);
	void MouseCallback(GLFWwindow* window, Camera* camera);
	glm::vec2 HandleKeyboardInput(GLFWwindow* window);
};

