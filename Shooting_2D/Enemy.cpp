#include "Enemy.h"
#include "DxLib.h"
void Enemy::Draw()
{
	DrawGraph(cPos.x, cPos.y, handle, TRUE);
}

void Enemy::Move()
{
}

void Enemy::Update()
{
}

Enemy::Enemy(float eX, float eY)
{
	cPos = Point2D(eX,eY);
	handle = LoadGraph("sozai/Enemy/Enemy1A.bmp");
	isDead = false;
	moveSpeed = 1.5f;
}

bool Enemy::All()
{
	Draw();
	Move();
	Update();
	if (isDead) {
		return false;
	}
	return true;
}
