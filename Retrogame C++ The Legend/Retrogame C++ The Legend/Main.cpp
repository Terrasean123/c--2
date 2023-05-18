#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Game.h"

int main()
{
	Game game;
	int ScreenWidth = 1980;
	int ScreenHeight = 1060;
	SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(ScreenWidth, ScreenHeight, "Legend of Fractalia");
	game.init();
	game.debug();
	/*MaximizeWindow();*/
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}
}
