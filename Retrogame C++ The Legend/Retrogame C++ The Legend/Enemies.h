#pragma once
#include "actor.h"

class Enemies :  public Actor
{
public:

	Enemies();
	~Enemies();
 void ActorBehaviour() override;

 void FollowBehaviour(Vector2 playerVec,float deltaTime);


};

