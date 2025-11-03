#include "Camera.h"



glm::mat4 Camera::DrawCamera(float y, float x, float z) {
    //Camera
    glm::vec3 targetPos = glm::vec3(y, z, x);

    float camDistance = 20.0f;
    float camHeight = 4.0f;

    // Calculate direction from yaw and pitch
    glm::vec3 direction;
    direction.x = sin(Camera::cameraYaw) * cos(Camera::cameraPitch);
    direction.y = sin(Camera::cameraPitch);
    direction.z = -cos(Camera::cameraYaw) * cos(Camera::cameraPitch);

    glm::vec3 cameraPos = targetPos + glm::vec3(0, camHeight, 0) + direction * camDistance;
    return glm::lookAt(cameraPos, targetPos + glm::vec3(0, camHeight, 0), glm::vec3(0, 1, 0));

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
Camera::Camera() {

}
Camera::~Camera() {
}