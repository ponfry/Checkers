#include "MouseXY.h"
#include <iostream>

CoordinateF MouseXY::ConvertIntTOFloat(int x, int y)
{
	int board = _window_size->Weigth / 2.26;
	int indentX = board*0.2;
	int indentY = (_window_size->Heigth - board) / 2.0;
	float board2 = board / 2.0f;
	CoordinateF res;
	if(InSquare(x,y))
	{
		int X = x - indentX;
		int Y = y - indentY;

		
		if(X>=board/2.0)
		{
			res.X = (X - board2) / board2;			
		}
		else
		{
			res.X = (-1) * (board2 -X)  / board2;
		}

		if(Y>=board/2.0)
		{
			res.Y = (-1)*(Y - board2) / board2;
		}
		else
		{
			res.Y = (board2-Y) / board2;
			
		}
		return res;
	}
	else
	{

	}
}

MouseXY::MouseXY()
{
}

void MouseXY::Init(WindowSize * window_size)
{
	_window_size = window_size;
}

bool MouseXY::InSquare(int x, int y)
{
	int board = _window_size->Weigth / 2.26;
	int indentX = board*0.2;
	int indentY = (_window_size->Heigth - board) / 2.0;
	if (x >= indentX && x <= (indentX + board) && y >= indentY && y <= (indentY + board))
	{
		return true;
	}

	return false;
}
