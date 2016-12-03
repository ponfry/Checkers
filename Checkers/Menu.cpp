#include "Menu.h"
#include "WindowSize.h"
#include "glew.h"
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
	X = (-2) * (window_size.Weigth / 2.0 - 100) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 20) / window_size.Heigth;
	offset = 1.0f - 2 * (window_size.Heigth / 2.0 - 40) / window_size.Heigth;
	menu.Init();
}

bool Menu::CheckContactCoordinate()
{
	CoordinateFloat* coordinate = MyMouse::ConvertIntToFloat(&coordinateMousePassiveMove);
	bool result = false;

	switch (gameMenu[0].state)
	{
	case drawing:
		if (gameMenu[0].coordinate->CheckRectangle(coordinate))
		{
			gameMenu[0].state = lighting;
			result = true;
		}

		for (int i = 1; i < 3; i++)
		{
			gameMenu[i].state = notDrawing;
		}

		delete coordinate;
		return result;

	case lighting:
		gameMenu[0].state = drawing;

		if (gameMenu[0].coordinate->CheckRectangle(coordinate))
		{
			gameMenu[0].state = lighting;
			result = true;
		}

		for (int i = 1; i < 3; i++)
		{
			gameMenu[i].state = notDrawing;
		}

		delete coordinate;
		return result;

	case selecting:

		if (!gameMenu[0].coordinate->CheckRectangle(coordinate))
		{
			bool flag = false;
			for (int i = 1; i < 3; i++)
			{
				if (gameMenu[i].coordinate->CheckRectangle(coordinate))
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

			if (gameMenu[i].coordinate->CheckRectangle(coordinate))
			{
				gameMenu[i].state = lighting;
			}
		}
		break;
	default: break;
	}	
	delete coordinate;
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
		Errors::Draw(endGame);
	}
}

void Menu::CaptureItemMenu()
{
	if (!flags_game.EndGame)
	{
		SetStateSelect();
	}
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
			glColor3f(0.9, 0.9, 0.9);
			break;

		default: break;
		}
		
		X = (-2) * (window_size.Weigth / 2.0 - 200) / window_size.Weigth;
		Y = 2 * (window_size.Heigth / 2.0 - 40) / window_size.Heigth;

		
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
}

void Menu::SetState(MenuState _state)
{
	gameMenu[0].state = _state;
}

void Menu::SetStateSelect()
{
	if (!flags_game.EndGame)
	{
		CoordinateFloat* coordinate = MyMouse::ConvertIntToFloat(&coordinateMouseMove);

		if (gameMenu[0].coordinate->CheckRectangle(coordinate))
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
				if (gameMenu[i].coordinate->CheckRectangle(coordinate))
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
		gameMenu[i].coordinate = new CoordinateFloat;
		gameMenu[i].state = notDrawing;
		gameMenu[i].coordinate->Set(X, Y - offset*i);
	}	
	gameMenu[0].state = drawing;
	gameMenu[0].SetTexture(menuDrawing, menuLighting);
	gameMenu[1].SetTexture(newGameDrawing, newGameLighting);
	gameMenu[2].SetTexture(continueDrawing, continueLighting);
}
