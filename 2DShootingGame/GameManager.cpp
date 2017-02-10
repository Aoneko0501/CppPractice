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
		e[i] = new Enemy(eX,eY,handle);
	}
}

GameManager::~GameManager() {
	delete p;
	delete[] e;
}

void GameManager::Update() {
	p->All();
	
	// “G‚Ìî•ñXV
	int i;
	LOOP(i,ENEMY_MAX){
		// ’e‚Ì“–‚½‚è”»’è‚ðs‚¤
		e[i]->checkHit(p->bullet);
		// “G‚Ìˆ—‚ðs‚¤
		e[i]->All();
	}
}
