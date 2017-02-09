#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	this->x = 40;
	this->y = 100;
	this->state = State::ALIVE;
	this->handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
}

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
	this->state = State::ALIVE;
	this->handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
}

Enemy::~Enemy()
{
}


State Enemy::All() {
	this->Draw();
	this->Move();

	return State::ALIVE;
}