#include"DxLib.h"
#include"GameManager.h"
#include"Player.h"

GameManager::GameManager() {
	p = new Player();
}

GameManager::~GameManager() {
	delete this;
}

void GameManager::Update() {
	p->All();
}
