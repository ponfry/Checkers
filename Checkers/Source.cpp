#include <iostream>
#include "glew.h"
#include "glut.h"
#include "ChessBoard.h"
#include "Helper.h"


using namespace std;


void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, WindowSize::Weigth, WindowSize::Heigth);	
	ChessBoard chess_board;

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	chess_board.Draw();
	

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
void main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);

	glutInitWindowSize(WindowSize::Weigth, WindowSize::Heigth);

	glutCreateWindow("Test Window");
	ilInit();

	glutMotionFunc(mouse);
	glutPassiveMotionFunc(mouse);
	glutEntryFunc(enter);
	glutDisplayFunc(display);
	glewInit();
	glutMainLoop();
}