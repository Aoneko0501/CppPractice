#pragma once

#include"PLayer.h"
#include"Enemy.h"
#include"Stage.h"

class GameManager {
private:
	Player *player;
	Enemy *enemy[10];
	Stage *stage;

public:
	GameManager();
	~GameManager();
	void All();
};