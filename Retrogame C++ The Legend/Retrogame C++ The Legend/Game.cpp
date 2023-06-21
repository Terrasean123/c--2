#include "Game.h"
#include "Map.h"
#include <iostream>


Game::Game()
{
	player_Zata.sprite.Load("../../SpriteFolder/ ZataSprite-0001-sheet.png");
	GameMap.CreateMap();
	enemy1.Translate(0, 100);
	enemy3.Translate(0, -200);
	enemy2.Translate(0, 300);

}

Game::~Game()
{


}
//
//void Game::spawnEnemies()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		Enemies enemy = Enemies();
//		enemy.globalPosition.x = GetScreenWidth() / 2;
//		enemy.globalPosition.y = GetScreenHeight() / 2;
//		EnemyGroup.push_back(&enemy);
//	}
//}

void  Game::debug(bool debugging)
{

	if (debugging == true)
	{

		std::cout << player_Zata.alive << endl;
		//	std::cout << enemy1.health << endl;

			//gameTime.seconds += gameTime.GetDeltaTime();
			//std::cout << "seconds:" << gameTime.sec << std::endl;
			//if (lastspeed < player_Zata.actorSpeed)
			//{
			//	lastspeed = player_Zata.actorSpeed;
			//	cout << "player Actor speed :" << lastspeed << endl;

			//}
			//if (lastspeed > player_Zata.actorSpeed)
			//{
			//	lastspeed = player_Zata.actorSpeed;
			//	cout << "player Actor speed :" << lastspeed << endl;
			//}
			//if ((int)(gameTime.sec - remainder(gameTime.sec, 1)) % 2 == 0)
			//{
			//	//cout << "remainder :" << gameTime.sec/ 2 + remainder(gameTime.sec, 2) << endl;
			//	cout << "remainder :" << gameTime.sec - remainder(gameTime.sec, 1) << endl;

			//}
			//cout << "animation number :" << player_Zata.sprite.aniIterator << endl;
	}
}

void Game::Update()
{
	if (gameOn == true)
	{
		WinCondition();
		gameTime.m_timer += gameTime.GetDeltaTime();
		if (player_Zata.alive == true)
		{
			PlayerControls();
		}
		GameMap.ManageTiles();
		player_Zata.Update(0);
		playerStateMonitor();
		EnemyStateMonitor();
		UpdateActorCollsionBoxes();
		enemy1.FollowBehaviour(ConvertGlmVec(player_Zata.globalPosition), gameTime.GetDeltaTime());
		enemy2.FollowBehaviour(ConvertGlmVec(player_Zata.globalPosition), gameTime.GetDeltaTime());

		enemy3.FollowBehaviour(ConvertGlmVec(player_Zata.globalPosition), gameTime.GetDeltaTime());



		debug(true);

	}

}

void Game::ChoosePlayerDrawType(bool walkingForward)
{
	if (walkingForward == true)
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
	gameTime.m_timer += gameTime.GetDeltaTime();

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

	if (IsKeyDown(KEY_M))
	{
		player_Zata.swordSprite.animated = false;
		/*if (lastrot < player_Zata.swordObject.rotation)
		{
			lastrot = player_Zata.swordObject.rotation;
			cout << "sword rotation:" << player_Zata.swordObject.rotation << endl;

		}*/
	}


	if (IsKeyDown(KEY_N))
	{
		player_Zata.swordSprite.animated = true;
		/*if (lastrot < player_Zata.swordObject.rotation)
		{
			lastrot = player_Zata.swordObject.rotation;
			cout << "sword rotation:" << player_Zata.swordObject.rotation << endl;

		}*/
	}



	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		slash = true;

		if(direction==0)
		{
			player_Zata.min_Yextender= -75;

		}

		if (direction == 1)
		{
			player_Zata.min_Xextender = -75;

		}

		if (direction == 2)
		{
			player_Zata.max_Xextender = 75;

		}
		
		if (direction == 3)
		{
			player_Zata.max_Yextender = 75;

		}
	}

	if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))
	{
		player_Zata.max_Xextender = 0;
		player_Zata.max_Yextender = 0;
		player_Zata.min_Xextender = 0;
		player_Zata.min_Yextender = 0;
		

		slash = false;
		if (direction == 2)
		{

			player_Zata.swordSprite.aniIterator = player_Zata.leftSwordAnim.aniStart;
		}

		if (direction == 1)
		{

			player_Zata.swordSprite.aniIterator = player_Zata.rightSwordAnim.aniStart;
		}

		if (direction == 2)
		{

			player_Zata.swordSprite.aniIterator = player_Zata.leftSwordAnim.aniStart;
		}

		if ((direction == 1) == false && (direction == 2) == false)
		{

			player_Zata.swordSprite.aniIterator = player_Zata.rightSwordAnim.aniStart;
		}
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
		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(90);
		player_Zata.Move(-gameTime.GetDeltaTime(), false);
	}


	if (IsKeyDown(KEY_D))//right
	{
		direction = 2;
		forward = false;
		PlayerAnim(direction);
		player_Zata.swordSprite.rotation = player_Zata.SwordRotation(270);
		player_Zata.Move(gameTime.GetDeltaTime(), false);
	}

	if (IsKeyDown(KEY_W) == false && IsKeyDown(KEY_A) == false && IsKeyDown(KEY_S) == false && IsKeyDown(KEY_D) == false)
	{
		once1 = 0;
		once2 = 0;
		once3 = 0;
		once4 = 0;

		if (direction == 0)
		{
			player_Zata.sprite.aniIterator = player_Zata.forwardAnim.aniStart;
		}

		if (direction == 1)
		{
			player_Zata.sprite.aniIterator = player_Zata.leftAnim.aniStart;

		}

		if (direction == 2)
		{
			player_Zata.sprite.aniIterator = player_Zata.rightAnim.aniStart;

		}

		if (direction == 3)
		{
			player_Zata.sprite.aniIterator = player_Zata.backAnim.aniStart;

		}
	}






	SwordAnim(direction, slash);
}

