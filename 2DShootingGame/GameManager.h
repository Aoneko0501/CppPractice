#pragma once
#include"Player.h"
#include"Enemy.h"
class GameManager {
	enum GAME_STATE {
		GAME_TITLE,
		GAME_PLAY,
		GAME_CLEAR,
		GAME_OVER
	};
public:
	Player* p;
	Enemy* e[ENEMY_MAX];
	GAME_STATE g_state;

public:
	GameManager();
	~GameManager();
	void Init();
	void Update();

	void ShowTitle();
	void GamePlay();
	void GameClear();
	void GameOver();
	void CheckDamage(Actor* a, Bullet* b[]);
	void 


};