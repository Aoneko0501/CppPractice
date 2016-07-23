//プレーヤーが何ターン鬼から逃げられるか

#include<iostream>
#include<string.h>
#include"Stage.h"
using namespace std;



int main() {
	//状態配列確保
	Object* state = new Object[gStageHeight * gStageWidth];
	//ステージ初期化
	Stage* sg = new Stage(state, gStageWidth, gStageHeight, gStageData);

	//変数初期化
	int turn = 0;
	char input;
	bool gameSet = false;

	//メインループ
	while (!gameSet) {
		//ターン経過
		turn++;
		//画面表示
		sg->draw(state, gStageWidth, gStageHeight);
		//操作説明
		cout << "A:Right D:Left W:Up S:Down Command?" << endl;
		cin >> input;

		//画面更新
		sg->update(state, input, gStageWidth, gStageHeight);
		//継続可能かどうか
		if (sg->checkClear(state, gStageWidth, gStageHeight)) {
			gameSet = true;
		}
	}
	//結果発表
	sg->draw(state, gStageWidth, gStageHeight);
	cout << "GameOver!\n" << endl;
	cout << "あなたは" << turn << "ターン逃げ切りました。" << endl;
	//後始末
	delete[] state;
	delete sg;
	state = 0;

	return 0;
}