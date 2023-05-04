#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
class SceneObject
{
   public: 
	   virtual void Draw();
	   glm::vec2 Position;

};

