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
	Tile(Map* mapRef);
	~Tile();

};

