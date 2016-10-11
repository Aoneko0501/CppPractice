#include "Enemy.h"
#include<DxLib.h>

// �G�̈ړ�
void Enemy::Move()
{
}

// �G�̕`��
void Enemy::Draw()
{
	if (this->live) DrawGraph(x, y, gh, FALSE);
}

// �G�̃R���X�g���N�^
Enemy::Enemy(float x, float y)
{
	this->x = x;		// X���W
	this->y = y;		// Y���W

	this->gh = LoadGraph("./sozai/Enemy/Enemy1A.bmp");	// �摜�n���h�����i�[
	GetGraphSize(gh, &width, &height);					// �摜�̃T�C�Y���e�ϐ��Ɋi�[

	this->live = true;	// �G�������Ă��邩(���݂��Ă��邩)�ǂ���
	this->score = 200;	// �G��|�����Ƃ��ɓ�����X�R�A
}

// �G�̃f�X�g���N�^
Enemy::~Enemy()
{
	delete this;
}

// �G�����܂ꂽ��
void Enemy::Dead()
{
	this->live = false; // �� 
}

// ���̓G�������Ă���X�R�A��Ԃ�
int Enemy::GetScore()
{
	return this->score;
}

// �G��X�����W��Ԃ�
float Enemy::GetEnemyX()
{
	return this->x;
}

// �G��Y�����W��Ԃ�
float Enemy::GetEnemyY()
{
	return this->y;
}

// �O������G�������Ă��邩�ǂ������m�F�ł���悤�ɂ��邽�߂̊֐�
bool Enemy::isAlive()
{
	return this->live;
}

// �G�̈ړ��ƕ`����s��
void Enemy::All()
{
	Move();	// �ړ�
	Draw();	// �`��
}
