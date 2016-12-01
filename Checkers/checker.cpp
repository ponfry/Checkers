#include "checker.h"
#include "glew.h"
#include "Texture.h"
#include "CoordinateMouse.h"
#include <iostream>
#include "MatrixMove.h"
#include "ControlMatrix.h"
using namespace std;

Checker::Checker(int color)
{
	drawing = WhiteDrawing;
	lighting = WhiteLighting;
	selecting = WhiteSelecting;

	result = false;
	state = draw;
	coordinateDraw = new CoordinateFloat;
	coordinateState = new CoordinateFloat;
	availableMoves = new Move[15];
	countMove = 0;
}

void Checker::Draw()
{
	if (state != notdraw)
	{
		InitDraw();
		Print();
	}	
}

void Checker::InitDraw()
{
	switch (state)
	{
	case draw:
		Texture::LoadDraw(drawing);
		break;

	case selected:
	case constant:
		Texture::LoadDraw(selecting);
		break;

	case light:
		Texture::LoadDraw(lighting);
		break;
	default:
		break;
	}
}

void Checker::Print()
{
	switch(state)
	{
	case selected:
		delete coordinateDraw;
		coordinateDraw = MyMouse::ConvertIntTOFloatForBoard(coordinateMouseMove.X,
			coordinateMouseMove.Y);
		break;
	default:
		coordinateDraw->Set(coordinateState);
		break;
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(coordinateDraw->X - 0.125f, coordinateDraw->Y - 0.125f);

	glTexCoord2f(0, 0);
	glVertex2f(coordinateDraw->X - 0.125f, coordinateDraw->Y + 0.125f);

	glTexCoord2f(1, 1);
	glVertex2f(coordinateDraw->X + 0.125f, coordinateDraw->Y - 0.125f);

	glTexCoord2f(1, 0);
	glVertex2f(coordinateDraw->X + 0.125f, coordinateDraw->Y + 0.125f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void Checker::CheckBeatCoordinate(CoordinateInt*)
{
}

void Checker::CheckWalkCoordinate(CoordinateInt*)
{
}

void Checker::ControlMove()
{
	if (state != notdraw)
	{
		CoordinateInt* coord = ControlMatrix::GetCoordinateForMatrix(coordinateState);
		countMove = 0;

		CheckWalkCoordinate(coord);
		CheckBeatCoordinate(coord);
	}
}

void Checker::SetCoordinate(CoordinateInt *coord)
{
	SetCoordinate(coord->X, coord->Y);
}

void Checker::SetCoordinate(int, int)
{
}

void Checker::SetCoordinate(float, float)
{
}

CoordinateFloat* Checker::GetCurrentCoordinate()
{
	if (state != notdraw)
	{
		CoordinateFloat* result = new CoordinateFloat;
		result->Set(coordinateState);
		return result;
	}
	return nullptr;
}

bool Checker::CheckContactCoordinate(float x, float y)
{
	if (state != notdraw)
	{
		return coordinateState->CheckQuad(x, y);
	}
	return false;
}

bool Checker::CheckContactCoordinate(int x, int y)
{
	if (state != notdraw)
	{
		CoordinateFloat *res = MyMouse::ConvertIntTOFloatForBoard(x, y);
		result = coordinateState->CheckQuad(res);

		delete res;
		return result;
	}
	return false;
}

bool Checker::CheckContactCoordinate(CoordinateFloat* coord)
{
	if (state != notdraw)
	{
		return coordinateState->CheckQuad(coord);
	}
	return false;
}

bool Checker::CheckContactCoordinate(CoordinateInt* coord)
{
	if (state != notdraw)
	{
		return CheckContactCoordinate(coord->X, coord->Y);
	}
	return false;
}

bool Checker::HaveBeatMove()
{
	if (state != notdraw)
	{
		ControlMove();
		for (int i = 0; i < countMove; i++)
		{
			if (availableMoves[i].IsBeat)
			{
				return true;
			}
		}

	}
	return false;
}

CoordinateFloat* Checker::GetAllBeatMove()
{
	if(countMove == 0)
	{
		return nullptr;
	}

	CoordinateFloat* result = new CoordinateFloat [countMove];
	int j = 0;

	for (int i = 0; i < countMove; i++)
	{
		if(availableMoves[i].IsBeat)
		{
			result[j] = *availableMoves[i].Coordinate;
			j++;
		}
	}

	if(j==0)
	{
		return nullptr;
	}

	return result;
}

bool Checker::CheckMove(CoordinateFloat *coordinate)
{
	if (state != notdraw)
	{
		
		ControlMove();
		for (int i = 0; i < countMove; i++)
		{
			if (availableMoves[i].Coordinate->operator==(coordinate))
			{
				return true;
			}
		}
	}
	return false;
}

void Checker::SetState(StateChecker state_)
{
	if (state == notdraw)
		return;

	if (state_ != notdraw)
	{
		state = state_;
	}
	else
	{
		state = notdraw;
		CoordinateInt* coord = ControlMatrix::GetCoordinateForMatrix(coordinateState);
		MatrixGameField[coord->X][coord->Y] = freely;
		coordinateState = nullptr;
		return;
	}

	if (state_ == selected)
	{
		coordinateState->Set(coordinateDraw);
	}

	
}

StateChecker Checker::GetState()
{
	return state;
}
