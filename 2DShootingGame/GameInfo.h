#pragma once
#include"DxLib.h"
#include<cmath>

#define PI 3.141592

// �Q�[���Ɋւ�����
#define WINDOW_WIDTH 640	// �E�B���h�E�̕�
#define WINDOW_HEIGHT 480	// �E�B���h�E�̍���
#define TIP_W 32			// �g�p�摜�̃T�C�Y

#define ENEMY_MAX 4			// �G�̍ő�`�搔
#define BULLET_MAX 50		// �e�L�����̒e�̍ő�ۗL��

#define LOOP(val,times) for(val = 0;val < (times); val++) // for���[�v�̃}�N��

enum Group {
	ACTOR_PLAYER,
	ACTOR_ENEMY,
	OTHER
};