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

		// �I�������u���b�N��z�u
		SetBlocks();

		if (bFlag == 0) { p->onBlock = false; } // bFlag=�u���b�N�̏�ɏ���Ă��邩�ǂ����̔���

		// �I�������G��z�u
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

// �u���b�N�z�u�p�֐�
void GameManager::SetBlocks() {

	// ID���w�肵�ďo��������u���b�N�����߂�
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
	// ==========�ǂ�������EnemyCollider()�݂̂�================
	// ============�摜�\���̐؂�ւ����o���邩�H=================
	EnemyCollider(0);
	EnemyCollider(1);
	EnemyCollider(2);
	EnemyCollider(3);
	EnemyCollider(4);
	EnemyCollider(5);
	EnemyCollider(6);
	EnemyCollider(7);
}


// �u���b�N�̓����蔻��
void GameManager::BlockCollider(int block_ID)
{
	// �w��u���b�N�̃|�C���^���΂����Ƃɂ���ĕύX�\�ɂȂ�B

	Block *b = s->GetBlock(block_ID);
	int bx = b->GetBlockX();
	int by = b->GetBlockY();


	b->isExsit = true;

	// �㑤
	if ((p->y + p->height) >= by - 10 && (p->y + p->height) <= by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->onBlock = true;
		p->isJump = false;
		p->vecY = 0.0f;
		p->y = by - 32 - 1;
		p->Walk();
		bFlag++;
	}
	// ����
	if ((p->y) <= by + 32 && (p->y) > by + 16 && (p->x + 16 >= bx) && (p->x + 16 < bx + 32)) {
		p->vecY = 5.0f;
	}
	// ����
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x + p->width >= bx) && (p->x + p->width < bx + 32)) {
		p->x = bx - 32;
		p->vecX = 0.0f;
	}
	// �E��
	if ((p->y + 16 >= by) && (p->y + 16 < by + 32) && (p->x < bx + 32) && (p->x >= bx)) {
		p->x = bx + 32;
		p->vecX = 0.0f;
	}
}

// �G�̓����蔻��
// �摜�\���̗L���������Őݒ�ł���悤�ɂ�����
void GameManager::EnemyCollider(int enemy_ID)
{
	// �w�肵���G�̃|�C���^���΂����Ƃɂ���ĕύX�\�ɂȂ�B

	Enemy *e = s->GetEnemy(enemy_ID);
	float ex = e->GetEnemyX();
	float ey = e->GetEnemyY();


	// �G���������Ă����ꍇ�̂݋@�\������
	if (e->isAlive()) {
		// �㑤
		if ((p->y + p->height) >= ey - 10 && (p->y + p->height) <= ey + 16 && (p->x + 16 >= ex) && (p->x + 16 < ex + 32)) {
			p->isJump = false;
			p->y = ey - 32 - 1;
			p->JumpStateChanger(false);
			e->Dead();
			s->AddScore(e->GetScore());
		}

		// ����
		if ((p->y) <= ey + 32 && (p->y) > ey + 16 && (p->x + 16 >= ex) && (p->x + 16 < ex + 32)) {
			p->vecY = 5.0f;
		}

		// ����
		if ((p->y + 16 >= ey) && (p->y + 16 < ey + 32) && (p->x + p->width >= ex) && (p->x + p->width < ex + 32)) {
			p->x = ex - 32;
			p->vecX = 0.0f;
		}
		// �E��
		if ((p->y + 16 >= ey) && (p->y + 16 < ey + 32) && (p->x < ex + 32) && (p->x >= ex)) {
			p->x = ex + 32;
			p->vecX = 0.0f;
		}
	}
}
