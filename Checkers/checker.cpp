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
		draw = Texture::Init(L"texture/checkerblack.png");
		break;
	case 2:
		draw = Texture::Init(L"texture/checkerwhite.png");
		break;
	default:
		draw = nullptr;
		break;
	}
}

void Checker::InitDraw()
{
	switch (state)
	{
	case StateChecker::draw:
		glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, draw->characteristic->width,
			draw->characteristic->height,
			0, draw->characteristic->format,
			draw->characteristic->type,
			draw->characteristic->texture);
		break;

	case StateChecker::select:
		glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, select->characteristic->width,
			select->characteristic->height,
			0, select->characteristic->format,
			select->characteristic->type,
			select->characteristic->texture);
		break;

	case StateChecker::lighting:
		glBindTexture(GL_TEXTURE_2D, draw->textures[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, lighting->characteristic->width,
			lighting->characteristic->height,
			0, lighting->characteristic->format,
			lighting->characteristic->type,
			lighting->characteristic->texture);
		break;
	default:
		break;
	}
}

void Checker::Print()
{
	switch(state)
	{
	case StateChecker::select:
		delete coordinateDraw;
		coordinateDraw = MyMouse::ConvertIntTOFloatForBoard(coordinateMouseMove.X,
			coordinateMouseMove.Y);
		break;
	default:
		coordinateDraw->Set(*coordinateState);
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

void Checker::SetCoordinate(CoordinateInt coord)
{
	SetCoordinate(coord.X, coord.Y);
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
	if(x < (coordinateState->X + 0.125f) && x > (coordinateState->X - 0.125f)
		&& y < (coordinateState->Y + 0.125f) && y > (coordinateState->Y - 0.125f))
	{

		return true;
	}	
	return false;
}

bool Checker::CheckCoordinate(int x, int y)
{
	CoordinateFloat *res = MyMouse::ConvertIntTOFloatForBoard(x, y);
	float X =res->X;
	float Y = res->Y;

	delete res;
	return CheckCoordinate(X, Y);
}

void Checker::SetState(StateChecker state_)
{
	if(state != StateChecker::notdraw)
	{
		state = state_;
	}

	if (state_ == StateChecker::select)
	{
		coordinateState->Set(*coordinateDraw);
	}
	
}
