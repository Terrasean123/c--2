#include "SpriteObject.h"


void SpriteObject::Load(std::string filename)
{
    image = LoadImage(filename.c_str());
    texture = LoadTextureFromImage(image);

}