#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"

GameManager::GameManager()
{
	player = new Player();
	stage = new Stage();

	for (int enemyID = 0; enemyID < 10; enemyID++) {
		enemy[enemyID] = new Enemy(enemyID * 32, enemyID * 32);
	}
}

GameManager::~GameManager()
{
	delete player;
	delete stage;
	for (int enemyID = 0; enemyID < 10; enemyID++) {
		delete enemy[enemyID];
	}
}

void GameManager::All()
{
	player->All();
	stage->All();

	for (int enemyID = 0; enemyID < 10; enemyID++) {
		enemy[enemyID]->All();
	}
}
