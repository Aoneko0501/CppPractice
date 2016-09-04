#pragma once
class Player;

class Stage {
private:
	Player* player;

public:
	Stage();
	~Stage();

	void Update();
	void Draw();
};