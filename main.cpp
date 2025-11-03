#pragma region "Includes and stuff"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Ground.h"
#include "Camera.h"
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")
#pragma endregion

GLFWwindow* window;
ObjModel* model;
ObjModel* cubeModel;

Ground ground;
Camera camera;

void init();
void update();
void draw();

//variables
float rotation = camera.cameraYaw;
float x = 0;
float y = 0;
float z = 0;
float speed = 50.0f;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main(void)
{
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


    return 0;
}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    camera.CameraMouseCallback(xpos,ypos);
}
void init()
{
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE)
                glfwSetWindowShouldClose(window, true);

        });
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide and grab cursor

    model = new ObjModel("models/steve/steve.obj");
    cubeModel = new ObjModel("models/Grass/Grass_Block.obj");
    ground = Ground();
    camera = Camera();
}

void update()
{
    float currentframe = glfwGetTime();
    deltaTime = currentframe - lastFrame;
    lastFrame = currentframe;

    glm::vec3 forward;
    forward.x = sin(camera.cameraYaw);
    forward.y = 0.0f;
    forward.z = -cos(camera.cameraYaw);

    glm::vec3 sideways;
    sideways.x = cos(camera.cameraYaw);
    sideways.y = 0.0f;
    sideways.z = sin(camera.cameraYaw);
    glm::vec3 moveDir(0.0f);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveDir -= forward;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveDir += forward;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveDir += sideways;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveDir -= sideways;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        z -= 20 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        z += 20 * deltaTime;

    // Normalize to prevent faster diagonal movement
    if (glm::length(moveDir) > 0.0f)
        moveDir = glm::normalize(moveDir);

    // Apply speed and update position
    x += moveDir.z * speed * deltaTime; // notice: z corresponds to your "x" world axis
    y += moveDir.x * speed * deltaTime; // and x corresponds to your "y" world axis

    rotation = -camera.cameraYaw - 1.57;
}

void draw()
{
    //background color
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //set viewport and perspective
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 500.0f);
    tigl::shader->setProjectionMatrix(projection);

    //setting camera
    tigl::shader->setViewMatrix(camera.DrawCamera(y,x,z));

    //Minecraft blocks
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            glm::mat4 cubeModelMatrix = ground.Cubetranslate(glm::mat4(1.0), i * 4, 1, j * 4);
            cubeModelMatrix = ground.CubeScale(cubeModelMatrix,2,2,2);
            tigl::shader->setModelMatrix(cubeModelMatrix);
            ground.DrawCube(cubeModel);

        }
    }


    //Player
    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(y, z, x));
    modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(modelMatrix);
    model->draw();

    tigl::shader->enableColor(true);
    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}
