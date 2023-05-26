#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "SceneObject.h"
#include "string"
class SpriteObject : public SceneObject
{
public:
	Texture2D texture;
	Image image;

	void Load(std::string filename);


	float GetWidth()
	{
		return texture.width;
	}
	float GetHeight()
	{
		return texture.height;
	}
	SpriteObject()
	{

	}
	~SpriteObject()
	{

	}

	void OnDraw()override;



};

