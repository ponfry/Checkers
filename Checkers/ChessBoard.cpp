#include "glew.h"
#include "ChessBoard.h"
#include  "WindowSize.h"
#include "Texture.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"
#include "CoordinateMouse.h"


void ChessBoard::Draw() 
{
	glViewport(window_size.IndentX, window_size.IndentY,
		window_size.Board, window_size.Board);
	glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();

	Texture::LoadDraw(draw);

	for (int i = 0; i < 33; i++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(0, 1);
		glVertex2f(coordinate[i].X - 0.125f, coordinate[i].Y - 0.125f);

		glTexCoord2f(0, 0);
		glVertex2f(coordinate[i].X - 0.125f, coordinate[i].Y + 0.125f);

		glTexCoord2f(1, 1);
		glVertex2f(coordinate[i].X + 0.125f, coordinate[i].Y - 0.125f);

		glTexCoord2f(1, 0);
		glVertex2f(coordinate[i].X + 0.125f, coordinate[i].Y + 0.125f);
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}

void ChessBoard::Init()
{
	draw = Texture::Init(L"texture/metall.jpg");
	int count = 0, i = 0;
	float x = -0.625f, y = -0.875f;

	while (y <= 1.0f)
	{
		while (x < 1.0f)
		{
			coordinate[i].Set(x, y);
			x += 0.5f;
			i++;
		}
		count++;
		if (count % 2 == 0)
		{
			x = -0.625f;
		}
		else
		{
			x = -0.875f;
		}
		y += 0.25f;

		if (count == 8)
		{
			break;
		}
	}
}

bool ChessBoard::CheckCoordinate()
{
	CoordinateFloat* coordf = MyMouse::ConvertIntTOFloatForBoard(&coordinateMouseMove);

	for (int i = 0; i < 33; i++)
	{
		if(coordinate[i].CheckQuad(coordf))
		{			
			return true;
		}
	}
	return false;
}

CoordinateFloat* ChessBoard::GetEntryCoordinate()
{
	CoordinateFloat* coordf = MyMouse::ConvertIntTOFloatForBoard(&coordinateMouseMove);

	for (int i = 0; i < 33; i++)
	{
		if (coordinate[i].CheckQuad(coordf))
		{
			coordf->Set(&coordinate[i]);
			return coordf;
		}
	}
	delete coordf;
	return nullptr;
}

ChessBoard::ChessBoard()
{
	Init();
}
