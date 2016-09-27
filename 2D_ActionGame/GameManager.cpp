#include "GameManager.h"
#include "Player.h"

const int WINDOW_X = 640;
const int WINDOW_Y = 480;

GameManager::GameManager(int winX,int winY)
{
	p = new Player(winX/2,winY/2);

}

GameManager::~GameManager()
{
	delete p;
}

void GameManager::All()
{
	p->All();
}
