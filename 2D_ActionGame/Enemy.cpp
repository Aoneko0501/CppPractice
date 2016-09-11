#include "Enemy.h"
#include"Stage.h"
#include<DxLib.h>

Enemy::Enemy(float setX,float setY)
{
	this->gh = LoadGraph("HatenaBlock.png");
	GetGraphSize(gh, &width, &height);
	this->live = true;
	this->x = setX;
	this->y = setY;
	this->vecX = 0.5f;
	this->vecY = 0.0f;

}

Enemy::~Enemy()
{
	delete[] this;
}

float Enemy::GetX()
{
	return this->x;
}

float Enemy::GetY()
{
	return this->y;
}

int Enemy::getWidth()
{
	return this->width;
}

int Enemy::getHeight()
{
	return this->height;
}

void Enemy::isDead()
{
	this->live = false;
}

bool Enemy::isAlive()
{
	return this->live ? true : false;
}

void Enemy::Draw()
{
	if (live) {
		Move();
		DrawGraph((int)x, (int)y, gh, TRUE);
	}
}

void Enemy::Move()
{
	x -= vecX;
}
