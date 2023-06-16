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
	int health = 100;
	
	SceneObject swordObject;
	SpriteObject swordSprite;

	animationRange forwardAnim;
	animationRange backAnim;
	animationRange rightAnim;
	animationRange leftAnim;

	animationRange leftSwordAnim;

	animationRange rightSwordAnim;

	float SwordRotation(int rotationIterator);
	void Die()override;
};

