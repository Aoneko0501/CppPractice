#pragma once
#include"Player.h"

class GameManager {
private:
	Player* p;

public:
	GameManager();
	~GameManager();
	void Update();
};