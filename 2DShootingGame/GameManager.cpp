#include"GameManager.h"

GameManager::GameManager() {
	// ƒvƒŒƒCƒ„[‰Šú‰»
	p = new Player();
	
	// “G‰Šú‰»
	int handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
	int i;
	LOOP(i,ENEMY_MAX) {
		int eX = 20 * i;
		int eY = 40 * i;
		e[i] = new Enemy(eX,eY);
		e[i]->handle = handle;
	}
}

GameManager::~GameManager() {
	delete p;
	delete[] e;
}

void GameManager::Update() {
	p->All();
	int i;

	LOOP(i,ENEMY_MAX){
		if (e[i]->All() == State::DEAD) {
			delete e[i];
		}
	}
}
