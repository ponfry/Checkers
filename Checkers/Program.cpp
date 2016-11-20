#include "Program.h"
#include "glew.h"
#include "glut.h"
#include "WindowSize.h"

void Program::Run(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
//	glutCreateWindow("Checkers");
//
//	ilInit();
//	checker = new Checker(2);
//	chess_board = new ChessBoard();
//	glutMotionFunc(SetCoordinateMouse);
//	//glutPassiveMotionFunc(mouse);
//	glutDisplayFunc(Init);
//	glutReshapeFunc(ChangeWH);
//	glewInit();
//	glutMainLoop();
{}


Program::Program()
{
	chess_board = new ChessBoard();
	checker = new Checker();
}

void Program::Textout(char* str, float X, float Y, float phi)
{
	i = 2;
	glRasterPos2f(X, Y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[0]);

	while (str[i - 1] != '\0')
	{
		glRasterPos2f(X + i * phi, Y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i - 1]);
		i++;
	}	
}

void Program::Textout(char* str, CoordinateFloat coordf, float phi)
{
	Textout(str, coordf.X, coordf.Y, phi);
}

void Program::Init()
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

void Program::reDraw()
{
	chess_board->Draw();
	checker->Draw();
	glutSwapBuffers();
}

void Program::SetCoordinateMouse(int x, int y)
{
	coordinateMouse.Set(x, y);
	checker->SetCoordinate(coordinateMouse);

	reDraw();
}
