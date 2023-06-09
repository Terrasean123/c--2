#include "Actor.h"

Actor::Actor()
{

}


Actor::~Actor()
{

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



void Actor::Die()
{

}
void Actor::ActorBehaviour()
{

}
