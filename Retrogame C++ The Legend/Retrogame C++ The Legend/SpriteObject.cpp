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
		/*Rectangle spriteFrame = Rectangle();
		spriteFrame.width = individualSpriteWidth;
		spriteFrame.height = individualSpriteHeight;
		spriteFrame.y = individualSpriteHeight * aniIterator;
		Rectangle DestinationRect = Rectangle();
		DestinationRect.height = (spriteFrame.height)*spriteScale;
		DestinationRect.width = (spriteFrame.width)*spriteScale;*/

		Rectangle spriteFrame = Rectangle();
		spriteFrame.width = individualSpriteWidth;
		spriteFrame.height = individualSpriteHeight;
		spriteFrame.y = individualSpriteHeight * aniIterator;
		Rectangle DestinationRect = Rectangle();
		DestinationRect.height= individualSpriteWidth*spriteScale ; 
		DestinationRect.width = individualSpriteHeight* spriteScale ;

		//DrawTexturePro(texture, spriteFrame, DestinationRect, ConvertGlmVec(-globalPosition), rotation, Tint);
		DrawTexturePro(texture, spriteFrame, DestinationRect, Vector2{,1}, rotation, Tint);
	}
}
