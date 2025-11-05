#include "GameObject.h"
#include "ObjModel.h"
#include "tigl.h"

GameObject::GameObject(ObjModel* model, glm::vec3 translate, float rotation, glm::vec3 scale)
{
	objectModel = model;
	objectTranslate = translate;
	objectRotation = rotation;
	objectScale = scale;
}

void GameObject::DrawObject() const {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, objectTranslate);
	modelMatrix = glm::rotate(modelMatrix, objectRotation, glm::vec3(0, 1, 0));
	modelMatrix = glm::scale(modelMatrix, objectScale);
	tigl::shader->setModelMatrix(modelMatrix);
	objectModel->draw();
}

void GameObject::SetTranslate(glm::vec3 translate) {
	objectTranslate = translate;
}
void GameObject::SetRotation(float rotation) {
	objectRotation = rotation;
}
void GameObject::SetScale(glm::vec3 scale) {
	objectScale = scale;
}

GameObject::~GameObject() {}
GameObject::GameObject() {}
