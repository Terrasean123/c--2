#pragma once
#include "SceneObject.h"
#include "SpriteObject.h"
//#include "Map.h"

class Map;

class Tile :public SceneObject
{
public:
	Map* mapRef;
	SpriteObject* currentSprite;
	//Tile();
	SpriteObject& Chooser();
	int spriteIndex = 1;
	void UpdateTileSprite();
	Tile(Map* mapRef);
	~Tile();

};

