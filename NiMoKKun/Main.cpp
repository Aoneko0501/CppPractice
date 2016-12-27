#include<iostream>
#include<Windows.h>
using namespace std;

// 迷子のスライムを探せ
// #,X壁 _空間 Pプレイヤー sスライム

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


// 関数プロトタイプ
void Init(Object* state, int width, int height, const char* stageData);
void Draw(const Object* state, int width, int height);
void Update(Object* state, char input, int width, int height);
bool isGameover(const Object* state, int width, int height);


int main()
{
	//二次元配列ではnewが使えないので、一次元配列に
	Object* state = new Object[gStageWidth * gStageHeight];	// 状態配列確保

	Init(state, gStageWidth, gStageHeight, gStageData); // ステージ初期化

	// メインループ
	while (true) {
		system("cls");
		// 描画
		Draw(state, gStageWidth, gStageHeight);
		// ゲームオーバーチェック
		if (isGameover(state, gStageWidth, gStageHeight)) { break; }

		// 入力取得
		cout << "a:left d:right w:up s:down  Commmand?" << endl;
		char input;
		cin >> input;

		// 更新
		Update(state, input, gStageWidth, gStageHeight);
	}
	// 祝いのメッセージ
	cout << "おめでとう！\n迷子のスライムを発見した！" << endl;

	// 後始末
	delete[] state;
	state = 0;

	return 0;
}

void Init(Object* state, int width, int height, const char* stageData) {
	const char* d = stageData;	// 読み込みポインタ
	int x = 0;
	int y = 0;
	while (*d != '\0') {		// NULL文字でない間
		Object obj;
		switch (*d) {
		case '#':obj = OBJ_WALL; break;
		case ' ':obj = OBJ_SPACE; break;
		case 'X':obj = OBJ_BLOCK; break;
		case 'P':obj = OBJ_MAN; break;
		case 's':obj = OBJ_ENEMY; break;
		case 'T':obj = OBJ_CTF_MAN; break;
		case '\n':	// 次の行へ
			x = 0;
			y++;
			obj = OBJ_UNKNOWN;
			break;
		default:
			obj = OBJ_UNKNOWN; break; //不正データ
		}
		++d;
		// 知らない文字は無視する
		if (obj != OBJ_UNKNOWN) {
			state[y*width + x] = obj; // 書き込み
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

	// 人座標を検索
	int i = -1;
	for (i = 0; i < width*height; i++) {
		if (state[i] == OBJ_MAN) {
			break;
		}
	}

	int x = i % width;
	int y = i / width;

	// 移動用
	int tx = x + dx;
	int ty = y + dy;

	// 座標の最大値チェック。外れていれば不可
	if (tx < 0 || ty < 0 || tx >= width || ty >= height || state[ty * width + tx] == OBJ_BLOCK) {
		return;
	}

	//A.その方向が空白→移動
	int p = y*width + x; // 人の位置
	int tp = ty*width + tx; // ターゲットの位置

	// 移動処理
	if (state[tp] == OBJ_SPACE) {
		state[tp] =OBJ_MAN;
		state[p] = OBJ_SPACE;
	}
	else if (state[tp] == OBJ_ENEMY) {
		state[tp] = OBJ_CTF_MAN;
		state[p] = OBJ_SPACE;
	}
}

// スライムにぶつかったらクリア
bool isGameover(const Object* state, int width, int height) {
	for (int i = 0; i < width * height; i++) {
		if (state[i] == OBJ_CTF_MAN) {
			return true;
		}
	}
	return false;
}