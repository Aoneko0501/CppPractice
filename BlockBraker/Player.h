#pragma once
class Player {
public:
	int x, y;
	int width, height;
	int speed;
	int gh;

	Player();
	~Player();
	void Move();
	void Draw();
	void All();
};