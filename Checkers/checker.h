﻿#pragma once
#include "DrawTexture.h"
#include "CoordinateFloat.h"
#include "CoordinateInt.h"
#include "StateChecker.h"
#include "Move.h"



class Checker
{
public:	
	Checker(int color=1);
	void Draw();

	void SetCoordinate(CoordinateInt*);
	void SetCoordinates(float, float);
	virtual void SetCoordinate(int, int);
	virtual void SetCoordinate(float, float);

	CoordinateFloat* GetCurrentCoordinate();

	bool CheckContactCoordinate(float, float);
	bool CheckContactCoordinate(int, int);

	bool CheckContactCoordinate(CoordinateFloat*);
	bool CheckContactCoordinate(CoordinateInt*);

	bool HaveBeatMove();
	CoordinateFloat* GetAllBeatMove();

	bool CheckMove(CoordinateFloat*);
	void ControlMove();

	void SetState(StateChecker);
	StateChecker GetState();
protected:
	void InitDraw();
	void Print();

	virtual void CheckBeatCoordinate(CoordinateInt*);
	virtual void CheckWalkCoordinate(CoordinateInt*);

	CoordinateFloat* coordinateDraw, *coordinateState;

	DrawTexture *drawing, *selecting, *lighting;
	StateChecker state;
	
	Move *availableMoves;
	int countMove;
	bool result;
};