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
	// 弾初期化
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

// typeにより行動パターン記載
void Enemy::Move()
{
	switch (this->type) {
	case 0:
		// 右からスタートして左右行ったり来たり
		this->x = ((WINDOW_WIDTH / 2) - (TIP_W / 2)) + ((WINDOW_WIDTH / 2) - (TIP_W / 2)) * (float)sin((this->e_counter * PI / 90.0F));
		//if (x >= WINDOW_WIDTH) x = 0;
		break;

	case 1:
		// 左からスタートして左右行ったり来たり
		this->x = ((WINDOW_WIDTH / 2) - (TIP_W / 2)) + ((WINDOW_WIDTH / 2) - (TIP_W / 2)) * (float)sin((this->e_counter * PI / -120.0F));
		if (x < 0 - TIP_W) x = WINDOW_WIDTH;
		break;

	case 2:
		// 右に移動し続ける(画面端まで行ったら戻ってくる)
		this->x += 2;
		if (x >= WINDOW_WIDTH) x = 0 - TIP_W;
		break;
	case 3:
		// 上から下に移動し続ける
		this->y++;
		if (this->y > WINDOW_HEIGHT)this->y = 0 - TIP_W;
		break;
	case 4:
		// 下から上に移動し続ける
		this->y--;
		if (this->y < 0 - TIP_W)this->y = WINDOW_HEIGHT;
		break;
	default:
		assert(!"敵の数は5体まで"); // それ以外の時は強制終了
	}

}

void Enemy::Shot()
{
	int id;
	if (isAlive()) { // 自分が生きていたら
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
		// カウントリセット
	}
	if (this->e_counter >= 360)this->e_counter = 0;
	// 弾の制御
	LOOP(id, BULLET_MAX) {
		if (bullet[id]->isDEAD())continue;
		if (this->type == 0) {
			// 弾の弾道
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

		// その他の関数
		bullet[id]->All();
	}
}


State Enemy::All() {
	this->Draw();
	this->Move();
	this->Shot();
	return this->state;
}
