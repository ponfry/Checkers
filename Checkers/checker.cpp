#include "checker.h"
#include "glew.h"
#include "Texture.h"
#include "CoordinateMouse.h"
#include <iostream>
using namespace std;

Checker::Checker(int color)
{
	state = StateChecker::draw;
	coordinateDraw = new CoordinateFloat;
	coordinateState = new CoordinateFloat;
	Checker::Init(color);
}

void Checker::Draw()
{
	if (state != StateChecker::notdraw)
	{
		InitDraw();

		Print();
	}	
}

void Checker::Init(int color)
{
	switch (color)
	{
	case 1:
		drawing = Texture::Init(L"texture/checkerblack.png");
		break;
	case 2:
		drawing = Texture::Init(L"texture/checkerwhite.png");
		break;
	default:
		drawing = nullptr;
		break;
	}
}

void Checker::InitDraw()
{
	switch (state)
	{
	case StateChecker::draw:
		Texture::LoadDraw(drawing);
		break;

	case StateChecker::selected:
		Texture::LoadDraw(selected);
		break;

	case StateChecker::lighting:
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
	case StateChecker::selected:
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

void Checker::SetCoordinate(CoordinateInt *coord)
{
	SetCoordinate(coord->X, coord->Y);
}

void Checker::SetCoordinate(int x, int y)
{
	delete coordinateState;
	coordinateState = MyMouse::ConvertIntTOFloatForBoard(x, y);
}

void Checker::SetCoordinate(float x, float y)
{
	coordinateState->Set(x, y);
}

bool Checker::CheckCoordinate(float x, float y)
{
	return coordinateState->CheckQuad(x, y);
}

bool Checker::CheckCoordinate(int x, int y)
{
	CoordinateFloat *res = MyMouse::ConvertIntTOFloatForBoard(x, y);
	result = coordinateState->CheckQuad(res);

	delete res;
	return result;
}

bool Checker::CheckCoordinate(CoordinateFloat* coord)
{
	return coordinateState->CheckQuad(coord);
}

bool Checker::CheckCoordinate(CoordinateInt* coord)
{
	return CheckCoordinate(coord->X, coord->Y);
}

void Checker::SetState(StateChecker state_)
{
	if(state != StateChecker::notdraw)
	{
		state = state_;
	}

	if (state_ == StateChecker::selected)
	{
		coordinateState->Set(coordinateDraw);
	}
	
}
