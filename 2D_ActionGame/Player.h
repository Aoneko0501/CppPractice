#pragma once
class Player {
	float x, y;
	float vecX, vecY;
	int width, height;
	
	int gh;

	int life;

private:
	void Move();
	void Draw();

public:
	Player(float x,float y);
	void All();
};