void Game::SwordAnim(int Direction, bool slash)
{


	if (slash == true)
	{
		if (Direction == 2)
		{
			if (gameTime.m_timer >= 0.02)
			{
				gameTime.m_timer = 0.0f;

				if (player_Zata.swordSprite.aniIterator != player_Zata.leftSwordAnim.aniEnd)
				{
					player_Zata.swordSprite.aniIterator += 1;
				}
				else
				{
					player_Zata.swordSprite.aniIterator = player_Zata.leftSwordAnim.aniStart;
				}
			}
		}


		if (Direction == 1)
		{
			if (gameTime.m_timer >= 0.02f)
			{
				gameTime.m_timer = 0.0f;

				if (player_Zata.swordSprite.aniIterator != player_Zata.rightSwordAnim.aniEnd)
				{
					player_Zata.swordSprite.aniIterator += 1;
				}
				else
				{
					player_Zata.swordSprite.aniIterator = player_Zata.rightSwordAnim.aniStart;
				}
			}
		}


		if (Direction == 0)
		{
			if (gameTime.m_timer >= 0.02f)
			{
				gameTime.m_timer = 0.0f;

				if (player_Zata.swordSprite.aniIterator != player_Zata.leftSwordAnim.aniEnd)
				{
					player_Zata.swordSprite.aniIterator += 1;
				}
				else
				{
					player_Zata.swordSprite.aniIterator = player_Zata.leftSwordAnim.aniStart;
				}
			}

		}


		if (Direction == 3)
		{
			if (gameTime.m_timer >= 0.02f)
			{
				gameTime.m_timer = 0.0f;

				if (player_Zata.swordSprite.aniIterator != player_Zata.rightSwordAnim.aniEnd)
				{
					player_Zata.swordSprite.aniIterator += 1;
				}
				else
				{
					player_Zata.swordSprite.aniIterator = player_Zata.rightSwordAnim.aniStart;
				}
			}
		}
	}
}


