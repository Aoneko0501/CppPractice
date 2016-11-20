#pragma once

static const int FILED_WIDTH = 10;
static const int FILED_HEIGHT = 10;

class GameManager {
	Player player;
	Enemy enemy;
	Stage stage;

	int score;
	bool isGameOver;

private:
	GameManager();
	~GameManager();


};