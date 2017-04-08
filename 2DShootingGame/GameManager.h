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
	int aliveEnemy;
public:
	Player* p;
	Enemy* e[ENEMY_MAX];
	GAME_STATE g_state;
	int phase; // 敵のフェーズ

public:
	GameManager();
	~GameManager();
	void Init();
	void Update();

	void UpdateInfo();
	void ShowTitle();
	void GamePlay();
	void GameClear();
	void GameOver();
	void CheckDamage(Actor* a, Bullet* b[]);
	void ShowMenu();
	void DrawMenu();
	void DoMenu();
	
	void SetEnemys(int phase_id);
};

typedef struct {
	int x, y;
	int color;
	char name[128];
}MenuElement_t;