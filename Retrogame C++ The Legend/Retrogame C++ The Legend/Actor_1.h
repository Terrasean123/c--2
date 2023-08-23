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
	float actorSpeed = 100;
	float actorAnimSpeed = 1;
	float actorMaxSpeed = 5;
	bool alive = true;
	BoundingBox actorattackCollisonBox;
	BoundingBox actorBodyCollisonBox;
	int max_Xextender = 0;
	int max_Yextender = 0;
	int min_Xextender = 0;
	int min_Yextender = 0;


	void AIMove(float DeltaTime, Vector2 locVec);
	void UpdateCollsionBox();

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
