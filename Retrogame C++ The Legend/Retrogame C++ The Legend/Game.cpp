#include "Game.h"
#include "Map.h"
#include <iostream>


Game::Game()
{
	player_Zata.sprite.Load("../../SpriteFolder/ ZataSprite-0001.png");
}

Game::~Game()
{


}


void  Game::debug(bool debugging)
{
	
	if (debugging == true)
	{
		//std::cout << "seconds:" << gameTime.GetDeltaTime() << std::endl;
		if(lastspeed < player_Zata.actorSpeed)
		{
			lastspeed = player_Zata.actorSpeed;
			cout <<"player Actor speed :" << lastspeed << endl;

		}
		if (lastspeed > player_Zata.actorSpeed)
		{
			lastspeed = player_Zata.actorSpeed;
			cout << "player Actor speed :" << lastspeed << endl;
		}
	}
}

void Game::Update()
{
	PlayerControls();
	GameMap.ManageTiles();
	player_Zata.Update(0);
	debug(true);


}



void Game::PlayerControls()
{
	float lastrot = 0;
	if (IsKeyDown(KEY_L))
	{
		player_Zata.swordSprite.rotation++;
		if (lastrot < player_Zata.swordSprite.rotation)
		{
			 lastrot = player_Zata.swordSprite.rotation;
			cout << "sword rotation:" << player_Zata.swordSprite.rotation << endl;

		}
	}
	
	if(IsKeyReleased(MOUSE_BUTTON_LEFT))
	{

	
	
	
	}

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
	GameMap.CreateMap();
	//player_Zata.swordSprite.Draw();
	player_Zata.DrawReverse();

    //DrawRectangle(player_Zata.globalPosition.x, player_Zata.globalPosition.y ,20,20 ,RED);
//	DrawRectangle(player_Zata.swordObject.globalPosition.x, player_Zata.swordObject.globalPosition.y, 20, 20, RED);
//	DrawRectangle(player_Zata.swordSprite.globalPosition.x, player_Zata.swordSprite.globalPosition.y, 20, 20, RED);
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
