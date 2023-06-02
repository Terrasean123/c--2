#include "Map.h"

Map::Map()
{
	debugSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/DebugTileSprite-0001.png");
	GrassSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/GrassSprite-0001.png");
	GroundSprite.Load("L:/C++ introduction project/c--2/Retrogame C++ The Legend/SpriteFolder/DirtPathSprite-0001.png");
	tileWidth = debugSprite.GetWidth();
	tileHeight = debugSprite.GetHeight();
	Creatormode = true;
}

Map::~Map()
{


}




void Map::CreateMap()
{
	float widthNumber = m_windowWidth / (tileWidth * tileScale);
	float heightNumber = m_windowHeight / (tileHeight * tileScale);

	//std::cout << "COL:" << widthNumber << std::endl;	std::cout << "ROW:" << heightNumber << std::endl;
	for (int rowID = 0; rowID < heightNumber; rowID++)
	{
		for (int colID = 0; colID < widthNumber; colID++)
		{
			float  xpos = colID * tileWidth * tileScale;
			float ypos = rowID * tileHeight * tileScale;
			Tile tile = Tile(this);
			tile.globalPosition.x = xpos;
			tile.globalPosition.y = ypos;
			Vector2 vec2 = Vector2{ tile.globalPosition.x,tile.globalPosition.y };
			tileMap.push_back(&tile);
			DrawTextureEx(tile.currentSprite->texture, vec2, 0, tileScale, WHITE);
		}
	}

}

void Map::ManageTiles()
{

	float widthNumber = m_windowWidth / (tileWidth * tileScale);
	float heightNumber = m_windowHeight / (tileHeight * tileScale);
	Vector2 mousePos = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		int rowIndex = mousePos.y / (tileWidth * tileScale);
		int colIndex = mousePos.x / (tileHeight * tileScale);
		std::cout <<"Row:" << rowIndex << std::endl; std::cout << "Col:" << colIndex << std::endl;

		int tileIndex = rowIndex * heightNumber + colIndex;
		std::cout << tileIndex << std::endl;
		tileMap[tileIndex]->spriteIndex += 1;
		if (tileMap[tileIndex]->spriteIndex >= 5)
			tileMap[tileIndex]->spriteIndex = 0;

	}

	for (Tile* tiles : tileMap)
	{
		tiles->UpdateTileSprite();
		//std::cout << tiles->spriteIndex << std::endl;
	}


}


//
//void Map::DrawMap()
//{
//	for (int rowid = 0; rowid < ROWS; rowid++)
//	{
//		for (int colid = 0; colid < COLS; colid++)
//		{
//			float  xpos = colid * tileWidth;
//			float ypos = rowid * tileHeight;
//			int index = rowid * COLS + colid;
//			Tile tile = Tile(this);
//			tile.globalPosition.x = xpos;
//			tile.globalPosition.y = ypos;
//			Vector2 vec2 = Vector2{ tile.globalPosition.x,tile.globalPosition.y };
//			DrawTextureEx(tile.currentSprite->texture, vec2, 0, 1, WHITE);
//
//		}
//
//	}
//}
