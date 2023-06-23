#include "Actor.h"

Actor::Actor()
{
	actorattackCollisonBox.min.x = 0 + globalPosition.x;
	actorattackCollisonBox.min.y = 0 + globalPosition.y;
	actorattackCollisonBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x;
	actorattackCollisonBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y;
	actorattackCollisonBox.min.z = 0;
	actorattackCollisonBox.min.z = 0;
	actorattackCollisonBox.max.z = 0;
	actorattackCollisonBox.max.z = 0;

	actorBodyCollisonBox.min.x = globalPosition.x;
	actorBodyCollisonBox.min.y = globalPosition.y;
	actorBodyCollisonBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x;
	actorBodyCollisonBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y;
	actorBodyCollisonBox.min.z = 0;
	actorBodyCollisonBox.min.z = 0;
	actorBodyCollisonBox.max.z = 0;
	actorBodyCollisonBox.max.z = 0;
}


Actor::~Actor()
{

}


void Actor::UpdateCollsionBox()
{
	actorattackCollisonBox.min.x = globalPosition.x + min_Xextender;
	actorattackCollisonBox.min.y = globalPosition.y + min_Yextender;
	actorattackCollisonBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x + max_Xextender;
	actorattackCollisonBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y + max_Yextender;
	actorattackCollisonBox.min.z = 0;
	actorattackCollisonBox.min.z = 0;
	actorattackCollisonBox.max.z = 0;
	actorattackCollisonBox.max.z = 0;


	actorBodyCollisonBox.min.x = globalPosition.x;
	actorBodyCollisonBox.min.y = globalPosition.y;
	actorBodyCollisonBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x;
	actorBodyCollisonBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y;
	actorBodyCollisonBox.min.z = 0;
	actorBodyCollisonBox.min.z = 0;
	actorBodyCollisonBox.max.z = 0;
	actorBodyCollisonBox.max.z = 0;

}


void Actor::Move(float deltaTime, bool Vertical)// false for vertical;true for horizontal
{
	float movedDistance = this->actorSpeed * deltaTime;
	if (Vertical == true)
	{
		this->globalPosition.y = this->globalPosition.y + movedDistance;
	}
	else
	{
		this->globalPosition.x = this->globalPosition.x + movedDistance;
	}

	SetPosition(this->globalPosition.x, this->globalPosition.y);
}

void Actor::AIMove(float deltaTime, Vector2 locVec)// false for vertical;true for horizontal
{
	float movedDistance = this->actorSpeed * deltaTime;


	if (locVec.x < this->globalPosition.x)
	{
		this->globalPosition.x = this->globalPosition.x - movedDistance;
	}

	if (locVec.y < this->globalPosition.y)
	{
		this->globalPosition.y = this->globalPosition.y - movedDistance;
	}

	if (locVec.x > this->globalPosition.x)
	{
		this->globalPosition.x = this->globalPosition.x + movedDistance;
	}

	if (locVec.y > this->globalPosition.y)
	{
		this->globalPosition.y = this->globalPosition.y + movedDistance;
	}

	SetPosition(this->globalPosition.x, this->globalPosition.y);
}




void Actor::Die()
{

}
void Actor::ActorBehaviour()
{

}
