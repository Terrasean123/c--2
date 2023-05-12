#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Player.h"
#include "SceneObject.h"
#include "SpriteObject.h"
#include "Actor.h"

class Game
{
private:

	long currentTime = 0;
	long lastTime = 0;
	float Timer = 0;
	int fps = 1;
	int frames = 0;
	float m_timer = 0;
	float deltaTime = 0.005f;
	int previousCount = 0;
public:
	float time = GetFrameTime();
	Player player_Zata;
	
	Camera2D camera = Camera2D();

	Game();
	void init();
	void debug();
	void Update();
	void Draw();

};



