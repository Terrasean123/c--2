#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "SceneObject.h"
#include "string"
class SpriteObject : public SceneObject
{
public:
	Texture2D texture = Texture2D();
	Image image = Image();

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

	void OnDraw();



};

