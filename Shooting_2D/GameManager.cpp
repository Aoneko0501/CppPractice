#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"
#include "Bullet.h"



// GameManager初期化
GameManager::GameManager()
{
	player = new Player();
	stage = new Stage();

	for (int enemyID = 0; enemyID < 10; enemyID++) {
		enemy[enemyID] = new Enemy(enemyID * (32 * 2), enemyID * 32);
	}

	for (int bulletID = 0; bulletID < 100; bulletID++) {
		bullet[bulletID] = new Bullet((float)bulletID+1,(float)bulletID+1);
	}
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
	delete stage;
	for (int enemyID = 0; enemyID < 10; enemyID++) {
		delete enemy[enemyID];
	}

	for (int bulletID = 0; bulletID < 100; bulletID++) {
		delete bullet[bulletID];
	}
}

// 全ての行動を処理する関数
void GameManager::All()
{
	player->All();
	stage->All();

	for (int enemyID = 0; enemyID < 10; enemyID++) {
		enemy[enemyID]->All();
	}

	for (int bulletID = 0; bulletID < ; bulletID++) {
		bullet[bulletID]->All();
	}
}
