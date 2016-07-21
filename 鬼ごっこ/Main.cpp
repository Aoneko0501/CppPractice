//プレーヤーが何ターン鬼から逃げられるか

#include<iostream>
#include<string.h>
#include"Stage.h"
using namespace std;

//#壁　pプレイヤ　D敵　@障害物

const char gStageData[] = "\
##########\n\
#        #\n\
# @   D  #\n\
#        #\n\
#   p @  #\n\
#        #\n\
##########";

const int gStageWidth = 10;
const int gStageHeight = 7;

enum Object {
	WALL,
	OBSTACLE,
	PLAYER,
	DRAGON,
	SPACE,
	PLAYER_MERGE_DRAGON,

	UNKNOWN
};

//関数プロトタイプ(引数が1文字なのは悪い例らしい)
void initialize(Object* stage, int w, int h, const char* stageData);//初期化
void draw(Object* stage, int w, int h);//描写
void update(Object* stage, char input, int w, int h);//画面更新
bool checkClear(const Object* stage, int w, int h);//クリアチェッカー


int main() {
	//状態配列確保
	Object* state = new Object[gStageHeight * gStageWidth];
	//ステージ初期化
	initialize(state, gStageWidth, gStageHeight, gStageData);

	//変数初期化
	int turn = 0;
	char input;
	bool gameSet = false;
	//メインループ
	while (!gameSet) {
		//ターン経過
		turn++;
		//画面表示
		draw(state, gStageWidth, gStageHeight);
		//操作説明
		cout << "A:Right D:Left W:Up D:Down Command?" << endl;
		cin >> input;

		//画面更新
		update(state, input, gStageWidth, gStageHeight);
		//継続可能かどうか
		if (checkClear(state, gStageWidth, gStageHeight)) {
			gameSet = true;
		}
	}
	//結果発表
	cout << "GameOver!\n" << endl;
	cout << "あなたは" << turn << "ターン逃げ切りました。" << endl;
	//後始末
	delete[] state;
	state = 0;

	return 0;
}

//関数定義
void initialize(Object* state, int w, int h, const char* stageData) {
	const char* data = stageData; //読み込みポインタ
	int x = 0;
	int y = 0;

	while (*data != '\0') {//NULL文字でないかどうか
		Object t;
		switch (*data) {
		case '#':t = WALL; break;
		case ' ':t = SPACE; break;
		case 'p':t = PLAYER; break;
		case 'D':t = DRAGON; break;
		case 'T':t = PLAYER_MERGE_DRAGON; break;
		case '@':t = OBSTACLE; break;
		case '\n': //次の行へ
			x = 0;
			y++;
			t = UNKNOWN;
			break;
		default:t = UNKNOWN; break;
		}
		data++;//ポインタを次の文字のポインタへ切り替える
		//知らない文字を無視する用
		if (t != UNKNOWN) {
			state[y*w + x] = t;
			x++;
		}
	}
}

void draw(Object* state, int w, int h) {
	//enum型の並びと同じにする
	const char font[] = { '#','@','p','D',' ','T' };

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			Object o = state[y*w + x];
			cout << font[o];
		}
		cout << endl;
	}
}

void update(Object* stage, char input, int w, int h) {
	Stage* s = new Stage();
	//inputを変換
	int dx = 0;
	int dy = 0;
	switch (toupper(input)) {
	case 'A': dx = -1; break; //左
	case 'D': dx = 1; break; //右
	case 'W': dy = -1; break; //上
	case 'S': dy = 1; break; //下
	}
	//Stageオブジェクト解放
	delete s;


}