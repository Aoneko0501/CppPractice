#include "Enemy.h"
#include"GameManager.h"
using namespace std;

Enemy::Enemy()
{
}

Enemy::Enemy(float x, float y, int gh, int type)
{
	this->x = x;
	this->y = y;
	this->state = State::ALIVE;
	this->handle = gh;
	this->e_counter = 0;
	this->type = type;
	this->group = Group::ACTOR_ENEMY;
	// �e������
	int bulletHandle;
	if (this->type % 2) {
		bulletHandle = LoadGraph("../src/bullet01.png", true);
	}
	else {
		bulletHandle = LoadGraph("../src/bullet02.png", true);
	}

	int		i;
	LOOP(i, BULLET_MAX) {
		this->bullet[i] = new Bullet(this->x, this->y, bulletHandle);
	}
	this->rebornCounter = 0;
}

Enemy::~Enemy()
{
}

// type�ɂ��s���p�^�[���L��
void Enemy::Move()
{
	switch (this->type) {
	case 0:
		// �E����X�^�[�g���č��E�s�����藈����
		this->x = ((WINDOW_WIDTH / 2) - (TIP_W / 2)) + ((WINDOW_WIDTH / 2) - (TIP_W / 2)) * (float)sin((this->e_counter * PI / 90.0F));
		//if (x >= WINDOW_WIDTH) x = 0;
		break;

	case 1:
		// ������X�^�[�g���č��E�s�����藈����
		this->x = ((WINDOW_WIDTH / 2) - (TIP_W / 2)) + ((WINDOW_WIDTH / 2) - (TIP_W / 2)) * (float)sin((this->e_counter * PI / -120.0F));
		if (x < 0 - TIP_W) x = WINDOW_WIDTH;
		break;

	case 2:
		// �E�Ɉړ���������(��ʒ[�܂ōs������߂��Ă���)
		this->x += 2;
		if (x >= WINDOW_WIDTH) x = 0 - TIP_W;
		break;
	case 3:
		// �ォ�牺�Ɉړ���������
		this->y++;
		if (this->y > WINDOW_HEIGHT)this->y = 0 - TIP_W;
		break;
	case 4:
		// �������Ɉړ���������
		this->y--;
		if (this->y < 0 - TIP_W)this->y = WINDOW_HEIGHT;
		break;
	default:
		assert(!"�G�̐���5�̂܂�"); // ����ȊO�̎��͋����I��
	}

}

void Enemy::Shot()
{
	int id;
	if (isAlive()) { // �����������Ă�����
		this->e_counter++;
		if ((this->e_counter % 6) == 0) {
			LOOP(id, BULLET_MAX) {
				if (bullet[id]->isDEAD()) {
					bullet[id]->setState(State::ALIVE);
					bullet[id]->setPoint(this->x, this->y);
					break;
				}
			}
		}
		// �J�E���g���Z�b�g
	}
	if (this->e_counter >= 360)this->e_counter = 0;
	// �e�̐���
	LOOP(id, BULLET_MAX) {
		if (bullet[id]->isDEAD())continue;
		if (this->type == 0) {
			// �e�̒e��
			bullet[id]->y += bullet[id]->speed;
		}
		else if (this->type == 1) {
			bullet[id]->y += bullet[id]->speed + 1.0F;
		}
		else if (this->type == 2) {
			bullet[id]->y += bullet[id]->speed * sin(this->e_counter*PI / 90.0F) + 2.0F;
		}
		else if (this->type == 3) {
			bullet[id]->x -= bullet[id]->speed * sin((this->e_counter)*PI / 90.0F) + 1.0F;
			bullet[id]->y += 2.0F;
		}
		else if (this->type == 4) {
			bullet[id]->x += bullet[id]->speed * cos(45.0);
		}

		// ���̑��̊֐�
		bullet[id]->All();
	}
}


State Enemy::All() {
	this->Draw();
	this->Move();
	this->Shot();
	return this->state;
}
