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
	static SpriteObject debugSprite;
	static SpriteObject GrassSprite;
	static SpriteObject GroundSprite;
	static SpriteObject StoneSprite;
	static SpriteObject WaterSprite;
	static SpriteObject TreeSprite;
	//std::vector<Tile> tileMap;
	int TileMap[ROWS * COLS];
	Map();
	~Map();
	int tileWidth = debugSprite.GetWidth();
	int tileHeight = debugSprite.GetHeight();

	void CreateMap(int ScreenWidth, int ScreenHeigth);
	void DrawMap();

};

