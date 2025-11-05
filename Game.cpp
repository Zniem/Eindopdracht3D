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
#include "Player.h"

using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;

ObjModel* cubeModel;

GameObject block;
Input input;
Timer timer;
Player player;

void init();
void update();
void draw();

//variables




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
void init(){
    player = Player();
    timer = Timer();

    cubeModel = new ObjModel("models/Grass/Grass_Block.obj");
    block = GameObject(cubeModel, glm::vec3(0,0,0), 0, glm::vec3(2,2,2));

    input.KeyCallback(window);
    input.MouseCallback(window, player.GetCamera());
    

}

void update()
{
    timer.CalculateDeltaTimeAndGettingFps();
    player.UpdatePlayer(input, window, timer);
}

void draw()
{
    //background color
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Player
    player.DrawPlayer();
   
    //block
    block.DrawObject();

    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}
