#include "Player.h"

// コンストラクタ
Player::Player()
{
	this->x = WINDOW_WIDTH / 2;
	this->y = WINDOW_HEIGHT / 2;
	this->handle = LoadGraph("../src/shooterDragon.bmp", true);
	this->state = State::ALIVE;
	// 弾初期化
	int bulletHandle = LoadGraph("../src/bullet02.png", true);
	int i;
	LOOP(i, BULLET_MAX) {
		bullet[i] = new Bullet(this->x, this->y,bulletHandle);
	}
}

// デストラクタ
Player::~Player() {
	delete[] bullet;
}

// ショット処理
void Player::Shot()
{
	int id;
	if (CheckHitKey(KEY_INPUT_Z))
		LOOP(id, BULLET_MAX) {
		if (bullet[id]->isDEAD()) {
			bullet[id]->setState(State::ALIVE);
			bullet[id]->setPoint(this->x, this->y);
			break;
		}
	}

	LOOP(id, BULLET_MAX) {
		bullet[id]->All();
	}
}

// 移動関数
void Player::Move() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 2;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= 2;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += 2;
	}

	if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = WINDOW_WIDTH - TIP_W;
	if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = WINDOW_HEIGHT - TIP_W;
}

State Player::All() {
	Move();
	Draw();
	Shot();
	return this->state;
}
