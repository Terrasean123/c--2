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
	player_Zata.actorSpeed = 20;
	player_Zata.actorMaxSpeed = 300;

}

Game::~Game()
{


}


void  Game::debug(bool debugging)
{
	if (debugging == true)
	{
		std::cout << "seconds:" << gameTime.GetDeltaTime() << std::endl;
		float movedDistance = player_Zata.actorSpeed * gameTime.GetDeltaTime();
		player_Zata.globalPosition.y = player_Zata.globalPosition.y + movedDistance;
		player_Zata.SetPosition(player_Zata.globalPosition.x, player_Zata.globalPosition.y);
	}
}

void Game::Update()
{
	PlayerControls();
	GameMap.ManageTiles();
	player_Zata.Update(0);
	debug(false);


}



void Game::PlayerControls()
{

	if (IsKeyDown(KEY_K))
	{
		player_Zata.actorSpeed -= 1;
		if (player_Zata.actorSpeed < 0)
			player_Zata.actorSpeed = 0;

	}
	if (IsKeyDown(KEY_I))
	{
		player_Zata.actorSpeed += 1;
		if (player_Zata.actorSpeed > player_Zata.actorMaxSpeed)
			player_Zata.actorSpeed = player_Zata.actorMaxSpeed;
	}

	if (IsKeyDown(KEY_W))
	{
		player_Zata.Move(-gameTime.GetDeltaTime(), true);
	}

	if (IsKeyDown(KEY_S))
	{
		player_Zata.Move(gameTime.GetDeltaTime(), true);
	}


	if (IsKeyDown(KEY_A))
	{
		player_Zata.Move(-gameTime.GetDeltaTime(), false);
	}


	if (IsKeyDown(KEY_D))
	{
		player_Zata.Move(gameTime.GetDeltaTime(), false);
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

Game::Timer::Timer()
{


}
void Game::Timer::Stopwatch()
{



}

float Game::Timer::GetDeltaTime()
{
	deltaTime = GetFrameTime();
	return deltaTime;
}

float Game::Timer::Seconds()
{
	high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

	float dur_seconds = std::chrono::duration<float>(end - start).count();

	return dur_seconds;
}
