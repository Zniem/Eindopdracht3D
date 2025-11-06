#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "Input.h"
#include "Timer.h"
#include <GLFW/glfw3.h>
class Player : public GameObject
{
private:
	GameObject player;	
	Camera* camera;
	ObjModel* playerModel;
	float rotation = 0;
	float playerX = 0;
	float playerY = 0;
	float playerZ = 0;
	float speed = 50.0f;
public:
	Player();
	~Player();

	void UpdatePlayer(Input input, GLFWwindow* window, Timer timer);
	void DrawPlayer();

	Camera* GetCamera();
};

