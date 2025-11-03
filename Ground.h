#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class Ground
{
public:
	Ground();
	~Ground();
	void DrawCube(ObjModel* model);
	glm::mat4 Cubetranslate(glm::mat4 matrix, float x, float y, float z);
	glm::mat4 CubeScale(glm::mat4 matrix, float x, float y, float z);
};

