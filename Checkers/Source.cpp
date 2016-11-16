#include <iostream>
#include "glew.h"
#include "glut.h"
#include <windows.h>
#include "WindowSize.h"
#include "Checker.h"
#include "ChessBoard.h"
#include "CoordinateInt.h"
#include "CoordinateFloat.h"
using namespace std;

ChessBoard* chess_board;
Checker* checker;
float X, Y;
int i;
void Textout(char* str, float x, float y, float phi = 0.02)
{
	i=2;
	glRasterPos2f(x, y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[0]);
	
	while(str[i-1] != '\0')
	{
		glRasterPos2f(x + i * phi, y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i-1]);
		i++;		
	}
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
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
	checker->Draw();

	glutSwapBuffers();
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, window_size.Weigth, window_size.Heigth);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
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
	checker->Draw();
	glutSwapBuffers();
	
}
void display()
{
	chess_board->Draw();
	checker->Draw();
	//Sleep(20);
	glutSwapBuffers();
}
void mouse(int x, int y)
{
	coordinateMouse.Set(x, y);	
	
	checker->SetCoordinate(coordinateMouse);
	
	display();
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
	char title[20];
	sprintf_s(title, "%d x %d", w, h);
	glutSetWindowTitle(title);
}
void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	checker = new Checker(2);
	chess_board = new ChessBoard();
	glutMotionFunc(mouse);
	//glutPassiveMotionFunc(mouse);
	glutEntryFunc(enter);
	glutDisplayFunc(init);
	glutReshapeFunc(ChangeWH);
	glewInit();
	glutMainLoop();
}