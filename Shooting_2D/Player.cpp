/*
�v���C���[�̃N���X�ł�
@author tukeru
*/

#include "Player.h"
#include "DxLib.h"
// �v���C���[�̃R���X�g���N�^���쐬
Player::Player()
	:life(3)
	, bomb(3)
	, usingBomb(false)
{
	cPos = Point2D();
	handle = LoadGraph("sozai/shooterDragon.bmp");
	moveSpeed = 3.0f;
	isDead = false;
}

void Player::Draw() {
	if (!isDead) {
		DrawGraph(cPos.x, cPos.y, handle, TRUE);
	}
}

void Player::Move() {

}

void Player::All() {
	Draw();
	Move();
}
