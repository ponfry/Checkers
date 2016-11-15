#include "CoordinateMouse.h"
#include "WindowSize.h"
#include <iostream>

CoordinateFloat MyMouse::ConvertIntTOFloatForBoard(int x, int y)
{
	if(InBoard(x,y))
	{
		int X = x - window_size.IndentX;
		int Y = y - window_size.IndentY;

		
		if(X >= window_size.Board2)
		{
			res.X = (X - window_size.Board2) / window_size.Board2;
		}
		else
		{
			res.X = (-1) * (window_size.Board2 - X)  / window_size.Board2;
		}

		if(Y >= window_size.Board2)
		{
			res.Y = (-1)*(Y - window_size.Board2) / window_size.Board2;
		}
		else
		{
			res.Y = (window_size.Board2 - Y) / window_size.Board2;
			
		}
		return res;
	}
	else
	{
		

		return res;
	}
}

MyMouse::MyMouse()
{
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
