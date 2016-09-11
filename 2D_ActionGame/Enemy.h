#pragma once
class  Enemy {
private:
	float x, y;
	float vecX, vecY;
	float accel;
	int width, height;
	int gh;

	bool live;

public:
	Enemy(float setX,float setY);
	~Enemy();

	float GetX();
	float GetY();

	int getWidth();
	int getHeight();

	void isDead();

	bool isAlive();

	void Draw();
	void Move();

};