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

// might be worth making sprite index a parameter
SpriteObject& Tile::Chooser()
{
	switch (spriteIndex)
	{
	case 0:
		return this->mapRef->debugSprite;
		break;
	case 1:
		return this->mapRef->GrassSprite;
		break;
	case 2:
		return this->mapRef->GroundSprite;
		break;
	case 3:
		return this->mapRef->TreeSprite;
		break;
	case 4:
		return this->mapRef->WaterSprite;
		break;
	case 5:
		return this->mapRef->StoneSprite;
		break;

	}

}



// REQUIRES SPRITE INDEX INVOLVEMENT
void Tile::UpdateTileSprite()
{
	currentSprite = &Chooser();
}



Tile::~Tile()
{

}