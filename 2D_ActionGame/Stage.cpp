#include<DxLib.h>
#include "Stage.h"
#include "Player.h"

const int Stage::WINDOW_X = 640;
const int Stage::WINDOW_Y = 480;

Stage::Stage()
{
	player = new Player();
}


void Stage::Update()
{
	Draw();
}

void Stage::Draw()
{
	player->Draw();
}
