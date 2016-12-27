#pragma once

/* 
	座標クラス
*/
class Point2D {
public:
	float x;	// x 座標
	float y;	// y 座標

	static const Point2D Zero();
	Point2D();
	Point2D(float aX, float aY);

	///@name 等値比較
	//@{
	bool operator==(const Point2D& aPos)const;	///< 2つの座標が等しいかを返す
	bool equals(const Point2D& aPos)const;      ///< 2つの座標が誤差の範囲内で等しいかを求めます。
	//@}



};