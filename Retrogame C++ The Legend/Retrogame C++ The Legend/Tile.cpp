#include "Tile.h"
#include "Map.h "
//Tile::Tile()
//{
// 
//}

Tile::Tile(Map* mapRef)
{
	this->mapRef = mapRef;
	currentSprite = &Chooser();
	this->AddChild(currentSprite);
}

SpriteObject& Tile::Chooser()
{
	switch (spriteIndex)
	{
	case 0:
		return this->mapRef->debugSprite;
	case 1:
		return this->mapRef->GrassSprite;
	case 2:
		return this->mapRef->GroundSprite;
	case 3:
		return this->mapRef->TreeSprite;
	case 4:
		return this->mapRef->WaterSprite;
	case 5:
		return this->mapRef->StoneSprite;

	}

}

void Tile::UpdateTileSprite()
{
	currentSprite = &Chooser();
}



Tile::~Tile()
{

}