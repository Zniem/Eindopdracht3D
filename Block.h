#pragma once
#include "GameObject.h"
class Block: public GameObject
{
public:
	void DrawCube(float x, float y, float z, float size);
	void initTexture();
	Block();
	~Block();

};

