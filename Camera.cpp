#include "Camera.h"
#include "tigl.h"
#include <iostream>

void Camera::DrawCamera(glm::vec3 cameraPostion) {
    UpdateProjectionMatrix();
    tigl::shader->setViewMatrix(UpdateViewMatrix(cameraPostion));

}
void Camera::CameraMouseCallback(double xpos, double ypos) {

    if (Camera::firstMouse)
    {
        
        Camera::lastMouseX = xpos;
        Camera::lastMouseY = ypos;
        Camera::firstMouse = false;
    }

    float sensitivity = 0.005f; // Adjust for feel
    float xoffset = float(xpos - Camera::lastMouseX) * sensitivity;
    float yoffset = float(Camera::lastMouseY - ypos) * sensitivity; // Reversed: y ranges bottom to top

    Camera::lastMouseX = xpos;
    Camera::lastMouseY = ypos;

    Camera::cameraYaw += xoffset;
    Camera::cameraPitch += yoffset;

    // Clamp pitch to avoid flipping
    if (cameraPitch > glm::radians(89.0f))  cameraPitch = glm::radians(89.0f);
    if (cameraPitch < glm::radians(-89.0f)) cameraPitch = glm::radians(-89.0f);
}

void Camera::UpdateProjectionMatrix() {
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 500.0f);
    tigl::shader->setProjectionMatrix(projection);

}
glm::mat4 Camera::UpdateViewMatrix(glm::vec3 cameraPostion) {
    // Calculate direction from yaw and pitch
    glm::vec3 direction;
    direction.x = sin(Camera::cameraYaw) * cos(Camera::cameraPitch);
    direction.y = sin(Camera::cameraPitch);
    direction.z = -cos(Camera::cameraYaw) * cos(Camera::cameraPitch);

    glm::vec3 cameraPos = cameraPostion + glm::vec3(0, Camera::camHeight, 0) + direction * Camera::camDistance;
    
    return glm::lookAt(cameraPos, cameraPostion + glm::vec3(0, Camera::camHeight, 0), glm::vec3(0, 1, 0));
}

Camera::Camera() {
}
Camera::~Camera() {}