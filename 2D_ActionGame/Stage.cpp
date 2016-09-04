#include<DxLib.h>
#include "Stage.h"
#include "Player.h"

Stage::Stage()
{
	player = new Player();
}

Stage::~Stage()
{
	delete this;
}

void Stage::Update()
{
	Draw();
}

void Stage::Draw()
{
	float px = player->GetX();
	float py = player->GetY();
	float pvx = player->GetVecX();
	float pvy = player->GetVecY();
	int pw = player->GetWidth();
	int ph = player->GetHeight();


	int pgh = player->GetGh();

	if (px + pw > 640 || px < 0) {
		pvx = -1 * pvx;
		player->SetVecX(pvx);
	}

	//ˆÚ“®
	player->SetX((px + pvx));
	//•`‰æ
	DrawGraph((int)px,(int)py,pgh,TRUE);
}
