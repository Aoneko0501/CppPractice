#include "GameManager.h"
#include<assert.h>
#include"Stage.h"

GameManager::GameManager()
{
	
}

GameManager::~GameManager()
{
}

void GameManager::Title()
{
}

void GameManager::Game()
{
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
