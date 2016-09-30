#include "GameManager.h"
#include"Stage.h"
#include "Player.h"
#include"Block.h"

const int WINDOW_X = 640;
const int WINDOW_Y = 480;

GameManager::GameManager(int winX,int winY)
{
	p = new Player(winX/2,winY/2);
	s = new Stage();
}

GameManager::~GameManager()
{
	delete p;
	delete s;
}

void GameManager::All()
{
	s->Draw();
	p->All();

	
	for (int i = 187; i < 192; i++) {
	Block b = s->GetBlock(i);
		int bx = b.GetBlockX();
		int by = b.GetBlockY();

		if ((p->y + p->height) <= by && (p->x >= bx) && (p->x < bx + 32)) {
			p->vecY = 0.0f;
			p->y = by - 33;
		}
	}
}
