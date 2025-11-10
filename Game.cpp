#include "Game.h"
void Game::Run() {
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    Init();

    while (!glfwWindowShouldClose(window))
    {
        Update();
        Draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
void Game::Init(){
    player = Player();
    timer = Timer();
    world = World();

    

    input.KeyCallback(window);
    input.MouseCallback(window, player.GetCamera());

    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);
    glPointSize(10.0f);
}

void Game::Update()
{
    timer.CalculateDeltaTimeAndGettingFps();
    player.UpdatePlayer(input, window, timer);
}

void Game::Draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    player.DrawPlayer();
    world.DrawWorld();
}

Game::Game() {

}
Game::~Game() {}
