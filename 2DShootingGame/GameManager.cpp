#include"DxLib.h"
#include"GameManager.h"

GameManager::GameManager() {
	p = new Player();
	
	for (int i = 0; i < ENEMY_MAX; i++) {
		e[i] = new Enemy(20*i,40*i);
	}
}

GameManager::~GameManager() {
	delete p;
	delete[] e;
}

void GameManager::Update() {
	p->All();
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (e[i]->All() == State::DEAD) {
			delete e[i];
		}
	}
}
