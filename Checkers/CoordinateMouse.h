#pragma once
#include "CoordinateFloat.h"

class MyMouse
{
public:	
	static CoordinateFloat ConvertIntTOFloatForBoard(int x, int y);
	static bool InBoard(int x, int y);
};
