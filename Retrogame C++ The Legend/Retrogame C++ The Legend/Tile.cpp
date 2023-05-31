#include "Tile.h"
#include "Map.h "
//Tile::Tile()
//{
// 
//}

Tile::Tile(Map* mapRef)
{
	currentSprite = &mapRef->debugSprite;
	this->AddChild(currentSprite);
}

Tile::~Tile()
{
	
}