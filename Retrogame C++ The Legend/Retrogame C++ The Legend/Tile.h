#pragma once
#include "SceneObject.h"
#include "SpriteObject.h"
#include "map.h"


class Tile :public SceneObject
{
public:
	Map *mapRef = nullptr;
	SpriteObject* currentSprite= nullptr;
	Tile();
	Tile(Map& mapRef);
	~Tile();

};

