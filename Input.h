#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Camera.h"
#include "Input.h"
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
class Input
{
public:
	void KeyCallback(GLFWwindow* window);
	void MouseCallback(GLFWwindow* window, Camera* camera);
	void HandleKeyboardInput(GLFWwindow* window, glm::vec3& forward, glm::vec3& sideways, glm::vec3& moveDir, float deltaTime, float& z);
};

