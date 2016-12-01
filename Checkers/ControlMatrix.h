#pragma once
#include "MatrixMove.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"

class ControlMatrix
{
public:
	static StateGameField GetStateForGameField(int, int);
	static StateGameField GetStateForGameField(CoordinateInt*);
	static CoordinateInt* GetCoordinateForMatrix(CoordinateFloat*);
	static void Init();
};
