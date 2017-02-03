#include "Bullet.h"
#include "DxLib.h"
#include <math.h>

// �������֐�
Bullet::Bullet(float x, float y)
{
	this->pos = Point2D(x, y);
	this->targetPos = targetPos;
	this->handle = LoadGraph("sozai/bullet01.bmp");
	this->isDead = false;
}

// �S�Ă̏��������s
void Bullet::All()
{
	Update();
	if (!this->isDead) {
		Draw();
	}
}


// �`��
void Bullet::Draw() {
	DrawGraph(pos.x, pos.y, handle, TRUE);
}

// ���X�V
void Bullet::Update()
{
}


