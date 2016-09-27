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
	void JumpStateChanger(bool b);

public:
	void Damage();
	Player(float x,float y);
	bool isAlive();
	void All();
};