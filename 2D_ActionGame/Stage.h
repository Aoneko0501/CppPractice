#pragma once
class Player;

class Stage {
private:
	Player* player;

public:
	static const int WINDOW_X;
	static const int WINDOW_Y;

	Stage();

	void Update();
	void Draw();
};