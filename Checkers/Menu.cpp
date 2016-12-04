#include "Menu.h"
#include "WindowSize.h"
#include "glew.h"
#include "DrawTexture.h"
#include "Texture.h"
#include "CoordinateInt.h"
#include "FlagsGame.h"
#include "TypeError.h"
#include "MyErrors.h"
#include "CoordinateFloat.h"
#include "CoordinateMouse.h"

Menu::Menu()
{
	beginMenu = new ItemMenu[3];
	gameMenu = new ItemMenu[4];
	endMenu = new ItemMenu;

	X = -900 / (window_size.Weigth*1.0f);
	Y = 570 / (window_size.Heigth*1.0f);
	offset = 80 / (window_size.Heigth *1.0f);

	Xi = window_size.Weigth / 13;
	Yi = window_size.Heigth / 32.5;
	offseti = window_size.Heigth / 16.25;
	menu.Init();
}

bool Menu::CheckContactCoordinate()
{
	bool result = false;

	switch (gameMenu[0].state)
	{
	case drawing:
		if (gameMenu[0].coordinate->CheckRectangle(&coordinateMousePassiveMove))
		{
			gameMenu[0].state = lighting;
			result = true;
		}

		for (int i = 1; i < 3; i++)
		{
			gameMenu[i].state = notDrawing;
		}

		return result;

	case lighting:
		gameMenu[0].state = drawing;

		if (gameMenu[0].coordinate->CheckRectangle(&coordinateMousePassiveMove))
		{
			gameMenu[0].state = lighting;
			result = true;
		}

		for (int i = 1; i < 3; i++)
		{
			gameMenu[i].state = notDrawing;
		}

		return result;

	case selecting:

		if (!gameMenu[0].coordinate->CheckRectangle(&coordinateMousePassiveMove))
		{
			bool flag = false;
			for (int i = 1; i < 3; i++)
			{
				if (gameMenu[i].coordinate->CheckRectangle(&coordinateMousePassiveMove))
				{
					flag = true;
				}
			}

			if (!flag)
			{
				gameMenu[0].state = drawing;
				return false;
			}
		}

		for (int i = 1; i < 3; i++)
		{
			gameMenu[i].state = drawing;

			if (gameMenu[i].coordinate->CheckRectangle(&coordinateMousePassiveMove))
			{
				gameMenu[i].state = lighting;
			}
		}
		break;
	default: break;
	}	
	return result;
}

void Menu::ControlPassive()
{
	if (!flags_game.EndGame)
	{
		CheckContactCoordinate();
		DrawGameMenu();
	}
	else
	{
		endMenu->state = drawing;
		CoordinateFloat *coord = MyMouse::ConvertIntToFloat(&coordinateMousePassiveMove);
		if ((coord->X > -0.3f && coord->X < 0.3f) &&
			(coord->Y > -0.2f && coord->Y < 0.0f))
		{
			endMenu->state = lighting;
		}
	}
}

void Menu::CaptureItemMenu()
{
	if (!flags_game.EndGame)
	{
		SetStateSelect();
	}
	else
	{
		CoordinateFloat *coord = MyMouse::ConvertIntToFloat(&coordinateMousePassiveMove);
		if ((coord->X > -0.3f && coord->X < 0.3f) &&
			(coord->Y > -0.2f && coord->Y < 0.0f))
		{
			flags_game.NewGame = true;
		}
	}
}

void Menu::SetNewCoordinate()
{
	Xi = window_size.Weigth / 13;
	Yi = window_size.Heigth / 32.5;
	offseti = window_size.Heigth / 16.25;

	for (int i = 0; i < 3; i++)
	{
		gameMenu[i].coordinate->Set(Xi, Yi + offseti*i);
	}
	endMenu->coordinate->Set(window_size.Weigth / 2, window_size.Heigth / 2);
}

void Menu::DrawBegin()
{
}

void Menu::DrawGameMenu()
{
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);
	
	for (int i = 0; i < 3; i++)
	{
		switch (gameMenu[i].state)
		{
		case drawing:
			Texture::LoadDraw(gameMenu[i].drawed);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case selecting:
		case lighting:
			Texture::LoadDraw(gameMenu[i].lighted);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case notDrawing:
			glColor3f(0.9f, 0.9f, 0.9f);
			break;

		default: break;
		}
		
		

		
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(0, 0);
		glVertex2f(-1.0f, 1.0f - offset*i);

		glTexCoord2f(1, 0);
		glVertex2f(X, 1.0f - offset*i);

		glTexCoord2f(0, 1);
		glVertex2f(-1.0f, Y - offset*i);

		glTexCoord2f(1, 1);
		glVertex2f(X, Y - offset*i);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}
	
}

void Menu::DrawEndGame()
{
	switch (endMenu->state)
	{
	case drawing:
		Texture::LoadDraw(endMenu->drawed);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case selecting:
	case lighting:
		Texture::LoadDraw(endMenu->lighted);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case notDrawing:
		return;
		break;

	default: break;
	}


	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 0);
	glVertex2f(-0.3f, 0.0f);

	glTexCoord2f(1, 0);
	glVertex2f(0.3f, 0.0f);

	glTexCoord2f(0, 1);
	glVertex2f(-0.3f, -0.2f);

	glTexCoord2f(1, 1);
	glVertex2f(0.3f, -0.2f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void Menu::SetState(MenuState _state)
{
	gameMenu[0].state = _state;
}

void Menu::SetStateSelect()
{
	if (!flags_game.EndGame)
	{
		if (gameMenu[0].coordinate->CheckRectangle(&coordinateMouseMove))
		{
			gameMenu[0].state = selecting;

			for (int i = 1; i < 3; i++)
			{
				gameMenu[i].state = drawing;
			}
		}
		else
		{
			bool flag = false;
			for (int i = 1; i < 3; i++)
			{
				if (gameMenu[i].coordinate->CheckRectangle(&coordinateMouseMove))
				{
					gameMenu[i].state = selecting;
					switch (i)
					{
					case 1:
						flags_game.NewGame = true;
						break;
					case 2:
						flags_game.Continue = true;
						break;
					default :
						break;
					}
					flag = true;
				}
			}

			if (!flag)
			{
				gameMenu[0].state = drawing;
			}
		}
	}
}

void Menu::Init()
{
	for (int i = 0; i < 3; i++)
	{
		gameMenu[i].coordinate = new CoordinateInt;
		gameMenu[i].state = notDrawing;
		gameMenu[i].coordinate->Set(Xi, Yi + offseti*i);
	}	
	gameMenu[0].state = drawing;
	gameMenu[0].SetTexture(menuDrawing, menuLighting);
	gameMenu[1].SetTexture(newGameDrawing, newGameLighting);
	gameMenu[2].SetTexture(continueDrawing, continueLighting);

	endMenu->coordinate = new CoordinateInt;
	endMenu->coordinate->Set(window_size.Weigth / 2, window_size.Heigth / 2);
	endMenu->state = notDrawing;
	endMenu->SetTexture(newGameDrawing, newGameLighting);
}
