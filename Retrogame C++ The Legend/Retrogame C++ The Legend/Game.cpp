#include "Game.h"
#include "Map.h"
#include <iostream>

Game::Game()
{
player_Zata.AddChild(&player_Zata.sprite);
	player_Zata.sprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/ ZataSprite-0001.png");
	player_Zata.SetPosition(-player_Zata.sprite.GetWidth() / 2.0f, player_Zata.sprite.GetWidth() / 2.0f);
	player_Zata.Translate(GetScreenWidth() / 2, GetScreenHeight() / 2);
}

Game::~Game()
{


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
		std::cout << player_Zata.globalPosition.x << "," << player_Zata.globalPosition.y << std::endl;
	}

	if (IsKeyDown(KEY_S))
	{
		player_Zata.Translate(0, 10);
		std::cout << player_Zata.globalPosition.x << "," << player_Zata.globalPosition.y << std::endl ;
	}

	if (IsKeyDown(KEY_A))
	{
		player_Zata.Translate(-10, 0);
		std::cout << player_Zata.globalPosition.x << "," << player_Zata.globalPosition.y << std::endl;

	}

	if (IsKeyDown(KEY_D))
	{
		player_Zata.Translate(10, 0);
		std::cout << player_Zata.globalPosition.x << "," << player_Zata.globalPosition.y << std::endl;
		
	}
}



void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	GameMap.DrawMap();
	player_Zata.Draw();

	EndDrawing();


}