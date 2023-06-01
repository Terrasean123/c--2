#include "Tile.h"
#include "Map.h "
//Tile::Tile()
//{
// 
//}

Tile::Tile(Map* mapRef)
{
	this->mapRef = mapRef;
	currentSprite = &this->mapRef->debugSprite;
	this->AddChild(currentSprite);
}

Tile::~Tile()
{

}