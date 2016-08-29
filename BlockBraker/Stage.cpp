#include<DxLib.h>
#include "Stage.h"
#include "Block.h"
#include "Ball.h"
#include "Player.h"

const int Stage::WINDOW_X = 640;
const int Stage::WINDOW_Y = 480;

Stage::Stage()
{
	Block* block[BLOCK_NUM];
	Ball* ball;
	Player* player;

	blockSum = BLOCK_NUM;
	score = 0;
	resetCheck = false;
	gameState = START;
	oldButtonPush = false;
	newButtonPush = false;

	for (int i = 0; i < BLOCK_NUM; i++) {
		this->block[i] = new Block((100 * (i / 4) + 30), (50 * (i % 4)));
	}
	this->ball = new Ball();
	this->player = new Player();
}

void Stage::GameManager() {
	
	switch (gameState) {
	case START:
		Game();
		break;
	case END:
		DrawFormatString(240, 230, GetColor(255, 255, 255), "GameClear!");
		ball->vecX = 0;
		ball->vecY = 0;
		break;
	default:
		break;
	}

}

void Stage::Game()
{
	for (int i = 0; i < BLOCK_NUM; i++) {
		block[i]->All();
	}
	player->All();
	ball->All();

	//ボールの情報格納用
	int ballX = ball->x;
	int ballY = ball->y;
	int ballR = ball->r;
	//自機バーの情報格納用
	int playerX = player->x;
	int playerY = player->y;
	int player_H = player->height;
	int player_W = player->width;



	//反射
	if (ballX - ballR < 0) { ball->vecX *= -1; }
	if (ballX + ballR > WINDOW_X) { ball->vecX *= -1; }
	if (ballY - ballR < 0) { ball->vecY *= -1; }

	//自機バー判定
	if (ballX > playerX && ballX < playerX + player->width && ballY + ballR > playerY &&
		ballY + ballR < playerY + player_H) {
		ball->vecY *= -1;
		//ボールの反射方向調整
		if (CheckHitKey(KEY_INPUT_LEFT))ball->vecX -= 1;
		else if (CheckHitKey(KEY_INPUT_RIGHT)) ball->vecX += 1;
	}

	//ブロックの場合
	for (int i = 0; i < BLOCK_NUM; i++) {

		if (block[i]->live) {

			//ブロックの情報格納用変数
			int blockX = block[i]->x;
			int blockY = block[i]->y;
			int block_H = block[i]->height;
			int block_W = block[i]->width;

			//上から
			if (ballX > blockX && ballX < blockX + block_W &&
				ballY + ballR > blockY && ballY + ballR < blockY + block_H) {
				ball->vecY *= -1;
				block[i]->live = false;
				blockSum--;
				score += 100;
			}

			//下から
			else if (ballX > blockX && ballX < blockX + block_W &&
				ballY - ballR > blockY && ballY - ballR < blockY + block_H) {
				ball->vecY *= -1;
				block[i]->live = false;
				blockSum--;
				score += 100;
			}

			//左から
			else if (ballX + ballR > blockX && ballX + ballR < blockX + block_W &&
				ballY > blockY && ballY < blockY + block_H) {
				ball->vecX *= -1;
				block[i]->live = false;
				blockSum--;
				score += 100;
			}

			//右から
			else if (ballX - ballR > blockX && ballX - ballR < blockX + block_W &&
				ballY > blockY && ballY < blockY + block_H) {
				ball->vecX *= -1;
				block[i]->live = false;
				blockSum--;
				score += 100;
			}
			
		}
	}

	//リセットボタン
	//押した瞬間のみ反応させる
	newButtonPush = CheckHitKey(KEY_INPUT_Q) ? true : false;

	if (!oldButtonPush && newButtonPush) {
		ball->x = 300;
		ball->y = 300;
		ball->vecX = 3;
		ball->vecY = 3;

		score -= 200;
	}
	oldButtonPush = newButtonPush;

	//文字表示
	if (blockSum > 0) {
		DrawFormatString(0, 460, GetColor(255, 255, 255), "残りブロック:%d", blockSum);
	}
	else {
		gameState = END;
	}

	//スコア表示
	DrawFormatString(400, 460, GetColor(255, 255, 255), "スコア:%d", score);
}
