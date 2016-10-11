#include "GameManager.h"
#include "Stage.h"
#include "Player.h"
#include "Block.h"
#include "Enemy.h"
#include <DxLib.h>

const int WINDOW_X = 640;
const int WINDOW_Y = 480;

static int bFlag = 0;

GameManager::GameManager(int winX, int winY)
{
	p = new Player(winX / 2, winY / 2);
	s = new Stage();

	this->titleGh = LoadGraph("./sozai/Title.png");

	this->gs = GAME_TITLE;
}

GameManager::~GameManager()
{
	delete p;
	delete s;
}

void GameManager::All()
{
	if (this->gs == GAME_TITLE) {

		DrawGraph(0, 0, titleGh, FALSE);
		if (CheckHitKey(KEY_INPUT_SPACE)) this->gs = GAME_PLAY;
	}
	else if (this->gs == GAME_PLAY)
	{
		bFlag = 0;

		s->Draw();
		p->All();

		// 選択したブロックを配置
		SetBlocks();

		if (bFlag == 0) { p->onBlock = false; } // bFlag=ブロックの上に乗っているかどうかの判定

		// 選択した敵を配置
		SetEnemys();

		if (s->isGameEnd() == true)gs = GAME_CLEAR;
	}
	else if (this->gs == GAME_CLEAR)
	{
		this->titleGh = LoadGraph("./sozai/GameClear.png");
		DrawGraph(0, 0, titleGh, FALSE);
	}
	else if (this->gs == GAME_OVER)
	{
		this->titleGh = LoadGraph("./sozai/GameOver.png");
		DrawGraph(0, 0, titleGh, FALSE);
	}
}

// ブロック配置用関数
void GameManager::SetBlocks() {

	// IDを指定して出現させるブロックを決める
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
}

void GameManager::SetEnemys()
{
	// ==========どうしたらEnemyCollider()のみで================
	// ============画像表示の切り替えも出来るか？=================
	EnemyCollider(0);
	EnemyCollider(1);
	EnemyCollider(2);
	EnemyCollider(3);
	EnemyCollider(4);
	EnemyCollider(5);
	EnemyCollider(6);
	EnemyCollider(7);
}


// ブロックの当たり判定
void GameManager::BlockCollider(int block_ID)
{
	// 指定ブロックのポインタを飛ばすことによって変更可能になる。

	Block *b = s->GetBlock(block_ID);
	int bx = b->GetBlockX();
	int by = b->GetBlockY();


	b->isExsit = true;

	// 上側
	if ((p->y + p->height) >= by - 10 && (p->y + p->height) <= by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->onBlock = true;
		p->isJump = false;
		p->vecY = 0.0f;
		p->y = by - 32 - 1;
		p->Walk();
		bFlag++;
	}
	// 下側
	if ((p->y) <= by + 32 && (p->y) > by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->vecY = 5.0f;
	}
	// 左側
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x + p->width >= bx) && (p->x + p->width < bx + 32)) {
		p->x = bx - 32;
		p->vecX = 0.0f;
	}
	// 右側
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x < bx + 32) && (p->x >= bx)) {
		p->x = bx + 32;
		p->vecX = 0.0f;
	}
}

// 敵の当たり判定
// 画像表示の有無もここで設定できるようにしたい
void GameManager::EnemyCollider(int enemy_ID)
{
	// 指定した敵のポインタを飛ばすことによって変更可能になる。

	Enemy *e = s->GetEnemy(enemy_ID);
	float ex = e->GetEnemyX();
	float ey = e->GetEnemyY();


	// 敵が生存していた場合のみ機能させる
	if (e->isAlive()) {
		// 上側
		if ((p->y + p->height) >= ey - 10 && (p->y + p->height) <= ey + 16 && (p->x + 16 >= ex) && (p->x + 16 < ex + 32)) {
			p->isJump = false;
			p->y = ey - 32 - 1;
			p->JumpStateChanger(false);
			e->Dead();
			s->AddScore(e->GetScore());
		}

		// 下側
		if ((p->y) <= ey + 32 && (p->y) > ey + 16 && (p->x + 16 >= ex) && (p->x + 16 < ex + 32)) {
			p->vecY = 5.0f;
		}

		// 左側
		if ((p->y + 16 >= ey) && (p->y + 16 < ey + 32) && (p->x + p->width >= ex) && (p->x + p->width < ex + 32)) {
			p->x = ex - 32;
			p->vecX = 0.0f;
		}
		// 右側
		if ((p->y + 16 >= ey) && (p->y + 16 < ey + 32) && (p->x < ex + 32) && (p->x >= ex)) {
			p->x = ex + 32;
			p->vecX = 0.0f;
		}
	}
}
