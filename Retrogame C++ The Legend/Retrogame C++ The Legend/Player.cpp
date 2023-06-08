#include "Player.h"

Player::Player()
{
	AddChild(&sprite);
	SetPosition(-sprite.GetWidth() / 2.0f, sprite.GetWidth() / 2.0f);
	SetPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
	sprite.spriteScale = 5;
	actorSpeed = 250;
	actorMaxSpeed = 300;

	//sword stuff

	swordSprite.Load("../../SpriteFolder/WoodenSword-0001.png");
	AddChild(&swordObject);
	swordObject.AddChild(&swordSprite);
	swordSprite.spriteScale = 4;
	swordObject.SetPosition(-sprite.GetWidth() / 2.0f, sprite.GetWidth() / 2.0f);
	UpdateTransform();
	swordSprite.rotation = SwordRotation(270);
}


float Player::SwordRotation(int rotation)
{
	float rot = 0;
	switch (rotation)
	{
	case 90:
		//right
		rot = 90;
		swordSprite.Translate(130,30);
		break;

	case 180:

		//down
		rot = 180;
		swordSprite.Translate(105,150);
		break;

	case 270:
		//left
		rot = 270;
		swordSprite.Translate(-40, 100);

		break;

	case 360:
		//up
		rot = 360;
		swordSprite.SetPosition(30,-50);
		break;

	}

	return rot;
}

Player::~Player()
{




}