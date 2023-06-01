#include "Map.h"

Map::Map()
{
	debugSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/DebugTileSprite-0001.png");
	tileWidth = debugSprite.GetWidth();
	tileHeight = debugSprite.GetHeight();
}

Map::~Map()
{


}


void Map::CreateMap()
{

	float scale = 5;

	float widthNumber = m_windowWidth / (tileWidth * scale);
	float heightNumber = m_windowHeight / (tileHeight * scale);

	for (int rowID = 0; rowID < heightNumber; rowID++)
	{
		for (int colID = 0; colID < widthNumber; colID++)
		{
			float  xpos = colID * tileWidth * scale;
			float ypos = rowID * tileHeight * scale;
			Tile tile = Tile(this);
			tile.globalPosition.x = xpos/* + scale*/;
			tile.globalPosition.y = ypos + scale+5;
			Vector2 vec2 = Vector2{ tile.globalPosition.x,tile.globalPosition.y };
			DrawTextureEx(tile.currentSprite->texture, vec2, 0, scale, WHITE);
		}
	}

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
			Tile tile = Tile(this);
			tile.globalPosition.x = xpos;
			tile.globalPosition.y = ypos;
			Vector2 vec2 = Vector2{ tile.globalPosition.x,tile.globalPosition.y };
			DrawTextureEx(tile.currentSprite->texture, vec2, 0, 1, WHITE);

		}

	}
}
