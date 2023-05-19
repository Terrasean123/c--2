#include "Map.h"


void Map::CreateMap()
{

	for (int i = 0; i < TileMapMax; i++)
	{
		Tile tile;
		tile.debugSprite.Load("L:\C++ introduction project\c--2\Retrogame C++ The Legend\SpriteFolder\DebugTileSprite-0001.png");
		tileMap.push_back(tile);
	}

}

void Map::CreateMap()
{
	for (int i = 0; i < TileMapMax; i++)
	{

		tileMap[i].globalPosition.x + tileMap[i].debugSprite.GetWidth()* increaser;

	
	}

}
