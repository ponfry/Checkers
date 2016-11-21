#include <iostream>
#include <windows.h>
#include "glew.h"
#include "glut.h"
#include "WindowSize.h"
#include "ChessBoard.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"
#include "player.h"
#include "Texture.h"
using namespace std;

ChessBoard* chess_board;
Player* player;
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
	player->Draw();

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
	player->Draw();

	glutSwapBuffers();
	
}

void reDraw()
{
	chess_board->Draw();
	player->Draw();
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
	Sleep(1500);
	reDraw();
}

void mouseActive(int x, int y)
{
	coordinateMouseMove.Set(x, y);
	reDraw();
}	

void mousePassive(int x, int y)
{
	coordinateMousePassiveMove.Set(x, y);
	if (player->CheckCoordinatePassive())
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
		player->SetStateSelectChecker();

		reDraw();
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		coordinateMouseMove.Set(x, y);
		if(chess_board->CheckCoordinate())
		{
			player->SetCoordinateSelectedChecker(chess_board->GetEntryCoordinate());
			reDraw();
		}
		else
		{
			player->SetStateUnSelectChecker();
			drawError();
		}
	}
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	player = new Player();
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