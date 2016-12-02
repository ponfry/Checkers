#pragma once
#include "CoordinateFloat.h"
#include "CoordinateInt.h"
class MyMouse
{
public:	
	static CoordinateFloat* ConvertIntToFloatForBoard(int x, int y);
	static CoordinateFloat* ConvertIntToFloatForBoard(CoordinateInt*);
	static CoordinateFloat* ConvertIntToFloat(CoordinateInt*);

	static bool InBoard(int x, int y);
};
