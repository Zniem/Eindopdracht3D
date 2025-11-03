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

GLFWwindow* window;
ObjModel* model;
ObjModel* cubeModel;

Ground ground;
Camera camera;

void init();
void update();
void draw();
float rotation = camera.cameraYaw;
float x = 0;
float y = 0;
float speed = 0.25f;
//float targetRotation = rotation;


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
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        y += 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
       
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        
    }
    /*float lerpspeed = 0.1f;
    float delta = targetRotation - rotation;
    while (delta > glm::pi<float>()) delta -= glm::two_pi<float>();
    while (delta < -glm::pi<float>()) delta += glm::two_pi<float>();

    rotation += delta * lerpspeed;*/
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
    tigl::shader->setViewMatrix(camera.DrawCamera(y,x));

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
    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(y, 0, x));
    modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(modelMatrix);
    model->draw();

    tigl::shader->enableColor(true);
    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}
