#include<DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

const int Stage::WINDOW_X = 640;
const int Stage::WINDOW_Y = 480;

Stage::Stage()
{
	player = new Player();

	for (int i = 0; i < 10; i++) {
		enemy[i] = new Enemy((Stage::WINDOW_X + ((float)i * 100.0f)),(Stage::WINDOW_Y - 32.0f));
	}
}


void Stage::Update()
{

	//“G‚ª‰E‚©‚çƒvƒŒƒCƒ„[‚É‚Ô‚Â‚©‚Á‚Ä‚«‚½‚ç“G‚ªisDead()
	for (int i = 0; i < 10; i++) {
		if ((int)(player->GetX() + 32.0f) == (int)enemy[i]->GetX()) {
			enemy[i]->isDead();
		}
	}
	Draw();
}

void Stage::Draw()
{
	if (!player->isLive()) {}
	else { player->Draw(); }

	for (int i = 0; i < 10; i++) {
		if (enemy[i]->isAlive()) { enemy[i]->Draw(); }
	}
}
