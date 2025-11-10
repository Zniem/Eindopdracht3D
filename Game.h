#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "Input.h"
#include "Timer.h"
#include "GameObject.h"
#include "Player.h"
#include "World.h"

using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

class Game
{
private:
	int WINDOW_WIDTH = 1400;
	int WINDOW_HEIGHT = 800;
	GLFWwindow* window;
	Input input;
	Timer timer;
	Player player;
	World world;
	

	void Init();
	void Update();
	void Draw();

public:
	Game();
	~Game();
	void Run();
};

