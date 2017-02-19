#include"GameManager.h"

GameManager::GameManager() {
	Init();
}

GameManager::~GameManager() {
	delete p;
	int id;
	LOOP(id, ENEMY_MAX) {
		delete e[id];
	}
}

void GameManager::Init()
{
	// ƒQ[ƒ€ó‘Ô‰Šú‰»
	this->g_state = GAME_TITLE;
	// ƒvƒŒƒCƒ„[‰Šú‰»
	this->p = new Player();

	// “G‰Šú‰»
	int handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
	int i;
	LOOP(i, ENEMY_MAX) {
		float eX = (float)((WINDOW_WIDTH / ENEMY_MAX) * i);
		float eY = 40.0F;
		e[i] = new Enemy(eX, eY, handle, (i % ENEMY_MAX));
	}
}

void GameManager::Update() {

	switch (this->g_state) {
	case GAME_TITLE:
		ShowTitle();
		break;
	case GAME_PLAY:
		GamePlay();
		break;
	case GAME_CLEAR:
		GameClear();
		break;
	case GAME_OVER:
		GameOver();
		break;
	default:
		break;
	}
}

// ƒ^ƒCƒgƒ‹‰æ–Ê
void GameManager::ShowTitle()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "PRESS SPACE KEY!");
	if (CheckHitKey(KEY_INPUT_SPACE))g_state = GAME_PLAY;
}


// ƒQ[ƒ€ƒvƒŒƒC‰æ–Ê
void GameManager::GamePlay()
{
	p->All();
	int id;
	// “G‚Ìî•ñXV
	LOOP(id, ENEMY_MAX) {
		// ’e‚Ì“–‚½‚è”»’è‚ðs‚¤
		CheckDamage(e[id], p->bullet); // “G->Ž©’e
		CheckDamage(p, e[id]->bullet); // Ž©‹@->“G
									// “G‚Ìˆ—‚ðs‚¤
		if (e[id]->All() == State::ALIVE) {
			DrawFormatString(500, 20 * id, GetColor(255, 255, 255), "%d:(%.1f,%.1f)", id, e[id]->getX(), e[id]->getY());
		}
		else {
			e[id]->rebornCounter++;
			// ˆê’èŽžŠÔŒã‚É•œŠˆ
			if (e[id]->rebornCounter == 100) {
				e[id]->rebornCounter = 0;
				e[id]->state = State::ALIVE;
			}
			DrawFormatString(540, 20 * id, GetColor(255, 255, 255), "%d is DEAD", id);
		}
	}

	if (!p->isAlive()) {
		g_state = GAME_OVER;
	}
}

// ƒQ[ƒ€ƒNƒŠƒA‰æ–Ê
void GameManager::GameClear()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME CLEAR!");
	if (CheckHitKey(KEY_INPUT_SPACE))Init();
}

// ƒQ[ƒ€ƒI[ƒo[‰æ–Ê
void GameManager::GameOver()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME OVER!");
	if (CheckHitKey(KEY_INPUT_SPACE))Init();
}


// ‘S‚Ä‚Ì’e‚Æ‚Ì“–‚½‚è”»’è‚ðŒvŽZ
void GameManager::CheckDamage(Actor* a, Bullet* b[])
{
	int id;
	LOOP(id, BULLET_MAX) {

		if (!b[id]->isDEAD()) {
			// ’e‚Ì’†SÀ•W‚ðì¬
			int bX = b[id]->getX() + 4.0F;
			int bY = b[id]->getY() + 4.0F;
			// “G”í’eˆ—
			if (a->group == Group::ACTOR_ENEMY) {
				if (bX > a->getX() && bX <= (a->getX() + TIP_W) &&
					bY > a->getY() && bY <= (a->getY() + TIP_W) && a->getState() == State::ALIVE) {
					a->setState(State::DEAD);
					b[id]->setState(State::DEAD);
				}
			}
			// Ž©‹@”í’eˆ—
			else if (a->group == Group::ACTOR_PLAYER) {
				int pX = (int)(a->getX() + (TIP_W / 2));
				int pY = (int)(a->getY() + (TIP_W / 2));
				int p = pow((pX - bX), 2) + pow((pY - bY), 2);

				if (p <= pow(4.0, 2) && a->getState() == State::ALIVE) {
					a->setState(State::DEAD);
					b[id]->setState(State::DEAD);
				}
			}
			// DrawFormatString(0, 20 * id, GetColor(255, 255, 255), "(%d,%d)", bX, bY);
		}
	}
}
