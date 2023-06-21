#include "Actor.h"

Actor::Actor()
{
	actorCollisionBox.min.x = 0 + globalPosition.x;
	actorCollisionBox.min.y = 0 + globalPosition.y;
	actorCollisionBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x;
	actorCollisionBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y;
	actorCollisionBox.min.z = 0;
	actorCollisionBox.min.z = 0;
	actorCollisionBox.max.z = 0;
	actorCollisionBox.max.z = 0;
}


Actor::~Actor()
{

}


void Actor::UpdateCollsionBox()
{
	actorCollisionBox.min.x = globalPosition.x + min_Xextender;
	actorCollisionBox.min.y = globalPosition.y + min_Yextender;
	actorCollisionBox.max.x = (sprite.individualSpriteWidth) * sprite.spriteScale + globalPosition.x + max_Xextender;
	actorCollisionBox.max.y = (sprite.individualSpriteHeight) * sprite.spriteScale + globalPosition.y + max_Yextender;
	actorCollisionBox.min.z = 0;
	actorCollisionBox.min.z = 0;
	actorCollisionBox.max.z = 0;
	actorCollisionBox.max.z = 0;

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
