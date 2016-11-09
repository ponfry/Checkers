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
Checker checker(&windowSize);
Coordinate coordinate;


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
	
	chess_board.Draw(windowSize);
	checker.Draw(coordinate);	
	
	glutSwapBuffers();
}

void mouse(int x, int y)
{
	coordinate.Set(x, y);	
	glutPostRedisplay();


}

void enter(int state)
{
	cout << state << endl;
}

void ChangeWH(int w, int h)
{
	if (w > 500 && h > 300)
	{
		windowSize.Set(w, h);		
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
	
	glutCreateWindow("Test Window");
	ilInit();
	glutMotionFunc(mouse);
	//glutPassiveMotionFunc(mouse);
	glutEntryFunc(enter);
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeWH);
	glewInit();
	glutMainLoop();
}