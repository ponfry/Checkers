#include <iostream>
#include "Texture.h"
#include "glut.h"
using namespace std;

unsigned int* textures;

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glViewport(0, 0, WindowSize::Weigth, WindowSize::Heigth);	

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();

	glViewport(350, 100, 300, 300);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, characteristics2.width, characteristics2.height, 0, characteristics2.format, characteristics2.type, characteristics2.texture);
	
	int count = 0;
	float x = -0.75, y = -1.0;	

	while (y < 1.0f)
	{
		while (x < 1.0f)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0, 1);
			glVertex2f(x, y);

			glTexCoord2f(0, 0);
			glVertex2f(x, y + 0.25f);

			glTexCoord2f(1, 1);
			glVertex2f(x + 0.25f, y);

			glTexCoord2f(1, 0);
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
	glDisable(GL_TEXTURE_2D);

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
	ilInit(); //Инициализация библиотеки
	textures = Texture::Init();
	glutMotionFunc(mouse);
	glutPassiveMotionFunc(mouse);
	glutEntryFunc(enter);
	glutDisplayFunc(display);
	glewInit();
	glutMainLoop();
}