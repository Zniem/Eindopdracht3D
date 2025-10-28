#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;
ObjModel* model;
ObjModel* cubeModel;

void init();
void update();
void draw();
float rotation = 1.57;
float x = 1;

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


void init()
{
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, true);
        if (key == GLFW_KEY_A)
            rotation = 2.356;
        if (key == GLFW_KEY_D)
            rotation = 0.785;
        if (key == GLFW_KEY_W) {
            x -= 1;
            rotation = 1.57;
        }
        if (key == GLFW_KEY_S) {
            x += 1;
            rotation = 4.71;
        }
    });


    model = new ObjModel("models/steve/steve.obj");
    cubeModel = new ObjModel("models/Grass/Grass_Block.obj");
}

void update()
{
}

void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 500.0f);
    tigl::shader->setProjectionMatrix(projection);

    //Camera
    glm::vec3 targetPos = glm::vec3(0, 5, x);          
    glm::vec3 cameraOffset = glm::vec3(0, 2, 10);      
    glm::vec3 cameraPos = targetPos + cameraOffset;    
    tigl::shader->setViewMatrix(glm::lookAt(cameraPos, targetPos, glm::vec3(0, 1, 0)));

    //Minecraft block
    glm::mat4 cubeModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(10, 0, 0)); 
    cubeModelMatrix = glm::scale(cubeModelMatrix, glm::vec3(2, 2, 2));
    tigl::shader->setModelMatrix(cubeModelMatrix);
    cubeModel->draw();
    
    //Player
    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0,x));
    modelMatrix = glm::rotate(modelMatrix, rotation, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(modelMatrix);
    model->draw();

    tigl::shader->enableColor(true);
    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}
