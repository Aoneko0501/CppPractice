#pragma once

class Stage;
class Player;
class Enemy;


class GameManager
{
	enum GameState {
		GAME_TITLE,
		GAME_PLAY,
		GAME_OVER
	};

	Stage *stage;
	Player *player;
	Enemy *enemy;

	GameState g_State;



public:
	GameManager();
	~GameManager();

	void Title();
	void Game();
	void GameOver();

	void All();

};
