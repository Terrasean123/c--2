#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Game.h"

void ShutDown();

int main()
{
	int ScreenWidth = 1980;
	int ScreenHeight = 1060;
	SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(ScreenWidth, ScreenHeight, "Legend of Fractalia");
	/*MaximizeWindow();*/
	SetTargetFPS(60);

	Vector2  start = Vector2{ 0, 0 };
	Vector2  end = Vector2{(float)ScreenWidth,(float)ScreenHeight};

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawLineEx(start, end, 20, RED);

		DrawText("Legend of Fractalia ", 190, 200, 300, RED);

		EndDrawing();
	}
}

void ShutDown()
{

	CloseWindow();

}

