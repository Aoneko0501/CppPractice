#include "GameManager.h"
#include"Stage.h"
#include "Player.h"
#include"Block.h"

const int WINDOW_X = 640;
const int WINDOW_Y = 480;

static int bFlag = 0;

GameManager::GameManager(int winX, int winY)
{
	p = new Player(winX / 2, winY / 2);
	s = new Stage();
}

GameManager::~GameManager()
{
	delete p;
	delete s;
}

void GameManager::All()
{
	bFlag = 0;

	s->Draw();
	p->All();

	//ブロックに乗せるための処理

	//====左右の判定も作りたい=====

	for (int i = 187; i <= 191; i++) {
		BlockCollider(i);	
	}

	BlockCollider(69);
	BlockCollider(209);

	if (bFlag == 0) { p->onBlock = false; }
}

void GameManager::BlockCollider(int num)
{
	Block b = s->GetBlock(num);
	int bx = b.GetBlockX();
	int by = b.GetBlockY();

	if ((p->y + p->height) > by - 16 && (p->y + p->height) <= by && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->onBlock = true;
		p->isJump = false;
		p->vecY = 0.0f;
		p->y = by - 33;
		p->Walk();
		bFlag++;
	}
	else if ((p->y) <= by + 32 && (p->y) > by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->vecY = 3.0f;
	}
}
