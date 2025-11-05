#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "ObjModel.h"
class GameObject
{
private:
	ObjModel* objectModel;
	glm::vec3 objectTranslate;
	glm::vec3 objectScale;
	float objectRotation;
public:
	GameObject();
	GameObject(ObjModel* model, glm::vec3 translate,float rotation, glm::vec3 scale);
	~GameObject();

	void DrawObject() const;

	void SetTranslate(glm::vec3 translate);
	void SetRotation(float rotation);
	void SetScale(glm::vec3 scale);

};

