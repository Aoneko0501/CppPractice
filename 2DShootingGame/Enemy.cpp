#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
	this->state = State::ALIVE;
}

Enemy::~Enemy()
{
}


State Enemy::All() {
	this->Draw();
	this->Move();

	return State::ALIVE;
}