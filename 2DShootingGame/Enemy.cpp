#include "Enemy.h"
#include"GameManager.h"
using namespace std;

Enemy::Enemy()
{
}

Enemy::Enemy(float x, float y, int gh)
{
	this->x = x;
	this->y = y;
	this->state = State::ALIVE;
	this->handle = gh;
	this->e_counter = 0;
	this->group = Group::ACTOR_ENEMY;
	// 弾初期化
	int bulletHandle;
	bulletHandle = LoadGraph("../src/bullet01.png", true);

	int		i;
	LOOP(i, BULLET_MAX) {
		this->bullet[i] = new Bullet(this->x, this->y, bulletHandle);
	}
}


// typeにより行動パターン記載
void Enemy::Move()
{

}

void Enemy::Shot()
{
	int id;
	if (isAlive()) { // 敵が生きていたら
		// 20フレームごとに弾を発射
		this->e_counter++;
		if ((this->e_counter % 20) == 0) {
			LOOP(id, BULLET_MAX) {
				if (bullet[id]->isDEAD()) {
					bullet[id]->setState(State::ALIVE);
					bullet[id]->setPoint(this->x, this->y);
					break;
				}
			}
		}
	}
	if (this->e_counter >= 360)this->e_counter = 0;
	// その他の関数
	LOOP(id, BULLET_MAX) {
		bullet[id]->All();
		// 出現している弾のみ動かす
		if (bullet[id]->isAlive()) {
			bullet[id]->y += 5;
		}
	}
}



State Enemy::All() {
	this->Draw();
	this->Move();
	this->Shot();

	return this->state;
}

void NormalEnemy1::Move()
{
	this->x++;
	if (x > WINDOW_WIDTH) this->x = -TIP_W;
}

void NormalEnemy2::Move()
{

}

void NormalEnemy2::Shot()
{
}

void NormalEnemy3::Move()
{
}

void NormalEnemy3::Shot()
{
}
