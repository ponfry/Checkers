#pragma once
#include <iostream>
#include "glew.h"
#include "glut.h"
#include "ChessBoard.h"
#include "Helper.h"
#include "Texture.h"
using namespace std;
WindowSize windowSize, chessWindowSize;
ChessBoard chess_board;

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
	
	DrawTexture* draw_texture = Texture::Init(L"texture/checker.png");
	glActiveTexture(GL_TEXTURE0);


	glBindTexture(GL_TEXTURE_2D, draw_texture->textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, draw_texture->characteristic->width, draw_texture->characteristic->height,
		0, draw_texture->characteristic->format, draw_texture->characteristic->type, draw_texture->characteristic->texture);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, draw_texture->textures[0]);
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(0.25, 0);

	glTexCoord2f(0, 0);
	glVertex2f(0.25, 0.25f);

	glTexCoord2f(1, 1);
	glVertex2f( 0.5f, 0);

	glTexCoord2f(1, 0);
	glVertex2f( 0.5f, 0.25f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glutSwapBuffers();
}

void mouse(int x, int y)
{
	cout << x << "---" << y<< endl;
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
	//glutMotionFunc(mouse);
	//glutPassiveMotionFunc(mouse);
	//glutEntryFunc(enter);
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeWH);
	glewInit();
	glutMainLoop();
}