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
    DrawTextureEx(texture, ConvertGlmVec(globalPosition), 0, 10, WHITE);


}
