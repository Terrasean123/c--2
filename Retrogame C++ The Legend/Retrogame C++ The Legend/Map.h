#pragma once
#include "Tile.h"
#include "vector"
#include <iostream>
class Map
{
public:

	int m_windowHeight = 1080;
	int m_windowWidth = 1920;

	SpriteObject debugSprite;
	SpriteObject GrassSprite;
	SpriteObject GroundSprite;
	SpriteObject StoneSprite;
	SpriteObject WaterSprite;
	SpriteObject TreeSprite;
	std::vector<Tile*> tileMap;

	Map();
	~Map();
	int tileWidth;
	int tileHeight;
	float tileScale = 5;
	bool Creatormode = false;

	void CreateMap();
	void DrawMap();
	void ManageTiles();

};

