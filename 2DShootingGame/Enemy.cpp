#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int x, int y,int gh)
{
	this->x = x;
	this->y = y;
	this->state = State::ALIVE;
	this->handle = gh;
}

Enemy::~Enemy()
{
}


State Enemy::All() {
	this->Draw();
	this->Move();
	return this->state;
}

// ‘S‚Ä‚Ì’e‚Æ‚Ì“–‚½‚è”»’è‚ðŒvŽZ
void Enemy::checkHit(Bullet* b[])
{
	int id;
	LOOP(id, BULLET_MAX-1) {
		if (!b[id]->isDEAD()) {
			int bX = b[id]->getX() + 4;
			int bY = b[id]->getY() + 4;

			// ”í’eˆ—(‰æ‘œ‚ðÁ‚·‚¾‚¯)
			if (bX > this->x && bX <= (this->x + TIP_W) &&
				bY > this->y && bY <= (this->y + TIP_W)) {
				this->state = State::DEAD;
				b[id]->setState(State::DEAD);
			}
			DrawFormatString(0, 20 * id, GetColor(255, 255, 255), "(%d,%d)", bX, bY);
		}
	}


}
