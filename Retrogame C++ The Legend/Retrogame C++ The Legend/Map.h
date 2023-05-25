#pragma once
#include "Tile.h"
#include "vector"
class Map
{
public:
	int increaser = 0;
	int TileMapMax = 100;
	std::vector<Tile> tileMap;

	void CreateMap(int ScreenWidth,int ScreenHeigth);
		void DrawMap();

};

