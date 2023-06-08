#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Player.h"
#include "SceneObject.h"
#include "SpriteObject.h"
#include "Actor.h"
#include "Map.h"
#include <chrono>
#include <ctime>
using namespace std::chrono;
using namespace std;

class Game
{
private:
	Map GameMap = Map();

public:


	Player player_Zata;

	Camera2D camera = Camera2D();

	Game();
	~Game();
	void init();
	void debug(bool debugging);
	void Update();
	void Draw();
	void PlayerControls();
	float lastspeed = player_Zata.actorSpeed;
	class Timer
	{
	public:
		
		time_t currentTime = 0;
		time_t lastTime = time(NULL);
		float m_timer = 0;
		float deltaTime = 0.0005f;
		int previousCount = 0;
		int fps = 1;
		int frames = 0;
		float seconds;
		Timer();
		void Restart();
		float GetDeltaTime();
		float Seconds();
		void Stopwatch();

	};

	Timer gameTime;





};



