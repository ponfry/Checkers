#pragma once
#include "CoordinateFloat.h"
#include "CoordinateInt.h"

class Conversion
{
public:
	static CoordinateInt* GetCoordinateForMatrix(CoordinateFloat*);	
	static void Init();
};
