#pragma once
#include "raylib.h"
#include "raylib.hpp"
//#include "glm/glm.hpp"
#include "SceneObject.h"
#include "SpriteObject.h"
class Actor:public SceneObject
{
public:
	SpriteObject sprite;
	virtual void Die();
	virtual void ActorBehaviour();

};

