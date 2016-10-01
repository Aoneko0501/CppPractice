#include "Player.h"
#include"GameManager.h"
#include<DxLib.h>

static int jumpCounter = 0;

static bool showParam = false;

static float accel = 0.5f;
static float g = 0.95;
static float maxSpeed = 10.0f;

//�X�y�[�X�L�[���������Ƃ��̂݁A�������s�킹��p�̕ϐ�
bool newJumpPush = false;
bool oldJumpPush = false;

bool newShowState = false;
bool oldShowState = false;

//�v���C���[�ʒu�������A�C�R����
static bool isOutOfWindow = true;

//=============================================
//�ړ��֌W
//=============================================
void Player::Move()
{

	//�n�ʔ���=================================
	onGround = (y >= WINDOW_Y - height) ? true : false;

	if (onGround) {
		vecY = 0.0f;
		y = WINDOW_Y - height;
		isJump = false;
	}
	else if (!onGround) {
		vecY += g * accel;
	}

	//�ǔ���====================================
	if (x > WINDOW_X - width) {
		x = WINDOW_X - width;
		vecX = 0.0f;
	}
	else if (x < 0) {
		x = 0.0f;
		vecX = 0.0f;
	}

	Jump();
	Walk();

	//�����ō��W���ړ�������
	x += vecX;
	y += vecY;

}

void Player::SetOnBlock(bool b)
{
	this->onBlock = b;
}

//�_���[�W
void Player::Damage()
{
	life--;
}

//�W�����v�����Ƃ���2�i�W�����v�t���O��ύX����
void Player::JumpStateChanger(bool b) {
	this->vecY = -17.5f;
	isJump = b;
}

float Player::GetX()
{
	return this->x;
}

float Player::GetY()
{
	return this->y;
}

void Player::Walk()
{
	//===================================================
	//���E�ړ�
	//RIGHT==============================================
	if (CheckHitKey(KEY_INPUT_RIGHT)) {

		if (vecX < 0) { vecX += accel * 1.5f; }//��ɍ����֑����Ă�����
		else { vecX += accel; }

		if (vecX >= maxSpeed)vecX = maxSpeed;

		gh = LoadGraph("./sozai/PlayerA.png");
		GetGraphSize(gh, &width, &height);
	}
	//LEFT===============================================
	else if (CheckHitKey(KEY_INPUT_LEFT)) {

		if (vecX > 0) { vecX -= accel * 1.5f; }//��ɉE���֑����Ă�����
		else { vecX -= accel; }

		if (vecX <= -1 * maxSpeed)vecX = -1 * maxSpeed;

		gh = LoadGraph("./sozai/PlayerB.png");
		GetGraphSize(gh, &width, &height);
	}
	else {
		if (onGround || onBlock)vecX *= 0.5;
	}
}

void Player::Jump()
{
	newJumpPush = (CheckHitKey(KEY_INPUT_SPACE)) ? true : false;

	//�W�����v====================================
	if (newJumpPush && !oldJumpPush) {
		if (!isJump && (onGround || onBlock)) {
			JumpStateChanger(true);
			jumpCounter++;
		}
		else if (isJump && (!onGround||!onBlock)) {
			JumpStateChanger(false);
			jumpCounter++;
		}
	}

	oldJumpPush = newJumpPush;
}


//�`��
void Player::Draw()
{
	//�ʒu
	DrawGraph(x, 0, x_Gh, FALSE);
	//�L�����\��
	DrawGraph(x, y, gh, FALSE);

	newShowState = CheckHitKey(KEY_INPUT_D) ? true : false;

	if (newShowState && !oldShowState) {
		showParam = showParam ? false : true;
	}

	if (showParam) {
		//�X�e�[�^�X
		DrawFormatString(0, 0, GetColor(255, 255, 255), "X�������x�F%f", vecX);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "Y�������x�F%f", vecY);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "�W�����v�񐔁F%d", jumpCounter);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "�W�����v�F%s", isJump ? "true" : "false");
		DrawFormatString(0, 80, GetColor(255, 255, 255), "�u���b�N�F%s", onBlock ? "true" : "false");
	}

	oldShowState = newShowState;
}

//�����ݒ�
Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;
	this->vecX = 0.0f;
	this->vecY = 0.0f;

	this->gh = LoadGraph("./sozai/PlayerA.png");
	GetGraphSize(gh, &width, &height);

	this->x_Gh = LoadGraph("./sozai/PlayerXY.bmp");

	this->life = 3;

	this->onGround = false;
	this->onBlock = false;

	this->isJump = false;


}

//�����Ă��邩�ǂ���
bool Player::isAlive()
{
	if (this->life > 0)return true;
	return false;
}

//�Ƃ肠������
void Player::All()
{
	Move();
	Draw();
}
