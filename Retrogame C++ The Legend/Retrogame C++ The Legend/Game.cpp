#include "Game.h"
#include "Map.h"
#include <iostream>


Game::Game()
{
	player_Zata.sprite.Load("../../SpriteFolder/ ZataSprite-0001-sheet.png");

//	player_Zata.sprite.Load("../../SpriteFolder/ ZataSprite-0001-sheet.png");
}

Game::~Game()
{


}


void  Game::debug(bool debugging)
{
	
	if (debugging == true)
	{
		std::cout << "seconds:" << gameTime.GetDeltaTime() << std::endl;
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

void Game::ChoosePlayerDrawType(bool walkingForward)
{
	if(walkingForward == true)
	{
		player_Zata.DrawReverse();
	
	}
	else
	{
		player_Zata.Draw();

	}


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

	if (IsKeyDown(KEY_W))//forward
	{
		direction = 0;
		forward = true;
		PlayerAnim(direction);
		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(360);
		player_Zata.Move(-gameTime.GetDeltaTime(), true);
	}

	if (IsKeyDown(KEY_S))//backward
	{
		direction = 3;

		forward = false;
		PlayerAnim(direction);

		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(180);
		player_Zata.Move(gameTime.GetDeltaTime(), true);
	}


	if (IsKeyDown(KEY_A))//left
	{
		direction = 1;
		forward = false;
		PlayerAnim(direction);

		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(270);
		player_Zata.Move(-gameTime.GetDeltaTime(), false);
	}


	if (IsKeyDown(KEY_D))//right
	{
		direction = 2;

		forward = false;
		PlayerAnim(direction);

		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(90);
		player_Zata.Move(gameTime.GetDeltaTime(), false);
	}


}
void Game::PlayerAnim(int direction)
{					   
   if(direction == 0 )
   {
	   player_Zata.sprite.aniIterator = player_Zata.forwardAnim.aniStart;
	   if (player_Zata.sprite.aniIterator < player_Zata.forwardAnim.aniEnd)
		   player_Zata.sprite.aniIterator += 1;
   
   }
   if (direction == 1)
   {
	   player_Zata.sprite.aniIterator = player_Zata.leftAnim.aniStart;
	   if (player_Zata.sprite.aniIterator < player_Zata.leftAnim.aniEnd)
		   player_Zata.sprite.aniIterator += GetFrameTime();

   }
   if (direction == 2)
   {
	   player_Zata.sprite.aniIterator = player_Zata.rightAnim.aniStart;
	   if (player_Zata.sprite.aniIterator < player_Zata.rightAnim.aniEnd)
		   player_Zata.sprite.aniIterator += GetFrameTime();

   }
   if (direction == 3)
   {
	   player_Zata.sprite.aniIterator = player_Zata.backAnim.aniStart;
	   if (player_Zata.sprite.aniIterator < player_Zata.backAnim.aniEnd)
		   player_Zata.sprite.aniIterator += GetFrameTime();

   }
}


void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	GameMap.CreateMap();
	//player_Zata.swordSprite.Draw();
	ChoosePlayerDrawType(forward);
    

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
