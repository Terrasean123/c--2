#include "SpriteObject.h"
#include "SceneObject.h"

void SpriteObject::Load(std::string filename)
{
    image = LoadImage(filename.c_str());
    texture = LoadTextureFromImage(image);

}

void SpriteObject::OnDraw() 
{
    DrawTextureEx(texture,ConvertGlmVec(globalPosition),90,100,WHITE );
}
