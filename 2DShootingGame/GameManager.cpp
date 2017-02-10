#include"GameManager.h"

GameManager::GameManager() {
	// �v���C���[������
	p = new Player();
	
	// �G������
	int handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
	int i;
	LOOP(i,ENEMY_MAX) {
		int eX = 20 * i;
		int eY = 40 * i;
		e[i] = new Enemy(eX,eY,handle);
	}
}

GameManager::~GameManager() {
	delete p;
	delete[] e;
}

void GameManager::Update() {
	p->All();
	
	// �G�̏��X�V
	int i;
	LOOP(i,ENEMY_MAX){
		// �e�̓����蔻����s��
		e[i]->checkHit(p->bullet);
		// �G�̏������s��
		e[i]->All();
	}
}
