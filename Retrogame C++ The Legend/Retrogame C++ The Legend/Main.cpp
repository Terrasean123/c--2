#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Game.h"

int main()
{
	
	int ScreenWidth = 1920;
	int ScreenHeight = 1080;
	InitWindow(ScreenWidth, ScreenHeight, "Legend of Fractalia");
	Game game;
	//game.spawnEnemies();
	
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
		
	}
}
