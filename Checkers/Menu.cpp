#include "Menu.h"
#include "WindowSize.h"
#include "glew.h"
#include "glut.h"
#include "DrawTexture.h"
#include "Texture.h"
#include "CoordinateInt.h"
#include "CoordinateMouse.h"
#include "FlagsGame.h"
#include "TypeError.h"
#include "MyErrors.h"

Menu::Menu()
{
	beginMenu = new ItemMenu[3];
	gameMenu = new ItemMenu[4];
	Init();
}

bool Menu::CheckContactCoordinate()
{
	CoordinateFloat* coordinate = MyMouse::ConvertIntToFloat(&coordinateMousePassiveMove);
	if (state != drawing)
	{
		for (int i = 0; i < 4; i++)
		{
			if (gameMenu[i].coordinate->CheckRectangle(coordinate))
			{
				gameMenu[i].state = lighting;
				delete coordinate;
				return true;
			}
			gameMenu[i].state = drawing;
		}
		
	}
	else
	{
		if(gameMenu[0].coordinate->CheckRectangle(coordinate))
		{
			gameMenu[0].state = lighting;
			delete coordinate;
			return true;
		}
	}
	delete coordinate;
	return false;
}

void Menu::ControlPassive()
{
	if (!flags_game.EndGame)
	{
		if(CheckContactCoordinate())
			DrawGameMenu();
	}
	else
	{
		Errors::Draw(endGame);
	}
}

void Menu::DrawBegin()
{
}

void Menu::DrawGameMenu()
{
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);
	switch (state)
	{
	case drawing:
	case selecting:
		Texture::LoadDraw(menuDrawing);
		break;
	case lighting:
		Texture::LoadDraw(menuDrawing);
		break;
	}
	//создать itemMenu нормальный и настроить отрисовку

	float X = (-2) * (window_size.Weigth / 2.0 - 200) / window_size.Weigth;
	float Y = 2 * (window_size.Heigth / 2.0 - 40) / window_size.Heigth;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 0);
	glVertex2f(-1.0f, 1.0f);

	glTexCoord2f(1, 0);
	glVertex2f(X, 1.0f);

	glTexCoord2f(0, 1);
	glVertex2f(-1.0f, Y);

	glTexCoord2f(1, 1);
	glVertex2f(X, Y);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void Menu::DrawEndGame()
{
}

void Menu::SetState(MenuState _state)
{
	state = _state;
}

void Menu::Init()
{
	float X = (-2) * (window_size.Weigth / 2.0 - 200) / window_size.Weigth;
	float Y = 2 * (window_size.Heigth / 2.0 - 40) / window_size.Heigth;
	float offset = 2 * (window_size.Heigth / 2.0 - 40) / window_size.Heigth;

	for (int i = 0; i < 4; i++)
	{
		gameMenu[i].coordinate = new CoordinateFloat;
		gameMenu[i].coordinate->Set(X, Y + offset*i);
	}	
}
