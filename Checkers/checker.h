#pragma once
#include "DrawTexture.h"
#include "CoordinateFloat.h"
#include "CoordinateInt.h"
#include "StateChecker.h"


class Checker
{
public:	
	Checker(int color=1);
	void Draw();

	void SetCoordinate(CoordinateInt*);
	void SetCoordinate(int, int);
	void SetCoordinate(float, float);

	bool CheckCoordinate(float, float);
	bool CheckCoordinate(int, int);

	bool CheckCoordinate(CoordinateFloat*);
	bool CheckCoordinate(CoordinateInt*);

	void SetState(StateChecker);
protected:
	virtual void Init(int);
	void InitDraw();
	void Print();

	CoordinateFloat* coordinateDraw, *coordinateState; 
	DrawTexture *drawing, *selected, *lighting;
	StateChecker state;
	bool result;
};
