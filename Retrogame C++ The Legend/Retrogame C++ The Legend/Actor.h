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
	float actorSpeed = 0;
	float actorMaxSpeed;
	void Move(float DeltaTime, bool Vertical);
	virtual void Die();
	virtual void ActorBehaviour();
	Actor();
	~Actor();
};

