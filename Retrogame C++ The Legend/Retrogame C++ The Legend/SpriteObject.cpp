#include "SpriteObject.h"
#include "SceneObject.h"

#include <iostream>

void SpriteObject::Load(std::string filename)
{
    image = LoadImage(filename.c_str());
    texture = LoadTextureFromImage(image);

}

void SpriteObject::OnDraw() 
{
    DrawTextureEx(texture,ConvertGlmVec(globalPosition),0,10,WHITE );


}
