#include "Map.h"

Map::Map()
{
	debugSprite.Load("../../SpriteFolder/DebugTileSprite-0001.png");
	GrassSprite.Load("../../SpriteFolder/GrassSprite-0001.png");
	GroundSprite.Load("../../SpriteFolder/DirtPathSprite-0001.png");
	tileWidth = debugSprite.GetWidth();
	tileHeight = debugSprite.GetHeight();
}

Map::~Map()
{


}




void Map::CreateMap()
{



	/// <summary>
	/// whilst indexing in this way is certainly wierd  i noticed that as an integer the calculations didnt account for the fact that there
	/// is an uneven amount of space between the screen and  the previous tile meaning there would be no half tiles to cover the screen completely
	/// i have decided to keeep them as floats for now so that it covers the screen completely a little bit of tile outspill is no issue  becuase a majority
	///  of the old zelda games seem to carry the same issue/feature
	/// </summary>
	float widthNumber = m_windowWidth / (tileWidth * tileScale) + 1;
	float heightNumber = m_windowHeight / (tileHeight * tileScale);

	std::cout << widthNumber * heightNumber << std::endl;
	tileMap.reserve(widthNumber * heightNumber);


	//std::cout << "COL:" << widthNumber << std::endl;	std::cout << "ROW:" << heightNumber << std::endl;
	for (int rowID = 0; rowID < heightNumber; rowID++)
	{
		for (int colID = 0; colID < widthNumber; colID++)
		{
			tileMap.emplace_back(this);
			float  xpos = colID * tileWidth * tileScale;
			float ypos = rowID * tileHeight * tileScale;
			Tile& tile = tileMap.back();
			tile.globalPosition.x = xpos;
			tile.globalPosition.y = ypos;
		}
	}

}

void Map::DrawMap()
{

	for (int i = 0; i < tileMap.size() - 1; i++)
	{
		Vector2 vec2 = Vector2{ tileMap[i].globalPosition.x,tileMap[i].globalPosition.y };
		DrawTextureEx(tileMap[i].currentSprite->texture, vec2, 0, tileScale, WHITE);
	}
}


void Map::ManageTiles(bool creatormode)
{

	float widthNumber = m_windowWidth / (tileWidth * tileScale);
	float heightNumber = m_windowHeight / (tileHeight * tileScale);
	Vector2 mousePos = GetMousePosition();



	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		int rowIndex = mousePos.y / (tileWidth * tileScale);
		int colIndex = mousePos.x / (tileHeight * tileScale);
		std::cout << "Row:" << rowIndex << std::endl; std::cout << "Col:" << colIndex << std::endl;

		int tileIndex = rowIndex * heightNumber + colIndex;
		std::cout << tileIndex << std::endl;

		if (creatormode == true)
		{
			tileMap[tileIndex].spriteIndex += 1;
			if (tileMap[tileIndex].spriteIndex >= 5)
				tileMap[tileIndex].spriteIndex = 0;
			std::cout << "tilesprite index" << tileMap[tileIndex].spriteIndex << std::endl;
		tileMap[tileIndex].UpdateTileSprite();

		}

	}



}