#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "c++"

int main()
{
	Vector2* begin = new Vector2();
	InitWindow(250, 250, "The Legend Of something");
	DrawLineEx(new Vector2(0, 0), new Vector2*(255, 255)),20,Color();
	CloseWindow();


}