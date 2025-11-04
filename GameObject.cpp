#include "GameObject.h"
#include "ObjModel.h"
#include "tigl.h"

void GameObject::DrawObject(ObjModel* model, glm::vec3 translate, float rotation, glm::vec3 scale) {
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	modelMatrix = TranslateObject(modelMatrix, translate.x, translate.y, translate.z);
	modelMatrix = RotateObject(modelMatrix, rotation, 0,1,0);
	modelMatrix = ScaleObject(modelMatrix, scale.x, scale.y, scale.z);
	tigl::shader->setModelMatrix(modelMatrix);
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

