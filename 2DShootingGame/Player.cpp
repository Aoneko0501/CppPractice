#include "Player.h"

// コンストラクタ
Player::Player()
{
	this->x = (float)(WINDOW_WIDTH / 2.0);
	this->y = (float)(WINDOW_HEIGHT / 2.0);
	this->handle = LoadGraph("../src/shooterDragon.bmp", true);
	this->state = State::ALIVE;
	this->speed = 5.0F;
	this->group = Group::ACTOR_PLAYER;
	// 弾初期化
	int bulletHandle = LoadGraph("../src/bullet02.png", true);
	int i;
	LOOP(i, BULLET_MAX) {
		bullet[i] = new Bullet(this->x, this->y, bulletHandle);
	}
}

// デストラクタ
Player::~Player() {
	int id;
	LOOP(id,BULLET_MAX)delete bullet[id];
}

// ショット処理
int p_counter = 0;
void Player::Shot()
{

	int id;
	p_counter++;
	if (CheckHitKey(KEY_INPUT_Z) && ((p_counter %= 3) == 0) && this->state == State::ALIVE) {
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

// 移動関数
void Player::Move() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += this->speed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= this->speed;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= this->speed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += this->speed;
	}

	if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = WINDOW_WIDTH - TIP_W;
	if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = WINDOW_HEIGHT - TIP_W;
}

State Player::All() {

	Draw();
	// 弾の描写も行う
	// 死んでいたら動かさない
	if (this->state == State::ALIVE) {
		Move();
	}
	Shot();

	return this->state;
}
