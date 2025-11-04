#pragma once

#include "stb_image.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "ObjModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class TerrainGeneration
{
public:
	std::vector<float> GenerateTerrain();
};

