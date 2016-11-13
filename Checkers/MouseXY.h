#pragma once
#include "Helper.h"

class MouseXY
{
public:
	MouseXY();	
	void Init(WindowSize* window_size);
	CoordinateF ConvertIntTOFloat(int x, int y);	

private:
	bool InSquare(int x, int y);
	WindowSize* _window_size;
	CoordinateF res;
};
