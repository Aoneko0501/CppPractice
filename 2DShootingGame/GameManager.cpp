#include"DxLib.h"
#include"GameManager.h"
#include"Player.h"
#include"Enemy.h"

GameManager::GameManager() {
	p = new Player();
	e = new Enemy();
}

GameManager::~GameManager() {
	delete this;
}

void GameManager::Update() {
	p->All();
	e->All();
}
