#include "Player.h"

// �R���X�g���N�^
Player::Player()
{
	this->x = (float)(WINDOW_WIDTH / 2.0);
	this->y = (float)(WINDOW_HEIGHT / 2.0);
	this->handle = LoadGraph("../src/shooterDragon.bmp", true);
	this->state = State::ALIVE;
	this->speed = 5.0F;
	this->group = Group::ACTOR_PLAYER;
	this->markerHandle = LoadGraph("../src/bullet02.png", true);
	// �e������
	int bulletHandle = LoadGraph("../src/bullet02.png", true);
	int i;
	LOOP(i, BULLET_MAX) {
		bullet[i] = new Bullet(this->x, this->y, bulletHandle);
	}
}

// �f�X�g���N�^
Player::~Player() {
	int id;
	LOOP(id,BULLET_MAX)delete bullet[id];
}

void Player::Draw()
{
	int markerX = x + (TIP_W / 2 - 4);
	int markerY = y + (TIP_W / 2 - 4);
	if (isAlive()) {
		DrawGraph(x, y, handle, false);
		DrawGraph(markerX, markerY, markerHandle, true);
	}
}

// �V���b�g����
int p_counter = 0;
void Player::Shot()
{

	int id;
	p_counter++;

	// Shot�{�^���̂����ꂩ����͔���
	const bool isShot = (CheckHitKey(KEY_INPUT_Z) || CheckHitKey(KEY_INPUT_J));
	
	// ���˂����e�̊��o�̒���
	const int interval = 5;
	const bool shotInterval = ((p_counter %= interval) == 0);

	if (isShot && shotInterval && isAlive()) {
		p_counter = 0;
		LOOP(id, BULLET_MAX) {
			if (bullet[id]->isDEAD()) {
				bullet[id]->setState(State::ALIVE);
				bullet[id]->setPoint(this->x, this->y);
				break;
			}
		}
	}

	LOOP(id, BULLET_MAX) {
		bullet[id]->y -= (float)(bullet[id]->speed * 2.0F);
		bullet[id]->All();
	}
}

// �ړ��֐�
void Player::Move() {

	// C�L�[�܂���L�L�[�������Ă���Ȃ�Ό���
	const bool isSlow = CheckHitKey(KEY_INPUT_C) || CheckHitKey(KEY_INPUT_L);
	if (isSlow) {
		this->speed = 2.0F;
	}
	else {
		this->speed = 5.0F;
	}

	// ���͂��������Ɉړ�
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) {
		x += this->speed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) {
		x -= this->speed;
	}
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) {
		y -= this->speed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) {
		y += this->speed;
	}

	// ��ʊO�ɏo�Ȃ��悤�ɂ��鏈��
	if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = WINDOW_WIDTH - TIP_W;
	if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = WINDOW_HEIGHT - TIP_W;
}

State Player::All() {

	Draw();
	// �e�̕`�ʂ��s��
	// ����ł����瓮�����Ȃ�
	if (isAlive()) {
		Move();
	}
	Shot();

	return this->state;
}
