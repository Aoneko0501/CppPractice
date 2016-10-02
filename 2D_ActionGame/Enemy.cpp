#include "Enemy.h"
#include<DxLib.h>

void Enemy::Move()
{
}

void Enemy::Draw()
{
	if (this->live) {
		DrawGraph(x, y, gh, FALSE);
	}
}

Enemy::Enemy(float x, float y)
{
	this->x = x;
	this->y = y;

	this->gh = LoadGraph("./sozai/Enemy/Enemy1A.bmp");

	GetGraphSize(gh,&width,&height);

	this->live = true;

	this->score = 200;
}

void Enemy::Dead()
{
	this->live = false;
}

int Enemy::GetScore()
{
	return this->score;
}

void Enemy::All()
{
	Move();
	Draw();
}
