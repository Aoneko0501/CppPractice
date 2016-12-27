#include "Point2D.h"
#include<Math.h>

//------------------------------------------------
/// x,y���W�Ƃ��Ƀ[���̍��W��Ԃ��܂�
const Point2D Point2D::Zero()
{
	return Point2D();
}
//------------------------------------------------
/// Point2D�N���X�̃C���X�^���X�𐶐����܂�
Point2D::Point2D()
	: x(0.0f)
	, y(0.0f)
{
}
//------------------------------------------------
/// Point2D�N���X�̃C���X�^���X���쐬���܂�
Point2D::Point2D(float aX, float aY)
	: x(aX)
	, y(aY)
{
}

//------------------------------------------------
bool Point2D::operator==(const Point2D& aPos)const
{
	return x == aPos.x && y == aPos.y;
}

// �덷�͈͓̔��œ������W���ǂ�����Ԃ�
bool Point2D::equals(const Point2D & aPos) const
{
	static const float EPS = 0.0001f;
	const float diffX = x - aPos.x;
	const float diffY = y - aPos.y;

	bool equalX = -EPS <= diffX && diffX <= EPS;
	bool equalY = -EPS <= diffY && diffY <= EPS;

	return equalX && equalY;
}
