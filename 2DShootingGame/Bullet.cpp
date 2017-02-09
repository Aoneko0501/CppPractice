#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int bX, int bY)
{
	// �v���C���[�̐^���ʂ��甭��
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 5.0;
}

// �e�̍��W���w��
void Bullet::setPoint(int bX, int bY)
{
	this->x = bX + (TIP_W / 2) - 4;
	this->y = bY;
}

bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{
	// �^��ɂ܂��������˂����
	y -= (this->speed) * 2.0;

	// ��ʊO�ɂ͂ݏo��������ł�����
	if (this->y < -10)this->state = State::DEAD;
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
