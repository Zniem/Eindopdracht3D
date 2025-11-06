#pragma once
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
private:
	float cameraPitch = 0.0f; // Vertical angle (X axis)
	double lastMouseX = 700;
	double lastMouseY = 400; // Start at window center
	bool firstMouse = true;
	float camDistance = 20.0f;
	float camHeight = 4.0f;
	float cameraYaw = 0.0f;   // Horizontal angle (Y axis)
public:

	

	Camera();
	~Camera();
	void DrawCamera(glm::vec3 cameraPosition);
	void CameraMouseCallback(double xpos, double ypos);

	void UpdateProjectionMatrix();
	glm::mat4 UpdateViewMatrix(glm::vec3 cameraPostion);

	float GetCameraYaw() { return cameraYaw; }

};

