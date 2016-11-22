﻿#include "checker.h"
#include "glew.h"
#include "Texture.h"
#include "CoordinateMouse.h"
#include <iostream>
using namespace std;

Checker::Checker(int color)
{
	state = draw;
	coordinateDraw = new CoordinateFloat;
	coordinateState = new CoordinateFloat;
	coordinateCheck = new CoordinateFloat;
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

bool Checker::CheckContactCoordinate(float x, float y)
{
	return coordinateState->CheckQuad(x, y);
}

bool Checker::CheckContactCoordinate(int x, int y)
{
	CoordinateFloat *res = MyMouse::ConvertIntTOFloatForBoard(x, y);
	result = coordinateState->CheckQuad(res);

	delete res;
	return result;
}

bool Checker::CheckContactCoordinate(CoordinateFloat* coord)
{
	return coordinateState->CheckQuad(coord);
}

bool Checker::CheckContactCoordinate(CoordinateInt* coord)
{
	return CheckContactCoordinate(coord->X, coord->Y);
}

bool Checker::CheckBeatCoordinate(CoordinateFloat* coordinate)
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

	return false;
}

bool Checker::CheckWalkCoordinate(CoordinateFloat* coordinate)
{
	//ОБЯЗАТЕЛЬНО ПЕРЕОПРЕДЕЛИТЬ!!!!!!!!!!!!!!!!!!
	coordinateCheck->Set(coordinateState->X + 0.25f,coordinateState->Y + 0.25f);
	if(coordinateCheck->CheckQuad(coordinate))
		return true;

	coordinateCheck->Set(coordinateState->X - 0.25f, coordinateState->Y + 0.25f);
	if (coordinateCheck->CheckQuad(coordinate))
		return true;

	return false;
}

void Checker::SetState(StateChecker state_)
{
	if(state != notdraw)
	{
		state = state_;
	}

	if (state_ == selected)
	{
		coordinateState->Set(coordinateDraw);
	}
	
}
