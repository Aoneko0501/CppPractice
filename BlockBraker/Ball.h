#pragma once
class Ball {
public:
	int x, y, r;
	int vecX, vecY;

	Ball();
	~Ball();
	void Draw();
	void Move();
	void All();
};