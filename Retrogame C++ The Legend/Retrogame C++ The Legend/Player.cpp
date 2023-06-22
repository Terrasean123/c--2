#include "Player.h"

Player::Player()
{
	AddChild(&sprite);
	//SetPosition(-sprite.GetWidth() / 2.0f, sprite.GetWidth() / 2.0f);
	SetPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
	sprite.animated = true;
	sprite.individualSpriteHeight = 23;
	sprite.individualSpriteWidth = 16;
	sprite.spriteScale = 5;
	actorSpeed = 250;
	actorMaxSpeed = 300;
	forwardAnim.aniStart = 30; forwardAnim.aniEnd = 39;
	backAnim.aniStart = 0; backAnim.aniEnd = 9;
	leftAnim.aniStart = 10; leftAnim.aniEnd = 19;
	rightAnim.aniStart = 20; rightAnim.aniEnd = 29;

	leftSwordAnim.aniStart = 0;
	leftSwordAnim.aniEnd = 6;
	rightSwordAnim.aniStart = 7;
	rightSwordAnim.aniEnd = 13;


	//sword stuff

	swordSprite.Load("../../SpriteFolder/SwordSlashSpriteSheet-0001.png");
	AddChild(&swordObject);
	swordSprite.individualSpriteHeight = 41;
	swordSprite.individualSpriteWidth = 41;
	swordSprite.spriteScale = 3.5;
	swordObject.AddChild(&swordSprite);
	swordSprite.SetPosition(0, 0);

	swordSprite.animated = true;
	swordSprite.aniIterator = 0;
	UpdateTransform();
	swordSprite.rotation = SwordRotation(1);
	//swordSlashSprite.Load("../../SpriteFolder/SwordSlashSpriteSheet-0001.png");


}


float Player::SwordRotation(int rotation)
{
	float rot = 0;
	switch (rotation)
	{
	case 90:
		//right

		swordSprite.SetPosition(-60, 0);
		break;

	case 180:

		//down
		rot = 180;
		swordSprite.SetPosition(100, 150);
		break;

	case 270:
		//left
		//rot = 270;
		swordSprite.SetPosition(0, 0);

		break;

	case 360:
		//up
		//rot = 360;
		swordSprite.SetPosition(-10, -60);
		break;

	}

	return rot;
}



void Player::Die()
{
	swordSprite = SpriteObject();
	sprite = SpriteObject();
	alive = false;
}

Player::~Player()
{




}