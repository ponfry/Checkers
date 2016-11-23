#include <iostream>
#include <windows.h>
#include "glew.h"
#include "glut.h"
#include "WindowSize.h"
#include "ChessBoard.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"
#include "Texture.h"
#include "FlagsPlayer.h"
#include "PlayerOne.h"
#include "PlayerTwo.h"
using namespace std;

ChessBoard* chess_board;
PlayerTwo* playerTwo;
PlayerOne* playerOne;
DrawTexture* drawErrorWrong;
float X, Y;


void Textout(char* str, float X, float Y, float phi = 0.02)
{
	int i = 2;
	glRasterPos2f(X, Y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[0]);

	while (str[i - 1] != '\0')
	{
		glRasterPos2f(X + i * phi, Y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i - 1]);
		i++;
	}
}

void Textout(char* str, CoordinateFloat coordf, float phi = 0.02)
{
	Textout(str, coordf.X, coordf.Y, phi);
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	
	X = (-2) * (window_size.Weigth / 2.0 - 163) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 33) / window_size.Heigth;

	glColor3f(1.0f, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(X, 1.0f);
	glVertex2f(-1.0f, Y);
	glVertex2f(X, Y);
	glEnd();
	X = (-2) * (window_size.Weigth / 2.0 - 50) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 25) / window_size.Heigth;
	glColor3f(0, 0, 1);
	Textout("Menu", X, Y);

	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();

	glutSwapBuffers();
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();

	X = (-2) * (window_size.Weigth / 2.0 - 163) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 33) / window_size.Heigth;

	glColor3f(1.0f, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(X, 1.0f);
	glVertex2f(-1.0f, Y);
	glVertex2f(X, Y);
	glEnd();
	X = (-2) * (window_size.Weigth / 2.0 - 50) / window_size.Weigth;
	Y = 2 * (window_size.Heigth / 2.0 - 25) / window_size.Heigth;
	glColor3f(0, 0, 1);
	Textout("Menu", X, Y);

	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();

	glutSwapBuffers();
	
}

void reDraw()
{
	chess_board->Draw();
	playerOne->Draw();
	playerTwo->Draw();
	glutSwapBuffers();
}

void drawError()
{
	Texture::LoadDraw(drawErrorWrong);
	
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(-0.5f, -0.25f);

	glTexCoord2f(0, 0);
	glVertex2f(-0.5f, 0.25f);

	glTexCoord2f(1, 1);
	glVertex2f(0.5f, -0.25f);

	glTexCoord2f(1, 0);
	glVertex2f(0.5f, 0.25f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glutSwapBuffers();
	Sleep(1150);
}

void mouseActive(int x, int y)
{
	coordinateMouseMove.Set(x, y);
	reDraw();
}	

void mousePassive(int x, int y)
{
	coordinateMousePassiveMove.Set(x, y);
	if (playerTwo->CheckCoordinatePassive() || playerOne->CheckCoordinatePassive())
	{
		reDraw();
	}	

	char title[20];
	sprintf_s(title, "%d x %d", coordinateMousePassiveMove.X, coordinateMousePassiveMove.Y);
	glutSetWindowTitle(title);
}

void ChangeWH(int w, int h)
{
	if (w > 500 && h > 300)
	{
		if (((h - w / 2.26 - 33) / 2.0) > 1)
		{
			window_size.Set(w, h);
		}
		else
		{
			glutReshapeWindow(window_size.Weigth, window_size.Heigth);
		}
	}
	else
	{
		window_size.Set(501, 301);
		glutReshapeWindow(window_size.Weigth, window_size.Heigth);
	}
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		coordinateMouseMove.Set(x,y);
		flags_player_one.CaptureChecker = playerOne->SetStateSelectChecker();
		flags_player_two.CaptureChecker = playerTwo->SetStateSelectChecker();	
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(flags_player_one.CaptureChecker|| flags_player_two.CaptureChecker)
		{
			if (flags_player_one.CaptureChecker)
			{
				coordinateMouseMove.Set(x, y);
				flags_player_one.CheckChessBoardCoordinate = chess_board->CheckCoordinate();
				flags_player_one.IsConflictOtherPlayerCheckers = playerTwo->CheckÑonflictCoordinateCheckers(chess_board->GetEntryCoordinate());
				if (flags_player_one.CheckChessBoardCoordinate && !flags_player_one.IsConflictOtherPlayerCheckers)
				{
					flags_player_one.WasSetCoordinateChecker =
						playerOne->SetCoordinateSelectedChecker(chess_board->GetEntryCoordinate());
				}
				if (!flags_player_one.CheckAll())
				{
					playerOne->SetStateUnSelectChecker();
					drawError();
				}
			}

			if (flags_player_two.CaptureChecker)
			{
				coordinateMouseMove.Set(x, y);
				flags_player_two.CheckChessBoardCoordinate = chess_board->CheckCoordinate();
				flags_player_two.IsConflictOtherPlayerCheckers = playerOne->CheckÑonflictCoordinateCheckers(chess_board->GetEntryCoordinate());

				if (flags_player_two.CheckChessBoardCoordinate && !flags_player_two.IsConflictOtherPlayerCheckers)
				{
					flags_player_two.WasSetCoordinateChecker =
						playerTwo->SetCoordinateSelectedChecker(chess_board->GetEntryCoordinate());
				}
				if (!flags_player_two.CheckAll())
				{
					playerTwo->SetStateUnSelectChecker();
					drawError();
				}
			}
		}
	}
	reDraw();
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	playerTwo = new PlayerTwo();
	playerOne = new PlayerOne();
	chess_board = new ChessBoard();
	drawErrorWrong = Texture::Init(L"errors/ErrorWrongMove.png");
	glutMotionFunc(mouseActive);
	glutPassiveMotionFunc(mousePassive);
	glutMouseFunc(mouse);
	glutDisplayFunc(init);
	glutReshapeFunc(ChangeWH);
	glewInit();
	glutMainLoop();
}