#include "Enemy.h"
#include "DxLib.h"

// �`��֐�
void Enemy::Draw()
{
	DrawGraph(pos.x, pos.y, handle, TRUE);
}

// Enemy�̍s������֐�
void Enemy::Move()
{
	// �� xFlag = 1
	if (xFlag) {
		pos.x -= moveSpeed;
		if (pos.x <= 0) { pos.x = 0; xFlag = 0; }
	}
	// �E xFlag = 0
	else {
		pos.x += moveSpeed;
		if (pos.x > 640 - 32) { pos.x = 640 - 32; xFlag = 1; }
	}
	// �� yFlag = 1
	if (yFlag) {
		pos.y -= moveSpeed;
		if (pos.y <= 0) { pos.y = 0; yFlag = 0; }
	}
	// �� yFlag = 0
	else {
		pos.y += moveSpeed;
		if (pos.y > 480 - 32) { pos.y = 480 - 32; yFlag = 1; }
	}
}

// �摜�X�V�֐�
void Enemy::Update()
{
	// �������̎�
	if (xFlag) {
		if (xFlag != oldFlagX) handle = LoadGraph("sozai/Enemy/Enemy1A.bmp");
	}
	// �E�����̎�
	else {
		if (xFlag != oldFlagX) handle = LoadGraph("sozai/Enemy/Enemy2A.bmp");
	}
	oldFlagX = xFlag;
}

// Enemy������
Enemy::Enemy(float eX, float eY)
	: xFlag(0)
	, yFlag(0)
	, oldFlagX(1)
{
	this->pos = Point2D(eX, eY);
	this->handle = LoadGraph("sozai/Enemy/Enemy1A.bmp");
	this->isDead = false;
	this->moveSpeed = 1.5f;
}

// Enmey��All�֐�
bool Enemy::All()
{
	Move();
	Update();
	Draw();
	if (isDead) {
		return false;
	}
	return true;
}
