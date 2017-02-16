#pragma once
#include"DxLib.h"
#include<cmath>

#define PI 3.141592

// ゲームに関する情報
#define WINDOW_WIDTH 640	// ウィンドウの幅
#define WINDOW_HEIGHT 480	// ウィンドウの高さ
#define TIP_W 32			// 使用画像のサイズ

#define ENEMY_MAX 4			// 敵の最大描画数
#define BULLET_MAX 50		// 各キャラの弾の最大保有数

#define LOOP(val,times) for(val = 0;val < (times); val++) // forループのマクロ

enum Group {
	ACTOR_PLAYER,
	ACTOR_ENEMY,
	OTHER
};