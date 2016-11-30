#pragma once
#include "CoordinateFloat.h"
#include "CoordinateInt.h"
class MyMouse
{
public:	
	static CoordinateFloat* ConvertIntTOFloatForBoard(int x, int y);
	static CoordinateFloat* ConvertIntTOFloatForBoard(CoordinateInt*);

	static bool InBoard(int x, int y);
};
