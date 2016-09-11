#pragma once
class Player;
class Enemy;

class Stage {
private:
	Player* player;
	Enemy* enemy[10];

public:
	static const int WINDOW_X;
	static const int WINDOW_Y;

	Stage();

	void Update();
	void Draw();
};