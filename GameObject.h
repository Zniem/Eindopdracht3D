#pragma once
#include "Ground.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class GameObject
{
public:
	void DrawObject(ObjModel* model);
	glm::mat4 TranslateObject(glm::mat4 matrix, float x, float y, float z);
	glm::mat4 ScaleObject(glm::mat4 matrix, float x, float y, float z);
	glm::mat4 RotateObject(glm::mat4 matrix,float rotation, float x, float y, float z);

};

