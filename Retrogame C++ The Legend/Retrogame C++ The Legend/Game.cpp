#include "Game.h"
#include "Map.h"
#include <iostream>

Game::Game()
{
player_Zata.AddChild(&player_Zata.sprite);
	player_Zata.sprite.Load("../../SpriteFolder/ ZataSprite-0001.png");
	player_Zata.SetPosition(-player_Zata.sprite.GetWidth() / 2.0f, player_Zata.sprite.GetWidth() / 2.0f);
	player_Zata.Translate(GetScreenWidth() / 2, GetScreenHeight() / 2);
	player_Zata.sprite.spriteScale = 5;
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
	GameMap.ManageTiles();
	player_Zata.Update(time);
	


}



void Game::PlayerControls()
{
	if (IsKeyDown(KEY_W))
	{
		player_Zata.Translate(0, -4);
	}

	if (IsKeyDown(KEY_S))
	{
		player_Zata.Translate(0, 4);
	}

	if (IsKeyDown(KEY_A))
	{
		player_Zata.Translate(-4, 0);

	}

	if (IsKeyDown(KEY_D))
	{
		player_Zata.Translate(4, 0);
		
		
	}
}



void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	//GameMap.DrawMap();
	GameMap.CreateMap();
	player_Zata.Draw();
	EndDrawing();


}