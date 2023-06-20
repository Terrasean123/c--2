#pragma once
#include "raylib.h"
#include "raylib.hpp"
#include "glm/glm.hpp"
#include "Player.h"
#include "SceneObject.h"
#include "SpriteObject.h"
#include "Enemies.h"
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
	void ChoosePlayerDrawType(bool walkingForward);
	void PlayerAnim(int direction);
	void Win();
	void spawnEnemies();
	void PlayerEnemyCollision();
	void UpdateActorCollsionBoxes();
	void Lose();
	void playerStateMonitor();
	void SwordAnim(int direction,bool slash);

	int enemyNumber;
	bool slash= false;
	void GameUi();


	Enemies enemy1; Enemies enemy2; Enemies enemy3; Enemies enemy4; Enemies enemy5; Enemies enemy6;
	

	float lastspeed = player_Zata.actorSpeed;
	bool forward = false;
	int direction = 0;
	int once1 = 0;
	int once2 = 0;
	int once3 = 0;
	int once4 = 0;

	class Timer
	{
	public:

		//time_t currentTime = 0;
		//ime_t lastTime = time(NULL);
		float m_timer = 0;
		float deltaTime = 0.0005f;
		int previousCount = 0;
		int fps = 1;
		int frames = 0;
		double sec = 0;
		Timer();
		float GetDeltaTime();
		~Timer();

		

	};

	Timer gameTime;





};



