#include "Timer.h"
#include <GLFW/glfw3.h>
#include "iostream"

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float delayTimer = 0.0f;
void Timer::CalculateDeltaTimeAndGettingFps() {
    float currentframe = glfwGetTime();
    deltaTime = currentframe - lastFrame;
    lastFrame = currentframe;

    delayTimer += deltaTime;
    if (delayTimer > 1.0f) {
        int fps = 1 / deltaTime;
        std::cout << "fps: " << fps << std::endl;
        delayTimer = 0.0f;
    }
}

float Timer::GetDeltaTime() {
    return deltaTime;
}