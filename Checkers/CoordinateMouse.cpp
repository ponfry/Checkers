#include "CoordinateMouse.h"
#include "WindowSize.h"
#include <iostream>
using namespace std;
CoordinateFloat* MyMouse::ConvertIntTOFloatForBoard(int x, int y)
{
	CoordinateFloat *result = new CoordinateFloat();
	result->Set(0, 0);
	if(InBoard(x,y))
	{
		int X = x - window_size.IndentX;
		int Y = y - window_size.IndentY - 33;

		
		if(X >= window_size.Board2)
		{
			result->X = (X - window_size.Board2) / window_size.Board2f;
		}
		else
		{
			result->X = (-1) * (window_size.Board2 - X) / window_size.Board2f;
		}

		if(Y >= window_size.Board2)
		{
			result->Y = (-1)*(Y - window_size.Board2) / window_size.Board2f;
		}
		else
		{
			result->Y = (window_size.Board2 - Y) / window_size.Board2f;
			
		}

		return result;
	}
	else
	{
		return result;
	}
}

bool MyMouse::InBoard(int x, int y)
{

	if (x >= window_size.IndentX
		&& x <= (window_size.IndentX + window_size.Board)
		&& y >= window_size.IndentY + 33
		&& y <= (window_size.IndentY + 33 + window_size.Board))
	{ 
		return true;
	}

	return false;
}
