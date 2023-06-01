#pragma once
#include "Tile.h"
#include "vector"
class Map
{
public:

	int m_windowHeight = 1080;
	int m_windowWidth = 1980;

	static const int COLS = 10;
	static const int ROWS = 10;
	SpriteObject debugSprite;
	SpriteObject GrassSprite;
	SpriteObject GroundSprite;
	SpriteObject StoneSprite;
	SpriteObject WaterSprite;
	SpriteObject TreeSprite;
	//std::vector<Tile> tileMap;
	int TileMap[ROWS * COLS];
	Map();
	~Map();
	int tileWidth;
	int tileHeight;

	void CreateMap();
	void DrawMap();

};

