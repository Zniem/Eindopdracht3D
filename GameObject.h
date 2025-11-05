#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "ObjModel.h"
class GameObject
{
private:
	float pX;
	float pY;
	float pZ;
	ObjModel* pModel;

public:
	GameObject(ObjModel* model,float x, float y, float z);
	~GameObject();


	void DrawObject(ObjModel* model, float rotation, glm::vec3 scale);
	glm::mat4 TranslateObject(glm::mat4 matrix, float x, float y, float z);
	glm::mat4 ScaleObject(glm::mat4 matrix, float x, float y, float z);
	glm::mat4 RotateObject(glm::mat4 matrix,float rotation, float x, float y, float z);

};

