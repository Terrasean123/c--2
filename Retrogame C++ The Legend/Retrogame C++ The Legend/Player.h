#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Actor.h"
class Player:public Actor
{
public:
	Player();
	~Player();
	
	SceneObject swordObject;
	SpriteObject swordSprite;

	float SwordRotation(int rotationIterator);


};

