#pragma once
#include "CoordinatesFloat.h"

class MyMouse
{
public:	
	MyMouse();
	CoordinateFloat ConvertIntTOFloatForBoard(int x, int y);
	bool InBoard(int x, int y);
private:	
	CoordinateFloat res;
};
