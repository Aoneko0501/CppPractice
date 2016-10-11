#pragma once
class Enemy {

	float x, y;
	int width, height;


	int gh;

	int score;
public:

	bool live;
private:
	void Move();
	void Draw();
public:
	Enemy(float x, float y);
	~Enemy();
	void Dead();
	int GetScore();
	float GetEnemyX();
	float GetEnemyY();

	bool isAlive();

	void All();
};
