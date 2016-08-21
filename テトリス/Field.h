#pragma once
class Field {
public:
	Field() {
		init();
	};
	~Field() {};

	//初期化
	void init();

	//壁かどうか
	//壁：true　それ以外：false
	bool isWall(int x, int y);
	//壁にブロックがめり込んでいるかどうか
	bool wallChecker();

	//描画
	void draw();

	//更新
	void update();

	//ブロック選択
	void blockSelecter();

	//消去判定
	void lineChecker();

	//ブロックが上に詰みあがったかどうか
	bool isGameOver();

	//タイマー
	void gameTimer();
};