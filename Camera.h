#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class Camera
{
public:
	float cameraYaw = 0.0f;   // Horizontal angle (Y axis)
	float cameraPitch = 0.0f; // Vertical angle (X axis)
	double lastMouseX = 700;
	double lastMouseY = 400; // Start at window center
	bool firstMouse = true;

	Camera();
	~Camera();
	glm::mat4 DrawCamera(float y, float x, float z);
	void CameraMouseCallback(double xpos, double ypos);
	};

