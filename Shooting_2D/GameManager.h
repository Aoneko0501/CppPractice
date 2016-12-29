#pragma once

#include"PLayer.h"
#include"Enemy.h"
#include"Stage.h"
#include"Bullet.h"

class GameManager {
private:
	Player *player;
	Enemy *enemy[10];
	Stage *stage;
	Bullet *bullet[100];

public:
	GameManager();
	~GameManager();
	void All();
};