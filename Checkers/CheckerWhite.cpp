#include "CheckerWhite.h"
#include "Texture.h"
#include "MatrixMove.h"

#include "CoordinateMouse.h"
#include <ostream>
#include <iostream>
#include "ControlMatrix.h"

CheckerWhite::CheckerWhite()
{
	drawing = WhiteDrawing;
	lighting = WhiteLighting;
	selecting = WhiteSelecting;	
}

void CheckerWhite::CheckWalkCoordinate(CoordinateInt* coord)
{
	int I = coord->X - 1;
	int J = coord->Y + 1;
	if (MatrixGameField[I][J] == freely)
	{
		availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
		availableMoves[countMove].IsBeat = false;
		countMove++;
	}
	J -= 2;
	if (MatrixGameField[I][J] == freely)
	{
		availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
		availableMoves[countMove].IsBeat = false;
		countMove++;
	}
}

void CheckerWhite::CheckBeatCoordinate(CoordinateInt*coord)
{
	int I = coord->X + 2;
	int J = coord->Y + 2;
	if (MatrixGameField[I][J] == freely)
	{
		if(MatrixGameField[I - 1][J - 1] == black)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					std::cout << " " << MatrixGameField[i][j];
						;
				}
				std::cout << std::endl;
			}
		}		
	}
	I -= 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I + 1][J - 1] == black)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
	J -= 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I + 1][J + 1] == black)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
	I += 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I - 1][J + 1] == black)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
}

void CheckerWhite::SetCoordinate(int x, int y)
{
	if (state != notdraw)
	{
		CoordinateFloat *result = MyMouse::ConvertIntTOFloatForBoard(x, y);
		CoordinateInt* coord = ControlMatrix::GetCoordinateForMatrix(result);

		if (coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = white;
			coord = ControlMatrix::GetCoordinateForMatrix(coordinateState);
			MatrixGameField[coord->X][coord->Y] = freely;
			delete coordinateState;
			coordinateState = result;
		}
	}
}

void CheckerWhite::SetCoordinate(float x, float y)
{
	if (state != notdraw)
	{
		CoordinateInt* coord = ControlMatrix::GetCoordinateForMatrix(new CoordinateFloat(x, y));
		if (coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = white;

			if (coordinateState != nullptr)
				coord = ControlMatrix::GetCoordinateForMatrix(coordinateState);

			coordinateState->Set(x, y);

			if (coord != nullptr)
				MatrixGameField[coord->X][coord->Y] = freely;

		}
	}
}
