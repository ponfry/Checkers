#include "CoordinateMouse.h"
#include "WindowSize.h"
#include <iostream>
using namespace std;
CoordinateFloat* MyMouse::ConvertIntTOFloatForBoard(int x, int y)
{

	result.Set(0, 0);
	if(InBoard(x,y))
	{
		int X = x - window_size.IndentX;
		int Y = y - window_size.IndentY;

		
		if(X >= window_size.Board2)
		{
			result.X = (X - window_size.Board2) / window_size.Board2d;
		}
		else
		{
			result.X = (-1) * (window_size.Board2 - X) / window_size.Board2d;
		}

		if(Y >= window_size.Board2)
		{
			result.Y = (-1)*(Y - window_size.Board2) / window_size.Board2d;
		}
		else
		{
			result.Y = (window_size.Board2 - Y) / window_size.Board2d;
			
		}
		cout << "m" << result.X << "=" << result.Y << endl;
		return &result;
	}
	else
	{
		return &result;
	}
}

bool MyMouse::InBoard(int x, int y)
{

	if (x >= window_size.IndentX
		&& x <= (window_size.IndentX + window_size.Board)
		&& y >= window_size.IndentY
		&& y <= (window_size.IndentY + window_size.Board))
	{
		return true;
	}

	return false;
}
