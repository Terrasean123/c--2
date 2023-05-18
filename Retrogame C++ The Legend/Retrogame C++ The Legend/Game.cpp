#include "Game.h"
#include <iostream>

Game::Game()
{

}

void Game::init()
{
	player_Zata.AddChild(&player_Zata.sprite);

	player_Zata.sprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/ ZataSprite-0001.png");
	player_Zata.SetPosition(-player_Zata.sprite.GetWidth() / 2.0f, player_Zata.sprite.GetWidth() / 2.0f);

	player_Zata.Translate(10, 10);
}


void  Game::debug()
{


}

void Game::Update()
{
	PlayerControls();
	player_Zata.Update(time);
	


}

void Game::PlayerControls()
{
	if (IsKeyDown(KEY_W))
	{
		player_Zata.Translate(0, -10);
	}

	if (IsKeyDown(KEY_S))
	{
		player_Zata.Translate(0, 10);
	}

	if (IsKeyDown(KEY_A))
	{
		player_Zata.Translate(10, 0);
	}

	if (IsKeyDown(KEY_D))
	{
		player_Zata.Translate(-10, 0);
	}

}



void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Legend of Fractalia ", 190, 200, 300, RED);

	player_Zata.Draw();

	EndDrawing();


}