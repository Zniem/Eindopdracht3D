#include "Player.h"
#include "Input.h"
#include "Timer.h"

Player::Player() {
    playerModel = new ObjModel("models/steve/steve.obj");
    player = GameObject(playerModel, glm::vec3(), rotation, glm::vec3(1,1,1));
    camera = Camera();
}

Player::~Player() {
    
}
void Player::UpdatePlayer(Input input, GLFWwindow* window, Timer timer) {
   
    glm::vec3 forward(sin(camera.GetCameraYaw()), 0.0f, -cos(camera.GetCameraYaw()));
    glm::vec3 sideways(cos(camera.GetCameraYaw()), 0.0f, sin(camera.GetCameraYaw()));
    glm::vec2 direction = input.HandleKeyboardInput(window);
    glm::vec3 moveDir = forward * direction.y + sideways * direction.x;

    // Normalize to prevent faster diagonal movement
    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    // Apply speed and update position
    playerZ += moveDir.z * speed * timer.GetDeltaTime(); // notice: z corresponds to your "x" world axis
    playerX += moveDir.x * speed * timer.GetDeltaTime(); // and x corresponds to your "y" world axis

    rotation = -camera.GetCameraYaw() - 1.57;
}

void Player::DrawPlayer() {
    //camera
    camera.DrawCamera(glm::vec3(playerX, playerY, playerZ));
    player.SetTranslate(glm::vec3(playerX, playerY, playerZ));
    player.SetRotation(rotation);
    player.DrawObject();
}

Camera* Player::GetCamera() {
    return& camera;
}