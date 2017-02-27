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
	
	this->g_state = GAME_TITLE;	// �Q�[����ԏ�����
	this->p = new Player();		// �v���C���[������
	this->aliveEnemy = ENEMY_MAX; // �G�̐���ݒ�

	// �G������
	int handle = LoadGraph("../src/Enemy/Enemy1A.bmp", true);
	int i;
	LOOP(i, ENEMY_MAX) {
		float eX = (float)((WINDOW_WIDTH / ENEMY_MAX) * i);
		float eY = 40.0F;
		e[i] = new Enemy(eX, eY, handle, (i % ENEMY_MAX));
	}
}

// �X�y�[�X�L�[���O�̃t���[���ŉ�����Ă��Ȃ������ꍇ�ɔ���������
bool newInputSpace;
bool oldInputSpace = false;
bool pushSpace;

void GameManager::Update() {
	
	newInputSpace = CheckHitKey(KEY_INPUT_SPACE);
	pushSpace = (!oldInputSpace) && newInputSpace;
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
}

// �^�C�g�����
void GameManager::ShowTitle()
{
	DrawFormatString(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "2D Shooting Game");
	
	ShowMenu();
}


// �Q�[���v���C���
void GameManager::GamePlay()
{
	p->All();

	// �G�̏��X�V
	UpdateInfo();

	// �v���C���[������Ă���΃Q�[���I�[�o�[��ʂ�
	if (!p->isAlive()) {
		g_state = GAME_OVER;
	}

	// �v���C���[������Ă���΃Q�[���I�[�o�[��ʂ�
	if (this->aliveEnemy <= 0) {
		g_state = GAME_CLEAR;
	}

	DrawFormatString(0,0, GetColor(255, 255, 255), "�c��:%d",this->aliveEnemy);
}

void GameManager::UpdateInfo() {
	int id;
	LOOP(id, ENEMY_MAX) {
		// �e�̓����蔻����s��
		CheckDamage(e[id], p->bullet); // �G->���e
		CheckDamage(p, e[id]->bullet); // ���@->�G
									   // �G�̏������s��
		if (e[id]->All() == State::ALIVE) {
			DrawFormatString(500, 20 * id, GetColor(255, 255, 255), "%d:(%.1f,%.1f)", id, e[id]->getX(), e[id]->getY());
		}
		else {
			e[id]->rebornCounter++;
			// ��莞�Ԍ�ɕ���(���Ȃ�)
			if (e[id]->rebornCounter == 100) {
				e[id]->rebornCounter = 0;
			}
			DrawFormatString(540, 20 * id, GetColor(255, 255, 255), "%d is DEAD", id);
		}
	}
}

// �Q�[���N���A���
void GameManager::GameClear()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME CLEAR!");
	if (pushSpace)Init();
}

// �Q�[���I�[�o�[���
void GameManager::GameOver()
{
	DrawFormatString(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GetColor(255, 255, 255), "GAME OVER!");
	if (pushSpace)Init();
}

// ���j���[��ʕ\��
// ��̓��͊m�F
bool newInputUp;
bool oldInputUp = false;
bool pushUp = !oldInputUp && newInputUp;

// ���̓��͊m�F
bool newInputDown;
bool oldInputDown = false;
bool pushDown = !oldInputDown && newInputDown;

int menu = 0;

typedef struct {
	int x, y;
	int color;
	char name[128];
}MenuElement_t;

// ���j���[��ʂ̗v�f�쐬
MenuElement_t MenuElement[3]{
	{ 100,WINDOW_HEIGHT / 2 ,GetColor(105, 105, 105) ,"START" },
	{ 100,WINDOW_HEIGHT / 2 + 30 ,GetColor(105, 105, 105) ,"OPTION" },
	{ 100,WINDOW_HEIGHT / 2 + 60,GetColor(105, 105, 105) ,"EXIT" }
};

void GameManager::ShowMenu()
{
	// �L�[���͔���
	newInputUp = CheckHitKey(KEY_INPUT_UP);
	newInputDown = CheckHitKey(KEY_INPUT_DOWN);
 
	pushUp = !oldInputUp && newInputUp;
	pushDown = !oldInputDown && newInputDown;

	if (pushUp)menu--;
	if (pushDown)menu++;

	// �I���������̂��E�֎኱���炷
	for (int i = 0; i < 3; i++) {
		if (i == menu) {
			MenuElement[i].x = 130;
			MenuElement[i].color = GetColor(255, 255, 255);
		}else{
			MenuElement[i].x = 100;
			MenuElement[i].color = GetColor(105, 105, 105);
		}			
	}

	// ���j���[�̕`��
	for (int i = 0; i < 3; i++) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, MenuElement[i].color, MenuElement[i].name);
	}

	if (pushSpace) { 
		switch (menu) {
		case 0:
			// �Q�[���X�^�[�g
			g_state = GAME_PLAY;
			break;

		case 1:
			// �I�v�V������ʂ�
			break;

		case 2:
			// ����I��
			exit(0);
			break;
		default:
			// �ُ�I��
			exit(1);
		}

	}

	if (menu >= 3) menu = 0;
	if (menu < 0)menu = 2;
	
	// �L�[���X�V
	oldInputUp = newInputUp;
	oldInputDown = newInputDown;
}


// �S�Ă̒e�Ƃ̓����蔻����v�Z
void GameManager::CheckDamage(Actor* a, Bullet* b[])
{
	int id;
	LOOP(id, BULLET_MAX) {

		if (!b[id]->isDEAD()) {
			// �e�̒��S���W���쐬
			int bX = b[id]->getX() + 4.0F;
			int bY = b[id]->getY() + 4.0F;
			// �G��e����
			if (a->group == Group::ACTOR_ENEMY) {
				if (bX > a->getX() && bX <= (a->getX() + TIP_W) &&
					bY > a->getY() && bY <= (a->getY() + TIP_W) && a->isAlive()) {
					a->setState(State::DEAD);
					b[id]->setState(State::DEAD);
					this->aliveEnemy--;
				}
			}
			// ���@��e����
			else if (a->group == Group::ACTOR_PLAYER) {

				// ���@�̒��S���W���G�e�̉~���ɑ��݂��Ă���Δ�e����
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
