#pragma once
#include "GameObject.h"
class World
{
	ObjModel* cubeModel = new ObjModel("models/Grass/Grass_Block.obj");
	GameObject block = GameObject(cubeModel, glm::vec3(0, 0, 0), 0, glm::vec3(2, 2, 2));
	
public:
	void DrawWorld();
	
};

