#include<DxLib.h>
#include "Stage.h"
#include"Block.h"
#include"Enemy.h"
#include "GameManager.h"

Stage::Stage()
{
	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x] = new Block(x * 32, y * 32, false);
		}
	}

	//élï˚î™ï˚Ç…ï¿Ç◊ÇΩÇ¢
	for (int i = 0; i < 8; i++) {
		e[i] = new Enemy(i*32,i*32);
	}
	this->score = 0;
}


void Stage::Draw()
{
	b[187]->isExsit = true;
	b[188]->isExsit = true;
	b[189]->isExsit = true;
	b[190]->isExsit = true;
	b[191]->isExsit = true;

	b[209]->isExsit = true;
	b[69]->isExsit = true;

	b[140]->isExsit = true;

	b[229]->isExsit = true;
	b[249]->isExsit = true;
	b[250]->isExsit = true;
	b[251]->isExsit = true;

	b[55]->isExsit = true;
	b[75]->isExsit = true;
	b[95]->isExsit = true;
	b[115]->isExsit = true;
	b[135]->isExsit = true;
	b[155]->isExsit = true;

	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x]->Draw();
		}
	}

	for (int i = 0; i < 8; i++) {
		e[i]->All();
	}

	
	DrawFormatString(480, 0, GetColor(255, 255, 255), "SCOREÅF%d", score);
}

Block Stage::GetBlock(int num)
{
	return *b[num];
}
