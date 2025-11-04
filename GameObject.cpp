#include "GameObject.h"
#include "ObjModel.h"

void GameObject::DrawObject(ObjModel* model) {
	model->draw();
}
glm::mat4 GameObject::TranslateObject(glm::mat4 matrix, float x, float y, float z) {
	return glm::translate(matrix, glm::vec3(x,y,z));
}

glm::mat4 GameObject::ScaleObject(glm::mat4 matrix, float x, float y, float z) {
	return glm::scale(matrix, glm::vec3(x, y, z));
}
glm::mat4 GameObject::RotateObject(glm::mat4 matrix, float rotation, float x, float y, float z) {
	return glm::rotate(matrix,rotation, glm::vec3(x, y, z));
}

