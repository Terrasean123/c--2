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
	void WinCondition();
	//void spawnEnemies();
	void PlayerEnemyCollision();
	void UpdateActorCollsionBoxes();
	void EnemyStateMonitor();
	void playerStateMonitor();
	void SwordAnim(int direction, bool slash);

	//int enemyNumber;
	//bool mapCreated = false;
	void GameUi();

	//vector<Enemies*> EnemyGroup;
	Enemies enemy1; Enemies enemy2; Enemies enemy3;



	bool slash = false;
	bool gameOn = true;
	bool gameOver = false;
	bool forward = false;
	bool win = false;
	bool playerDead = false;
	int direction = 0;
	int once1 = 0;
	int once2 = 0;
	int once3 = 0;
	int once4 = 0;

	float lastspeed = player_Zata.actorSpeed;

	class Timer
	{
	public:
		float deltaTime = 0;
		float m_timer = 0;
		float GetDeltaTime();
		Timer();
		~Timer();
	};

	Timer gameTime;
};



