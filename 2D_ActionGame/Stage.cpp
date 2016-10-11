#include<DxLib.h>
#include "Stage.h"
#include"Block.h"
#include"Enemy.h"
#include "GameManager.h"

// �X�e�[�W�̃R���X�g���N�^
Stage::Stage()
{
	// �u���b�N�쐬
	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x] = new Block(x * 32, y * 32, false);
		}
	}

	enemyConter = 0;	// �G�̐�

	// �G�̍쐬
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

	this->score = 0;	// �X�R�A������
}

// �u���b�N�ƓG�̕`����s��
void Stage::Draw()
{
	// �u���b�N
	for (int y = 0; y < (WINDOW_Y / 32); y++) {
		for (int x = 0; x < (WINDOW_X / 32); x++) {
			b[y*(WINDOW_X / 32) + x]->Draw();
		}
	}

	// �G
	for (int i = 0; i < 8; i++) { e[i]->All(); }

	// �e���
	DrawFormatString(480, 0, GetColor(255, 255, 255), "SCORE�F%d", score);		// �X�R�A
	DrawFormatString(480, 20, GetColor(255, 255, 255), "�c��%d��", enemyConter);	// �c��̓G�̐�
}

// �X�R�A�ǉ��֐�
void Stage::AddScore(int score)
{
	this->score += score;	// �X�R�A�����Z����
	enemyConter--;			// �c��̓G�̐������炷

	// �N���A�{�[�i�X
	if (enemyConter == 0) { this->score += 10000; }
}

//�G�̐���0�ɂȂ�����(true)�Q�[���N���A
bool Stage::isGameEnd()
{
	return (enemyConter <= 0) ? true : false;
}

//�w�肵��ID�̃u���b�N��Ԃ�
Block *Stage::GetBlock(int block_ID)
{
	return b[block_ID];
}

//�w�肵��ID�̓G��Ԃ�
Enemy * Stage::GetEnemy(int enemy_ID)
{
	return e[enemy_ID];
}
