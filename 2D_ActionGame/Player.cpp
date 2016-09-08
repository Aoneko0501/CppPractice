#include "Player.h"
#include"Stage.h"
#include<DxLib.h>
#include<math.h>

//enum��state������
enum State {
	STAND,
	WALK,
	DUSH,
	JUMP,
	NONE
};

Player::Player()
{
	SetX(300.0f);
	SetY(240.0f);
	SetVecX(0.0f);
	SetVecY(0.0f);
	this->gh = LoadGraph("Player.png");
	GetGraphSize(gh, &width, &height);
	this->live = true;
	jumpSpeed = 10.0f;


	//2�i�W�����v�p�t���O
	bool doubleJump = false;
	jump = 0;
}

Player::~Player() { delete this; }

void Player::SetX(float x) { this->x = x; }
void Player::SetY(float y) { this->y = y; }
void Player::SetGh(int gh) { this->gh = gh; }
void Player::SetVecX(float vx) { this->vecX = vx; }
void Player::SetVecY(float vy) { this->vecY = vy; }

float Player::GetX() { return this->x; }
float Player::GetY() { return this->y; }
int Player::GetGh() { return this->gh; }
float Player::GetVecX() { return this->vecX; }
float Player::GetVecY() { return this->vecY; }
int Player::GetWidth() { return this->width; }
int Player::GetHeight() { return this->height; }

void Player::Draw()
{
	if (!Move()) { delete this; }

	//�`��
	DrawGraph((int)x, (int)y, gh, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "X1���W:%f", GetX());
	DrawFormatString(0, 20, GetColor(255, 255, 255), "X2���W:%f", GetX() + width);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Y1���W:%f", GetY());
	DrawFormatString(0, 60, GetColor(255, 255, 255), "Y2���W:%f", GetY() + height);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "X���W�����x:%f", GetVecX());
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y���W�����x:%f", GetVecY());
	DrawFormatString(0, 120, GetColor(255, 255, 255), "�W�����v��:%d", jump);
}

bool Player::Move()
{
	float winX = Stage::WINDOW_X;
	float winY = Stage::WINDOW_Y;

	//�d�͉����x
	float g = 0.95f;

	//�����x
	float accel = 0.5f;
	//�ő�X�s�[�h
	float maxSpeed = 5.0f;


	//�㉺�̔���
	if (y > winY - height) {
		this->y = winY - height;
		this->vecY = 0.0f;
		doubleJump = false;
	}
	else if (y < 0) {
		this->y = 0.0f;
		this->vecY = 0.0f;
	}

	//�W�����v
	//�W�����v�������̉����x��ۑ�����
	//2�i�W�����v
	if (CheckHitKey(KEY_INPUT_SPACE) && (GetY() == winY - height)) {
		Jump();
	}
	else {
		//�������������˂Ă���
		this->vecY += g * 0.5f;
	}


	//���E
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		//�E
		if (vecX < maxSpeed) {
			this->vecX += accel;
		}
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		//��
		if ((GetVecX() * -1) < maxSpeed) {
			this->vecX -= accel;
		}
	}
	else {
		//���E�L�[��������Ă��Ȃ��ꍇ�͌���
		if (y + height >= winY) {
			this->vecX *= accel  * 0.99f;
		}
	}

	//�ǔ���
	if (x < 0) { x = 0.0f; vecX = 0.0f; }//����
	if (x + width > winX) { x = winX - width; vecX = 0.0f; }//�E��

	//�ړ�����
	x += vecX;
	y += vecY;

	return true;
}

void Player::Jump()
{
	this->vecY -= jumpSpeed;
	jump++;

}
