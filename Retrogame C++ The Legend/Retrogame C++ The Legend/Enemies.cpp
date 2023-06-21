
#include "Enemies.h"

Enemies::Enemies()
{
	sprite.Load("../../SpriteFolder/SquidEnemySprite-0001.png");
	sprite.spriteScale = 5;
	AddChild(&sprite);
	SetPosition(-sprite.GetWidth() / 2.0f, sprite.GetWidth() / 2.0f);
	SetPosition(GetScreenWidth() / 2+200, GetScreenHeight() / 2);
	sprite.animated = false;
	sprite.individualSpriteHeight = 20;
	sprite.individualSpriteWidth = 20;
	sprite.spriteScale = 5;
	actorSpeed = 120;
	actorMaxSpeed = 200;
}

void Enemies::ActorBehaviour()
{
	


}

void Enemies::Die()
{
	sprite = SpriteObject();
	alive = false;
}
void Enemies::FollowBehaviour(Vector2 playerVec,float deltaTime)
{
	AIMove(deltaTime, playerVec);
}

Enemies::~Enemies()
{
	//delete this;

}