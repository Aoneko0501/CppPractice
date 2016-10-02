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

	for (int i = 187; i <= 191; i++) {
		BlockCollider(i);	
	}

	BlockCollider(69);
	BlockCollider(209);

	BlockCollider(140);
	
	BlockCollider(229);

	BlockCollider(249);
	BlockCollider(250);
	BlockCollider(251);

	BlockCollider(55);
	BlockCollider(75);
	BlockCollider(95);
	BlockCollider(115);
	BlockCollider(135);
	BlockCollider(155);

	if (bFlag == 0) { p->onBlock = false; }
}


//ブロックの当たり判定
//左右も作りたい
void GameManager::BlockCollider(int num)
{
	Block b = s->GetBlock(num);
	int bx = b.GetBlockX();
	int by = b.GetBlockY();

	//上
	if ((p->y + p->height) >= by - 10 && (p->y + p->height) <= by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->onBlock = true;
		p->isJump = false;
		p->vecY = 0.0f;
		p->y = by - 32 - 1;
		p->Walk();
		bFlag++;
	}

	//下
	if ((p->y) <= by + 32 && (p->y) > by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->vecY = 5.0f;
	}

	//左
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x + p->width >= bx) && (p->x + p->width < bx + 32)) {
		p->x = bx - 32;
		p->vecX = 0.0f;
	}
	//右
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x < bx + 32)&&(p->x >= bx)) {
		p->x = bx + 32;
		p->vecX = 0.0f;
	}
}