void Game::PlayerAnim(int direction)
{

	if (direction == 0)
	{
		if (gameTime.m_timer >= 0.02f)
		{
			gameTime.m_timer = 0.0f;

			if (once1 != 1)
			{
				player_Zata.sprite.aniIterator = player_Zata.forwardAnim.aniStart;
				once1++;
			}

			if (player_Zata.sprite.aniIterator < player_Zata.forwardAnim.aniEnd - 1)
			{
				player_Zata.sprite.aniIterator++;
			}
			else
			{
				player_Zata.sprite.aniIterator = player_Zata.forwardAnim.aniStart;
				once1 = 0;
			}
		}
	}

	if (direction == 1)
	{
		if (gameTime.m_timer >= 0.02f)
		{
			gameTime.m_timer = 0.0f;

			if (once2 != 1)
			{
				player_Zata.sprite.aniIterator = player_Zata.leftAnim.aniStart;
				once2++;
			}

			if (player_Zata.sprite.aniIterator < player_Zata.leftAnim.aniEnd - 1)
			{
				player_Zata.sprite.aniIterator++;
			}
			else
			{
				player_Zata.sprite.aniIterator = player_Zata.leftAnim.aniStart;
				once2 = 0;
			}
		}
	}

	if (direction == 2)
	{
		if (gameTime.m_timer >= 0.02f)
		{
			gameTime.m_timer = 0.0f;

			if (once3 != 1)
			{
				player_Zata.sprite.aniIterator = player_Zata.rightAnim.aniStart;
				once3++;
			}
			if (player_Zata.sprite.aniIterator < player_Zata.rightAnim.aniEnd - 1)
			{
				player_Zata.sprite.aniIterator++;
			}
			else
			{
				player_Zata.sprite.aniIterator = player_Zata.rightAnim.aniStart;
				once3 = 0;
			}
		}
	}

	if (direction == 3)
	{
		if (gameTime.m_timer >= 0.02f)
		{
			gameTime.m_timer = 0.0f;

			if (once4 != 1)
			{
				player_Zata.sprite.aniIterator = player_Zata.backAnim.aniStart;
				once4++;
			}

			if (player_Zata.sprite.aniIterator < player_Zata.backAnim.aniEnd - 1)
			{
				player_Zata.sprite.aniIterator++;
			}
			else
			{
				player_Zata.sprite.aniIterator = player_Zata.backAnim.aniStart;
				once4 = 0;

			}
		}
	}
}

void Game::EnemyStateMonitor()
{
	if (enemy1.health <= 0)
	{
		enemy1.Die();
	}

	if (enemy2.health <= 0)
	{
		enemy2.Die();
	}

	if (enemy3.health <= 0)
	{
		enemy3.Die();
	}
}


void Game::WinCondition()
{

	if (enemy1.alive == false && enemy2.alive == false && enemy3.alive == false)
	{
		win = true;
		gameOver = true;
	}
	if (playerDead == true)
	{

		win = false;
		gameOver = true;

	}

}



void Game::UpdateActorCollsionBoxes()
{
	player_Zata.UpdateCollsionBox();
	enemy1.UpdateCollsionBox();
	enemy2.UpdateCollsionBox();
	enemy3.UpdateCollsionBox();
}


void Game::GameUi()
{
	string playerHealth = "health:" + to_string(player_Zata.health);
	DrawText(playerHealth.c_str(), 0, 200, 100, RED);

	if (gameOver == true)
	{

		if (win == true)
		{
			DrawText("Quest Complete", GetScreenWidth() / 2 - 550, GetScreenHeight() / 2 - 100, 150, BLUE);
			gameOn = false;


		}
		else
		{
			DrawText("Game Over", GetScreenHeight() / 2 - 550, GetScreenHeight() / 2 - 100, 150, RED);
			gameOn = false;

		}


	}

}

void Game::playerStateMonitor()
{
	if (player_Zata.health <= 0)
	{
		player_Zata.health = 0;
		player_Zata.Die();
		playerDead = true;
	}

}

void Game::PlayerEnemyCollision()//worst way i couldve done  this 
{
//	DrawBoundingBox(player_Zata.actorCollisionBox, RED);
	//DrawBoundingBox(enemy1.actorCollisionBox, RED);
	//DrawBoundingBox(enemy2.actorCollisionBox, RED);	DrawBoundingBox(enemy3.actorCollisionBox, RED);

	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy1.actorCollisionBox) && slash == false)
	{
		player_Zata.health--;
	}
	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy1.actorCollisionBox) && slash == true)
	{
		enemy1.health--;
	}

	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy2.actorCollisionBox) && slash == false)
	{
		player_Zata.health--;
	}


	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy2.actorCollisionBox) && slash == true)
	{
		enemy2.health--;
	}


	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy3.actorCollisionBox) && slash == false)
	{
		player_Zata.health--;
	}


	if (CheckCollisionBoxes(player_Zata.actorCollisionBox, enemy3.actorCollisionBox) && slash == true)
	{
		enemy3.health--;
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);



	
	GameMap.DrawMap();
	ChoosePlayerDrawType(forward);
	PlayerEnemyCollision();
	enemy1.Draw();
	enemy2.Draw();
	enemy3.Draw();

	GameUi();
	EndDrawing();
}

Game::Timer::Timer()
{


}
Game::Timer::~Timer()
{


}

float Game::Timer::GetDeltaTime()
{
	deltaTime = GetFrameTime();
	return deltaTime;
}



