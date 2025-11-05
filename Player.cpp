#include "Player.h"
#include "Input.h"
#include "Timer.h"

Player::Player() {
    playerModel = new ObjModel("models/steve/steve.obj");
    player = GameObject(playerModel, glm::vec3(), rotation, glm::vec3(1,1,1));
}

Player::~Player() {
    
}
void Player::UpdatePlayer(Input input, GLFWwindow* window, Timer timer) {
   
    glm::vec3 forward(sin(camera->cameraYaw), 0.0f, -cos(camera->cameraYaw));
    glm::vec3 sideways(cos(camera->cameraYaw), 0.0f, sin(camera->cameraYaw));
    glm::vec2 direction = input.HandleKeyboardInput(window);
    glm::vec3 moveDir = forward * direction.y + sideways * direction.x;

    // Normalize to prevent faster diagonal movement
    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    // Apply speed and update position
    playerX += moveDir.z * speed * timer.GetDeltaTime(); // notice: z corresponds to your "x" world axis
    playerY += moveDir.x * speed * timer.GetDeltaTime(); // and x corresponds to your "y" world axis

    rotation = -camera->cameraYaw - 1.57;
}

void Player::DrawPlayer() {
    //camera
    camera->DrawCamera(playerY, playerX, playerZ);
    player.SetTranslate(glm::vec3(playerY, playerZ, playerX));
    player.SetRotation(rotation);
    player.DrawObject();
}

Camera* Player::GetCamera() {
    return camera;
}