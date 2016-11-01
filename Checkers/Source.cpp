#include "glew.h" 
#include "glut.h" 
#include <iostream>
#include "Helper.h"
using namespace std;

struct Size
{
	int weigth;
	int height;
}size;

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, WindowSize::Weigth, WindowSize::Heigth);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.31f, -0.615f);
	glVertex2f(-0.31f, 0.615f);
	glVertex2f(0.31f, -0.615f);
	glVertex2f(0.31f, 0.615f);
	glEnd();
	
	glViewport(350, 100, 300, 300);

	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	

	int count = 0;
	float x = -0.75, y = -1.0;
	glColor3f(0.0, 0.0, 0.0);

	while (y < 1.0f)
	{
		while (x < 1.0f)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(x, y);
			glVertex2f(x, y + 0.25f);
			glVertex2f(x + 0.25f, y);
			glVertex2f(x + 0.25f, y + 0.25f);
			glEnd();
			x += 0.5f;
		}
		count++;
		if (count % 2 == 0)
		{
			x = -0.75f;
		}
		else
		{
			x = -1.0f;
		}
		y += 0.25f;
	}


	glutSwapBuffers();
}

void Init(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WindowSize::Weigth, WindowSize::Heigth);
	glutCreateWindow("Test Window");
}

void main(int argc, char* argv[])
{
	Init(argc, argv);

	glutDisplayFunc(display);
	glewInit();
	glutMainLoop();
}