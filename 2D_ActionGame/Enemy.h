#pragma once
class Enemy {

	float x, y;
	int width, height;

	bool live;

	int gh;

	int score;

private:
	void Move();
	void Draw();
public:
	Enemy(float x,float y);
	void Dead();
	int GetScore();

	void All();
};