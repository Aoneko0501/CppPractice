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
	
	this->g_state = GAME_TITLE;	// ゲーム状態初期化
	this->p = new Player();		// プレイヤー初期化
	this->aliveEnemy = ENEMY_MAX; // 敵の数を設定
	this->phase = 0;

	// 敵初期化
	SetEnemys(this->phase);
}

// スペースキーが前のフレームで押されていなかった場合に反応させる
bool newInputSpace;
bool oldInputSpace = false;
bool pushSpace;

bool newInputEnter;
bool oldInputEnter = false;
bool pushEnter;

bool nextScene;

void GameManager::Update() {
	
	newInputSpace = CheckHitKey(KEY_INPUT_SPACE);
	newInputEnter = CheckHitKey(KEY_INPUT_RETURN);

	pushSpace = (!oldInputSpace) && newInputSpace;
	pushEnter = (!oldInputEnter) && newInputEnter;

	nextScene = (pushSpace || pushEnter);

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

	oldInputSpace = newInputSpace;
	oldInputEnter = newInputEnter;
}

// タイトル画面
void GameManager::ShowTitle()
{
	DrawFormatString(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "2D Shooting Game");
	
	ShowMenu();
	DrawMenu();
	DoMenu();
}


// ゲームプレイ画面
void GameManager::GamePlay()
{
	p->All();

	// 敵の情報更新
	UpdateInfo();

	// プレイヤーがやられていればゲームオーバー画面へ
	if (!p->isAlive()) {
		g_state = GAME_OVER;
	}

	// プレイヤーがやられていればゲームオーバー画面へ
	if (this->aliveEnemy <= 0) {
		if (this->phase < PHASE) {
			this->phase++;
		}
		g_state = GAME_CLEAR;
	}

	DrawFormatString(0,0, GetColor(255, 255, 255), "残り:%d",this->aliveEnemy);
}

void GameManager::UpdateInfo() {
	int id;
	LOOP(id, ENEMY_MAX) {
		// 弾の当たり判定を行う
		CheckDamage(e[id], p->bullet); // 敵->自弾
		CheckDamage(p, e[id]->bullet); // 自機->敵
									   // 敵の処理を行う
		if (e[id]->All() == State::ALIVE) {
			DrawFormatString(500, 20 * id, GetColor(255, 255, 255), "%d:(%.1f,%.1f)", id, e[id]->getX(), e[id]->getY());
		}
		else {
			DrawFormatString(540, 20 * id, GetColor(255, 255, 255), "%d is DEAD", id);
		}
	}
}

// ゲームクリア画面
void GameManager::GameClear()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME CLEAR!");
	if (nextScene)Init();
}

// ゲームオーバー画面
void GameManager::GameOver()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME OVER!");
	if (nextScene)Init();
}

// メニュー画面表示
// 上の入力確認
bool newInputUp;
bool oldInputUp = false;
bool pushUp = !oldInputUp && newInputUp;

// 下の入力確認
bool newInputDown;
bool oldInputDown = false;
bool pushDown = !oldInputDown && newInputDown;

int menu = 0; // 0:START, 1:OPTION, 2:EXIT

// メニュー画面の要素作成
MenuElement_t MenuElement[3]{
	{ 100,WINDOW_HEIGHT / 2 ,GetColor(105, 105, 105) ,"START" },
	{ 100,WINDOW_HEIGHT / 2 + 30 ,GetColor(105, 105, 105) ,"OPTION" },
	{ 100,WINDOW_HEIGHT / 2 + 60,GetColor(105, 105, 105) ,"EXIT" }
};

void GameManager::ShowMenu()
{
	// キー入力判定
	newInputUp = CheckHitKey(KEY_INPUT_UP);
	newInputDown = CheckHitKey(KEY_INPUT_DOWN);
 
	pushUp = !oldInputUp && newInputUp;
	pushDown = !oldInputDown && newInputDown;

	if (pushUp)menu--;
	if (pushDown)menu++;

	if (menu >= 3) menu = 0;
	if (menu < 0)menu = 2;
	
	// キー情報更新
	oldInputUp = newInputUp;
	oldInputDown = newInputDown;
}

void GameManager::DrawMenu()
{
	// 選択したものを右へ若干ずらす
	int i;
	LOOP(i,3){
		if (i == menu) {
			MenuElement[i].x = 130;
			MenuElement[i].color = GetColor(255, 255, 255);
		}
		else {
			MenuElement[i].x = 100;
			MenuElement[i].color = GetColor(105, 105, 105);
		}
	}

	// メニューの描画
	LOOP(i,3) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, MenuElement[i].color, MenuElement[i].name);
	}
}

void GameManager::DoMenu()
{
	// 各選択を行った後の挙動
	if (nextScene) {
		switch (menu) {
		case 0:
			// ゲームスタート
			g_state = GAME_PLAY;
			break;

		case 1:
			// オプション画面へ(まだ無理)
			break;

		case 2:
			// 正常終了
			exit(0);
			break;
		default:
			// 異常終了
			exit(1);
			break;
		}
	}
}

void GameManager::SetEnemys(int phase_id)
{
	int handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
	int i;
	switch (phase_id) {
	case 0:
		LOOP(i, ENEMY_MAX) {
			float eX = (float)((WINDOW_WIDTH / ENEMY_MAX) * i);
			float eY = 40.0F;
			e[i] = new NormalEnemy1(eX, eY, handle);
		}
		break;
	case 1:
		LOOP(i, ENEMY_MAX) {
			float eX = (float)((WINDOW_WIDTH / ENEMY_MAX) * i);
			float eY = 40.0F;
			e[i] = new NormalEnemy2(eX, eY, handle);
		}
		break;
	case 2:
		LOOP(i, ENEMY_MAX) {
			float eX = (float)((WINDOW_WIDTH / ENEMY_MAX) * i);
			float eY = 40.0F;
			e[i] = new NormalEnemy3(eX, eY, handle);
		}
		break;
	case 3:
		break;
	default:
		// phase_idが0~3以外の場合は異常とみなし終了
		exit(1);
		break;
	}
}


// 全ての弾との当たり判定を計算
void GameManager::CheckDamage(Actor* a, Bullet* b[])
{
	int id;
	LOOP(id, BULLET_MAX) {

		if (!b[id]->isDEAD()) {
			// 弾の中心座標を作成
			int bX = b[id]->getX() + 4.0F;
			int bY = b[id]->getY() + 4.0F;
			// 敵被弾処理
			if (a->group == Group::ACTOR_ENEMY) {
				if (bX > a->getX() && bX <= (a->getX() + TIP_W) &&
					bY > a->getY() && bY <= (a->getY() + TIP_W) && a->isAlive()) {
					a->setState(State::DEAD);
					b[id]->setState(State::DEAD);
					this->aliveEnemy--;
				}
			}
			// 自機被弾処理
			else if (a->group == Group::ACTOR_PLAYER) {

				// 自機の中心座標が敵弾の円内に存在していれば被弾処理
				int pX = (int)(a->getX() + (TIP_W / 2));
				int pY = (int)(a->getY() + (TIP_W / 2));
				int p = pow((pX - bX), 2) + pow((pY - bY), 2);

				if (p <= pow(4.0, 2) && a->isAlive()) {
					a->setState(State::DEAD);
					b[id]->setState(State::DEAD);
				}
			}
			// DrawFormatString(0, 20 * id, GetColor(255, 255, 255), "(%d,%d)", bX, bY);
		}
	}
}
