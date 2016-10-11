#include<DxLib.h>
#include "Stage.h"
#include"Block.h"
#include"Enemy.h"
#include "GameManager.h"

// ステージのコンストラクタ
Stage::Stage()
{
	// ブロック作成
	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x] = new Block(x * 32, y * 32, false);
		}
	}

	enemyConter = 0;	// 敵の数

	// 敵の作成
	for (int i = 0; i < 8; i++) {
		enemyConter++;
	}

	e[0] = new Enemy(532,64);	
	e[1] = new Enemy(64,32*5);
	e[2] = new Enemy(128, 360);
	e[3] = new Enemy(256, 96+64);
	e[4] = new Enemy(432, 356);
	e[5] = new Enemy(170, 256 + 4);
	e[6] = new Enemy(93, 256 - 64);
	e[7] = new Enemy(22, 26);

	this->score = 0;	// スコア初期化
}

// ブロックと敵の描画を行う
void Stage::Draw()
{
	// ブロック
	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x]->Draw();
		}
	}

	// 敵
	for (int i = 0; i < 8; i++) { e[i]->All(); }

	// 各情報
	DrawFormatString(480, 0, GetColor(255, 255, 255), "SCORE：%d", score);		// スコア
	DrawFormatString(480, 20, GetColor(255, 255, 255), "残り%d体", enemyConter);	// 残りの敵の数
}

// スコア追加関数
void Stage::AddScore(int score)
{
	this->score += score;	// スコアを加算する
	enemyConter--;			// 残りの敵の数を減らす

	// クリアボーナス
	if (enemyConter == 0) { this->score += 10000; }
}

//敵の数が0になったら(true)ゲームクリア
bool Stage::isGameEnd()
{
	return (enemyConter <= 0) ? true : false;
}

//指定したIDのブロックを返す
Block *Stage::GetBlock(int block_ID)
{
	return b[block_ID];
}

//指定したIDの敵を返す
Enemy * Stage::GetEnemy(int enemy_ID)
{
	return e[enemy_ID];
}
