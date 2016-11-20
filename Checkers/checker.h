#pragma once
#include "DrawTexture.h"
#include "CoordinateFloat.h"
#include "CoordinateInt.h"
#include "StateChecker.h"


class Checker
{
public:
	void Draw();
	Checker(int color=1);
	void SetCoordinate(CoordinateInt);
	void SetCoordinate(int, int);
	void SetCoordinate(float, float);
	bool CheckCoordinate(float, float);
	void SetState(StateChecker);
protected:
	virtual void Init(int);
	void InitDraw();
	void Print();
	CoordinateFloat* coordinateDraw; 
	//CoordinateFloat coordinateState;
	DrawTexture* draw, *select, *lighting;
	StateChecker state;
};
