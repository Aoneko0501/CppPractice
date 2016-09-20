#pragma once

class Stage;



class GameManager
{
	enum GameState {
		GAME_TITLE,
		GAME_PLAY,
		GAME_OVER
	};
	Stage *s;
	GameState g_State;

public:
	GameManager();
	~GameManager();

	void Title();
	void Game();
	void GameOver();

	void All();

};
