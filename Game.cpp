#include "Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Camera.h"
#include "Input.h"
#include "Timer.h"
#include "GameObject.h"

using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;
ObjModel* playerModel;
ObjModel* cubeModel;

Camera* camera = new Camera();
GameObject block;
GameObject player;
Input input;
Timer timer;

void init();
void update();
void draw();

//variables
float rotation = camera->cameraYaw;
float x = 0;
float y = 0;
float z = 0;
float speed = 50.0f;



void Game::Run() {
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1400, 800, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

    while (!glfwWindowShouldClose(window))
    {
        update();
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
void init()
{
    input.KeyCallback(window);
    input.MouseCallback(window, camera);
    
    playerModel = new ObjModel("models/steve/steve.obj");
    cubeModel = new ObjModel("models/Grass/Grass_Block.obj");
    block = GameObject(cubeModel, glm::vec3(0,0,0), 0, glm::vec3(2,2,2));
    player = GameObject(playerModel, glm::vec3(x,y,z), rotation, glm::vec3(1,1,1));
    timer = Timer();

}

void update()
{
    timer.CalculateDeltaTimeAndGettingFps();

    glm::vec3 forward;
    forward.x = sin(camera->cameraYaw);
    forward.y = 0.0f;
    forward.z = -cos(camera->cameraYaw);

    glm::vec3 sideways;
    sideways.x = cos(camera->cameraYaw);
    sideways.y = 0.0f;
    sideways.z = sin(camera->cameraYaw);
    glm::vec3 moveDir(0.0f);

    input.HandleKeyboardInput(window, forward, sideways, moveDir, timer.GetDeltaTime(), z);

    // Normalize to prevent faster diagonal movement
    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    // Apply speed and update position
    x += moveDir.z * speed * timer.GetDeltaTime(); // notice: z corresponds to your "x" world axis
    y += moveDir.x * speed * timer.GetDeltaTime(); // and x corresponds to your "y" world axis

    rotation = -camera->cameraYaw - 1.57;
}

void draw()
{
    //background color
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //camera
    camera->DrawCamera(y, x, z);

    //Player
    player.SetTranslate(glm::vec3(y, z, x));
    player.SetRotation(rotation);
    player.DrawObject();

    //blocks
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            block.DrawObject();
        }
    }

    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}
