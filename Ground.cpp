#include "Ground.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
void Ground::DrawCube(ObjModel* model) {
    model->draw();
}

glm:: mat4 Ground::Cubetranslate(glm::mat4 matrix, float x, float y, float z) {
    return glm::translate(matrix, glm::vec3(x,y,z));
}
glm::mat4 Ground::CubeScale(glm::mat4 matrix, float x, float y, float z) {
    return glm::scale(matrix, glm::vec3(x, y, z));
}

Ground::Ground() {
    
}

Ground::~Ground() {
}

