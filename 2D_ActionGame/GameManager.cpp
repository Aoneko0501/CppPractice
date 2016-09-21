#include "GameManager.h"
#include<assert.h>
#include"Stage.h"
#include"Player.h"

GameManager::GameManager()
{
	this->player = new Player();
	this->stage = new Stage();


}

GameManager::~GameManager()
{
	delete player;
	delete stage;
}

void GameManager::Title()
{
}

void GameManager::Game()
{
	player->All();
}

void GameManager::GameOver()
{
}

void GameManager::All()
{
	switch (g_State) {
	case GAME_TITLE:Title(); break;
	case GAME_PLAY:Game(); break;
	case GAME_OVER:GameOver(); break;
	default:assert(!"異常なステータスです。");
	}
}
