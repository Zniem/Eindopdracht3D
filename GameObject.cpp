#include "GameObject.h"
#include "ObjModel.h"
#include "tigl.h"

//Constructor
GameObject::GameObject(ObjModel* model, glm::vec3 translate, float rotation, glm::vec3 scale)
	: objectModel(model), objectTranslate(translate), objectRotation(rotation), objectScale(scale)
{}

//Method for drawing an object
void GameObject::DrawObject(){
	tigl::shader->setModelMatrix(GetModelMatrix());
	objectModel->draw();
}

//Method for getting the current matrix
glm::mat4 GameObject::GetModelMatrix() {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, objectTranslate);
	modelMatrix = glm::rotate(modelMatrix, objectRotation, glm::vec3(0, 1, 0));
	modelMatrix = glm::scale(modelMatrix, objectScale);
	return modelMatrix;
}

//Setters
void GameObject::SetTranslate(glm::vec3 translate) {objectTranslate = translate;}
void GameObject::SetRotation(float rotation) {objectRotation = rotation;}
void GameObject::SetScale(glm::vec3 scale) {objectScale = scale;}

//Default constructor and deconstructor
GameObject::~GameObject() {}
GameObject::GameObject() {}
