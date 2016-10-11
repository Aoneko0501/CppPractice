#pragma once
class Player;
class Stage;
class Block;

extern const int WINDOW_X;
extern const int WINDOW_Y;

class GameManager {
	Player *p;
	Stage *s;

	int titleGh;
public:
	enum GameState {
		GAME_TITLE,
		GAME_PLAY,
		GAME_CLEAR,
		GAME_OVER
	};

	GameState gs;

private:
	void BlockCollider(int block_ID);
	void EnemyCollider(int enemy_ID);
public:
	GameManager(int winX, int winY);
	~GameManager();
	void All();

	void SetBlocks();
	void SetEnemys();

};
