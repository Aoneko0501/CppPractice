#include "Enemy.h"
#include<Dxlib.h>
void Enemy::Move()
{
}

void Enemy::Draw()
{
}

Enemy::Enemy(float x, float y, bool vec)
{
	this->x = x;
	this->y = y;

	this->gh = LoadGraph("Enemy.png");
	GetGraphSize(gh,&width,&height);

	this->vec = vec;
}

void Enemy::All()
{
	this->Move();
	this->Draw();
}
