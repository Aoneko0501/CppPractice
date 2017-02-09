#pragma once
#include"Player.h"
#include"Enemy.h"
class GameManager {
private:
	Player* p;
	Enemy* e[ENEMY_MAX];
public:
	GameManager();
	~GameManager();
	void Update();
};