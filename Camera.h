#pragma once
#include <glm/gtc/matrix_transform.hpp>
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
	void DrawCamera(float y, float x, float z);
	void CameraMouseCallback(double xpos, double ypos);
	};

