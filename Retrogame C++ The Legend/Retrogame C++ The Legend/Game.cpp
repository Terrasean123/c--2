#include "Game.h"


Game::Game()
{

}

void Game::init()
{
	player_Zata.sprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/ ZataSprite-0001.png");
	player_Zata.sprite.SetPosition(-player_Zata.sprite.GetWidth() / 2.0f, player_Zata.sprite.GetWidth() / 2.0f);

	player_Zata.AddChild(player_Zata.sprite);
}


void  Game::debug()
{


}

void Game::Update()
{


}


void Game::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	//DrawText("Legend of Fractalia ", 190, 200, 300, RED);

	player_Zata.Draw();

	EndDrawing();


}