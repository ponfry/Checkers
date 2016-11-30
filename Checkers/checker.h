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
	CoordinateFloat* GetCurrentCoordinate();

	bool CheckContactCoordinate(float, float);
	bool CheckContactCoordinate(int, int);

	bool CheckContactCoordinate(CoordinateFloat*);
	bool CheckContactCoordinate(CoordinateInt*);

	bool CheckBeatCoordinate(CoordinateFloat*);
	int GetCountMove();
	void SetState(StateChecker);

	virtual bool CheckWalkCoordinate(CoordinateFloat*);
protected:
	virtual void Init();
	void InitDraw();
	void Print();

	virtual void ControlMove();
	CoordinateFloat* coordinateDraw, *coordinateState, *coordinateCheck, *availableMoves;
	DrawTexture *drawing, *selecting, *lighting;
	StateChecker state;
	
	int countMove;
	bool result;
};
