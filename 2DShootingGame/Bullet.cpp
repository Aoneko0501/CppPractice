#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(float bX, float bY, int gh)
{
	// �v���C���[�̐^���ʂ��甭��
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 3.0F;
	this->handle = gh;
	this->group = Group::OTHER;
}

// �e�̍��W���w��
void Bullet::setPoint(float bX, float bY)
{
	int gX;
	int gY;
	// �e�̉摜�̃T�C�Y���擾
	GetGraphSize(this->handle, &gX, &gY);

	this->x = bX + (TIP_W / 2) - (gX / 2);
	this->y = bY;
}


bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{
	// ��ʊO�ɂ͂ݏo��������ł�����
	if ((this->y) < -10.0F || (this->y) > (float)WINDOW_HEIGHT + 10.0F
		|| (this->x) > (float)WINDOW_WIDTH + 10.0F || (this->x) < -10.0F 
		|| this->state != State::ALIVE) 
	{
		this->state = State::DEAD;
		this->x = -100.0F;
		this->y = -100.0F;
	}
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
