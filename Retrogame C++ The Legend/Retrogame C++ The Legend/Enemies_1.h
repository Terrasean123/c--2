#pragma once
#include "actor.h"

class Enemies :  public Actor
{
public:

	Enemies();
	~Enemies();
	int health = 100;
	void Die()override;
 void ActorBehaviour() override;

 void FollowBehaviour(Vector2 playerVec,float deltaTime);


};

