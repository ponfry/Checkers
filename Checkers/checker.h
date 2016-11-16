#pragma once
#include "DrawTexture.h"
#include "CoordinateFloat.h"
#include "CoordinateInt.h"


class Checker
{
public:
	void Draw();
	Checker(int color=1);
	void SetCoordinate(CoordinateInt);
	void SetCoordinate(int, int);
protected:
	virtual void Init(int);
	CoordinateFloat coordinate_f, coordinateState;
	DrawTexture* draw;
};
