#include "Map.h"

Map::Map()
{
	debugSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/DebugTileSprite-0001.png");

}

Map::~Map()
{


}


void Map::CreateMap(int ScreenWidth, int ScreeHeigth)
{

	/*for (int i = 0; i < TileMapMax; i++)
	{
		Tile tile = Tile();
		tile.debugSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/DebugTileSprite-0001.png");
		tileMap.push_back(tile);
	}*/

}

void Map::DrawMap()
{
	for (int rowid = 0; rowid < ROWS; rowid++)
	{
		for (int colid = 0; colid < COLS; colid++)
		{
			float  xpos = colid * tileWidth;
			float ypos = rowid * tileHeight;
			int index = rowid * COLS + colid;
			Tile tile = Tile(*this);
			tile.globalPosition.x = xpos /**m_windowWidth*/;
			tile.globalPosition.y = ypos/* *m_windowHeight*/;
			Vector2 vec2 = Vector2{ tile.globalPosition.x,tile.globalPosition.y };
			DrawTextureEx(tile.currentSprite->texture, vec2, 0, 1, WHITE);

		}

	}
}
