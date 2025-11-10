#include "World.h"
void World::DrawWorld() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			block.SetTranslate(glm::vec3(i,0,j));
			block.DrawObject();
		}
	}
	
}