#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "ObjModel.h"
class GameObject
{
private:
	//GameObject variables
	ObjModel* objectModel;
	glm::vec3 objectTranslate;
	glm::vec3 objectScale;
	float objectRotation;

public:
	GameObject(ObjModel* model, glm::vec3 translate,float rotation, glm::vec3 scale);

	void DrawObject();

	glm::mat4 GetModelMatrix();

	void SetTranslate(glm::vec3 translate);
	void SetRotation(float rotation);
	void SetScale(glm::vec3 scale);

	GameObject();
	~GameObject();
};

