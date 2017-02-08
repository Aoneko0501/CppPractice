#pragma once
#include"Player.h"
#include"Enemy.h"
class GameManager {
private:
	Player* p;
	Enemy* e;

public:
	GameManager();
	~GameManager();
	void Update();
};