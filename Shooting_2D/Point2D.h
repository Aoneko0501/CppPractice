#pragma once

/* 
	���W�N���X
*/
class Point2D {
public:
	float x;	// x ���W
	float y;	// y ���W

	static const Point2D Zero();
	Point2D();
	Point2D(float aX, float aY);

	///@name ���l��r
	//@{
	bool operator==(const Point2D& aPos)const;	///< 2�̍��W������������Ԃ�
	bool equals(const Point2D& aPos)const;      ///< 2�̍��W���덷�͈͓̔��œ������������߂܂��B
	//@}



};