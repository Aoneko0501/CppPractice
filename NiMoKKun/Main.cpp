#include<iostream>
#include<Windows.h>
using namespace std;

// ���q�̃X���C����T��
// #,X�� _��� P�v���C���[ s�X���C��

const char gStageData[] = "\
###########\n\
#  P      #\n\
# X X X X #\n\
#         #\n\
# X X X X #\n\
#    s    #\n\
# X X X X #\n\
#         #\n\
###########";

const int gStageWidth = 11;
const int gStageHeight = 9;

enum Object{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_BLOCK,
	OBJ_MAN,
	OBJ_CTF_MAN,
	OBJ_ENEMY,

	OBJ_UNKNOWN
};


// �֐��v���g�^�C�v
void Init(Object* state, int width, int height, const char* stageData);
void Draw(const Object* state, int width, int height);
void Update(Object* state, char input, int width, int height);
bool isGameover(const Object* state, int width, int height);


int main()
{
	//�񎟌��z��ł�new���g���Ȃ��̂ŁA�ꎟ���z���
	Object* state = new Object[gStageWidth * gStageHeight];	// ��Ԕz��m��

	Init(state, gStageWidth, gStageHeight, gStageData); // �X�e�[�W������

	// ���C�����[�v
	while (true) {
		system("cls");
		// �`��
		Draw(state, gStageWidth, gStageHeight);
		// �Q�[���I�[�o�[�`�F�b�N
		if (isGameover(state, gStageWidth, gStageHeight)) { break; }

		// ���͎擾
		cout << "a:left d:right w:up s:down  Commmand?" << endl;
		char input;
		cin >> input;

		// �X�V
		Update(state, input, gStageWidth, gStageHeight);
	}
	// �j���̃��b�Z�[�W
	cout << "���߂łƂ��I\n���q�̃X���C���𔭌������I" << endl;

	// ��n��
	delete[] state;
	state = 0;

	return 0;
}

void Init(Object* state, int width, int height, const char* stageData) {
	const char* d = stageData;	// �ǂݍ��݃|�C���^
	int x = 0;
	int y = 0;
	while (*d != '\0') {		// NULL�����łȂ���
		Object obj;
		switch (*d) {
		case '#':obj = OBJ_WALL; break;
		case ' ':obj = OBJ_SPACE; break;
		case 'X':obj = OBJ_BLOCK; break;
		case 'P':obj = OBJ_MAN; break;
		case 's':obj = OBJ_ENEMY; break;
		case 'T':obj = OBJ_CTF_MAN; break;
		case '\n':	// ���̍s��
			x = 0;
			y++;
			obj = OBJ_UNKNOWN;
			break;
		default:
			obj = OBJ_UNKNOWN; break; //�s���f�[�^
		}
		++d;
		// �m��Ȃ������͖�������
		if (obj != OBJ_UNKNOWN) {
			state[y*width + x] = obj; // ��������
			++x;
		}
	}
}

void Draw(const Object* state, int width, int height) {
	const char font[] = {' ','#','X','P','T','s'};
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Object o = state[y*width + x];
			cout << font[o];
		}
		cout << endl;
	}
}

void Update(Object* state, char input, int width, int height) {
	int dx = 0;
	int dy = 0;
	switch (input) {
	case 'a':dx = -1; break;
	case 'd':dx = 1; break;
	case 'w':dy = -1; break;
	case 's':dy = 1; break;
	default:break;
	}

	// �l���W������
	int i = -1;
	for (i = 0; i < width*height; i++) {
		if (state[i] == OBJ_MAN) {
			break;
		}
	}

	int x = i % width;
	int y = i / width;

	// �ړ��p
	int tx = x + dx;
	int ty = y + dy;

	// ���W�̍ő�l�`�F�b�N�B�O��Ă���Εs��
	if (tx < 0 || ty < 0 || tx >= width || ty >= height || state[ty * width + tx] == OBJ_BLOCK) {
		return;
	}

	//A.���̕������󔒁��ړ�
	int p = y*width + x; // �l�̈ʒu
	int tp = ty*width + tx; // �^�[�Q�b�g�̈ʒu

	// �ړ�����
	if (state[tp] == OBJ_SPACE) {
		state[tp] =OBJ_MAN;
		state[p] = OBJ_SPACE;
	}
	else if (state[tp] == OBJ_ENEMY) {
		state[tp] = OBJ_CTF_MAN;
		state[p] = OBJ_SPACE;
	}
}

// �X���C���ɂԂ�������N���A
bool isGameover(const Object* state, int width, int height) {
	for (int i = 0; i < width * height; i++) {
		if (state[i] == OBJ_CTF_MAN) {
			return true;
		}
	}
	return false;
}