#include "CheckerBlack.h"
#include "Texture.h"
#include "MatrixMove.h"
#include "Conversion.h"
#include "CoordinateMouse.h"

CheckerBlack::CheckerBlack()
{
	CheckerBlack::Init();
}
void CheckerBlack::Init()
{
	drawing = Texture::Init(L"blackChecker/checker.png");
	selecting = Texture::Init(L"blackChecker/select.png");
	lighting = Texture::Init(L"blackChecker/lighting.png");
}

void CheckerBlack::CheckWalkCoordinate(CoordinateInt*coord)
{
	int I = coord->X + 1;
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

void CheckerBlack::CheckBeatCoordinate(CoordinateInt*coord)
{
	int I = coord->X + 2;
	int J = coord->Y + 2;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I - 1][J - 1] == white)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
	I -= 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I + 1][J - 1] == white)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
	J -= 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I + 1][J + 1] == white)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
	I += 4;
	if (MatrixGameField[I][J] == freely)
	{
		if (MatrixGameField[I - 1][J + 1] == white)
		{
			availableMoves[countMove].Coordinate = MatrixCheckBoard[I][J];
			availableMoves[countMove].IsBeat = true;
			countMove++;
		}
	}
}

void CheckerBlack::SetCoordinate(int x, int y)
{
	if (state != notdraw)
	{
		CoordinateFloat *result = MyMouse::ConvertIntTOFloatForBoard(x, y);
		CoordinateInt* coord = Conversion::GetCoordinateForMatrix(result);

		if (coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = black;
			coord = Conversion::GetCoordinateForMatrix(coordinateState);
			MatrixGameField[coord->X][coord->Y] = freely;
			delete coordinateState;
			coordinateState = result;
		}
	}
}

void CheckerBlack::SetCoordinate(float x, float y)
{
	if (state != notdraw)
	{
		CoordinateInt* coord = Conversion::GetCoordinateForMatrix(new CoordinateFloat(x, y));
		if (coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = black;

			if (coordinateState != nullptr)
				coord = Conversion::GetCoordinateForMatrix(coordinateState);

			coordinateState->Set(x, y);

			if (coord != nullptr)
				MatrixGameField[coord->X][coord->Y] = freely;

		}
	}
}
