#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Block.h"
#include "Camera.h"
#include "Player.h"
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
	void HandleKeyboardInput();
};

