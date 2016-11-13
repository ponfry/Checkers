#pragma once
#include <iostream>
#include "glew.h"
#include "glut.h"
#include "ChessBoard.h"
#include "Helper.h"
#include "Texture.h"
#include "checker.h"

using namespace std;

WindowSize windowSize, chessWindowSize;
ChessBoard chess_board;
Checker* checkerWhite;
Checker* checkerBlack;
Coordinate coordinate;
CoordinateF coordf;
MouseXY mouse_xy;
float X, Y;

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, windowSize.Weigth, windowSize.Heigth);		

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	
	X = (-2) * (windowSize.Weigth / 2.0 - 163) / windowSize.Weigth;
	Y = 2 * (windowSize.Heigth / 2.0 - 33) / windowSize.Heigth;

	glColor3f(1.0f, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(X, 1.0f);
	glVertex2f(-1.0f, Y);
	glVertex2f(X, Y);
	glEnd();

	chess_board.Draw(&windowSize);
	mouse_xy.Init(&windowSize);

	coordf = mouse_xy.ConvertIntTOFloat(coordinate.X, coordinate.Y);

	int count = 0;
	float x = -0.625f, y = -0.875f;
	
	
	while (y <= -0.375f)
	{
		while (x < 1.0f)
		{
			checkerBlack->Draw(x, y);
			x += 0.5f;
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
		if (count == 3)
		{
			count = 1;
			break;
		}
	}

	y = 0.375f;
	while (y <= 1.0f)
	{
		while (x < 1.0f)
		{
			checkerWhite->Draw(x, y);
			x += 0.5f;
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
		if (count == 4)
		{
			break;
		}
	}
		
	glutSwapBuffers();
}

void mouse(int x, int y)
{
	coordinate.Set(x, y);	
	glutPostRedisplay();
}

void enter(int state)
{

}

void ChangeWH(int w, int h)
{
	if (w > 500 && h > 300)
	{
		if (((h - w / 2.26 - 33) / 2.0) > 1)
		{
			windowSize.Set(w, h);
		}
		else
		{
			glutReshapeWindow(windowSize.Weigth, windowSize.Heigth);
		}
	}
	else
	{
		windowSize.Set(501, 301);
		glutReshapeWindow(windowSize.Weigth, windowSize.Heigth);
	}
	char title[20];
	sprintf_s(title, "%d x %d", w, h);
	glutSetWindowTitle(title);
}
void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(windowSize.Weigth, windowSize.Heigth);	
	glutCreateWindow("Checkers");

	ilInit();
	checkerWhite = new Checker(&windowSize, 2);
	checkerBlack = new Checker(&windowSize, 1);
	glutMotionFunc(mouse);
	//glutPassiveMotionFunc(mouse);
	glutEntryFunc(enter);
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeWH);
	glewInit();
	glutMainLoop();
}