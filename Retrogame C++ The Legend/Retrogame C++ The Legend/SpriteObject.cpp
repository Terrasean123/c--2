#include "SpriteObject.h"
#include "SceneObject.h"

#include <iostream>


void SpriteObject::Load(std::string filename)
{
	image = LoadImage(filename.c_str());
	std::cout << "IMAGE lOADED " << std::endl;

	texture = LoadTextureFromImage(image);
	std::cout << "Texture Loaded" << std::endl;
	UnloadImage(image);
}

void SpriteObject::OnDraw()
{
	if (animated == false)
	{
		DrawTextureEx(texture, ConvertGlmVec(globalPosition), this->rotation, spriteScale, Tint);
	}
	else
	{
		Rectangle spriteFrame = Rectangle();
		spriteFrame.width = individualSpriteWidth;
		spriteFrame.height = individualSpriteHeight;
		spriteFrame.y = individualSpriteHeight * aniIterator;
		spriteFrame.x = 0;
		Rectangle DestinationRect = Rectangle();
		DestinationRect.height = individualSpriteHeight * spriteScale;
		DestinationRect.width = individualSpriteWidth * spriteScale;
		DestinationRect.x = globalPosition.x;
		DestinationRect.y = globalPosition.y;


		DrawTexturePro(texture, spriteFrame, DestinationRect, Vector2{ 0,0 }, rotation, Tint);
	}
}
