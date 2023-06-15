#pragma once
#include "raylib.h"
#include "raylib.hpp"
//#include "glm/glm.hpp"
#include "SceneObject.h"
#include "SpriteObject.h"
class Actor :public SceneObject
{
public:
	SpriteObject sprite;
	float actorSpeed = 1;
	float actorAnimSpeed = 1;
	float actorMaxSpeed = 5;
	void AIMove(float DeltaTime, Vector2 locVec);

	void Move(float DeltaTime, bool Vertical);
	virtual void Die();
	virtual void ActorBehaviour();

	struct animationRange 
	{
		int aniStart;
		int aniEnd;
	};

	Actor();
	~Actor();
};

