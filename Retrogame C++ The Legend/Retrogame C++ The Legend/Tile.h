#pragma once
#include "SceneObject.h"
#include "SpriteObject.h"


class Tile :public SceneObject
{
public:
  SpriteObject debugSprite;
  SpriteObject GrassSprite;
  SpriteObject GroundSprite;
  SpriteObject StoneSprite;
  SpriteObject WaterSprite;
  SpriteObject TreeSprite;

  

};

