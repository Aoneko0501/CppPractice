#pragma once
class Player;
class Stage;

extern const int WINDOW_X;
extern const int WINDOW_Y;

class GameManager {
	Player *p;
	Stage *s;
public:
	GameManager(int winX,int winY);
	~GameManager();
	void All();
};