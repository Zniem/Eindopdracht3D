#include "Block.h"
#include "tigl.h"
using tigl::Vertex;

void Block::DrawCube(float x, float y, float z, float size) {
    glm::vec3 offset(x, y, z);
    float s = size / 2.0f;  // Halve grootte voor correcte plaatsing

    // Top face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, -s), glm::vec4(0, 0.5, 0, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, -s), glm::vec4(0, 0.5, 0, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, s), glm::vec4(0, 0.5, 0, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, s), glm::vec4(0, 0.5, 0, 0)));
    tigl::end();

    // Bottom face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::end();

    // Front face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::end();

    // Back face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::end();

    // Left face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(-s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::end();

    // Right face
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::addVertex(Vertex::PC(offset + glm::vec3(s, -s, -s), glm::vec4(0.54, 0.27, 0.07, 0)));
    tigl::end();
}