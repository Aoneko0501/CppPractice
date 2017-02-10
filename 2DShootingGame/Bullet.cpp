#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int bX, int bY,int gh)
{
	// �v���C���[�̐^���ʂ��甭��
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 5.0;
	this->handle = gh;
}

// �e�̍��W���w��
void Bullet::setPoint(int bX, int bY)
{
	int gX;
	int gY;
	// �e�̉摜�̃T�C�Y���擾
	GetGraphSize(this->handle, &gX, &gY);

	this->x = bX + (TIP_W / 2) - (gX / 2);
	this->y = bY;
}

void Bullet::setState(State s)
{
	this->state = s;
}

bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{

	// ��ʊO�ɂ͂ݏo��������ł�����
	if ((this->y) < -10) { 
		this->state = State::DEAD;
		this->x = -10;
		this->y = -10;
	}
	else if(this->state == State::ALIVE){
		// �^��ɂ܂��������˂����
		y -= (int)(this->speed) * 2.0;
	}
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
