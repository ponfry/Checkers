#include "checker.h"
#include "glew.h"
#include "Texture.h"
#include "CoordinateMouse.h"
#include <iostream>
#include "MatrixMove.h"
#include "Conversion.h"
using namespace std;

Checker::Checker(int color)
{
	state = draw;
	coordinateDraw = new CoordinateFloat;
	coordinateState = new CoordinateFloat;
	coordinateCheck = new CoordinateFloat;
	availableMoves = new CoordinateFloat[15];
	countMove = 0;
	Checker::Init();
}

void Checker::Draw()
{
	if (state != notdraw)
	{
		InitDraw();
		Print();
	}	
}

void Checker::Init()
{
	drawing = Texture::Init(L"texture/checkerwhite.png");
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

void Checker::ControlMove()
{
	CoordinateInt* coord = Conversion::GetCoordinateForMatrix(coordinateState);
	if((coord->X+1 < SizeMatrix || coord->X-1 >=0) && 
		(coord->Y + 1 < SizeMatrix || coord->Y - 1 >= 0))
	{
		countMove = 1;
	}
}

void Checker::SetCoordinate(CoordinateInt *coord)
{
	SetCoordinate(coord->X, coord->Y);
}

void Checker::SetCoordinate(int x, int y)
{
	if (state != notdraw)
	{
		CoordinateFloat *result = MyMouse::ConvertIntTOFloatForBoard(x, y);
		CoordinateInt* coord = Conversion::GetCoordinateForMatrix(result);

		if(coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = busy;
			coord = Conversion::GetCoordinateForMatrix(coordinateState);
			MatrixGameField[coord->X][coord->Y] = freely;
			delete coordinateState;
			coordinateState = result;
		}		
	}
}

void Checker::SetCoordinate(float x, float y)
{
	if (state != notdraw)
	{
		CoordinateInt* coord = Conversion::GetCoordinateForMatrix(new CoordinateFloat(x, y));
		if (coord != nullptr)
		{
			MatrixGameField[coord->X][coord->Y] = busy;
			coord = Conversion::GetCoordinateForMatrix(coordinateState);
			if(coord!=NULL)
				MatrixGameField[coord->X][coord->Y] = freely;
			coordinateState->Set(x, y);
		}		
	}
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

bool Checker::CheckBeatCoordinate(CoordinateFloat* coordinate)
{
	if (state != notdraw)
	{
		coordinateCheck->Set(coordinateState->X + 0.5f, coordinateState->Y + 0.5f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;

		coordinateCheck->Set(coordinateState->X - 0.5f, coordinateState->Y + 0.5f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;

		coordinateCheck->Set(coordinateState->X - 0.5f, coordinateState->Y - 0.5f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;

		coordinateCheck->Set(coordinateState->X + 0.5f, coordinateState->Y - 0.5f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;
	}
	return false;
}

int Checker::GetCountMove()
{
	if(state !=notdraw)
	{
		ControlMove();
		return countMove;
	}
	else
	{
		return 0;
	}
}

bool Checker::CheckWalkCoordinate(CoordinateFloat* coordinate)
{
	if (state != notdraw)
	{
		coordinateCheck->Set(coordinateState->X + 0.25f, coordinateState->Y + 0.25f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;

		coordinateCheck->Set(coordinateState->X - 0.25f, coordinateState->Y + 0.25f);
		if (coordinateCheck->CheckQuad(coordinate))
			return true;
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
		CoordinateInt* coord = Conversion::GetCoordinateForMatrix(coordinateState);
		MatrixGameField[coord->X][coord->Y] = freely;
		coordinateState = nullptr;
		return;
	}

	if (state_ == selected)
	{
		coordinateState->Set(coordinateDraw);
	}

	
}
