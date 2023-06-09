#include "Player.h"

Player::Player()
{
	AddChild(&sprite);
	SetPosition(-sprite.GetWidth() / 2.0f, sprite.GetWidth() / 2.0f);
	SetPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
	sprite.nonActor = false;
	sprite.individualSpriteHeight = 23;
	sprite.individualSpriteWidth = 16;
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
	swordSprite.rotation = SwordRotation(180);

	forwardAnim.aniStart = 30; forwardAnim.aniEnd = 39;
	backAnim.aniStart = 1;backAnim.aniEnd = 9; 
	leftAnim.aniStart = 10;leftAnim.aniEnd =19 ;
	rightAnim.aniStart = 20 ;rightAnim.aniEnd =29;
	

}


float Player::SwordRotation(int rotation)
{
	float rot = 0;
	switch (rotation)
	{
	case 90:
		//right
		rot = 90;
		swordSprite.SetPosition(150,25);
		break;

	case 180:

		//down
		rot = 180;
		swordSprite.SetPosition(110,150);
		break;

	case 270:
		//left
		rot = 270;
		swordSprite.SetPosition(-60,100);

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