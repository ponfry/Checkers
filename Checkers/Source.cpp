#include "glew.h" 
#include "glut.h" 
#include <iostream>
#include "Helper.h"
#include "il.h"
using namespace std;

struct Size
{
	int weigth;
	int height;
}size;

float coordinateX = 0;
float coordinateY = 0;

struct Characteristc
{
	ILubyte* texture;
	ILuint width;
	ILuint height;
	ILuint type;
	ILuint format;
};

ILuint images;
Characteristc characteristics;
unsigned int* textures;

void TextureInitialization()
{
	textures = new unsigned int;
	ilGenImages(1, &images);

	ilBindImage(images);
	ilLoadImage(L"texture.jpg");
	characteristics.texture = ilGetData();
	characteristics.width = ilGetInteger(IL_IMAGE_WIDTH);
	characteristics.height = ilGetInteger(IL_IMAGE_HEIGHT);
	characteristics.type = ilGetInteger(IL_IMAGE_TYPE);
	characteristics.format = ilGetInteger(IL_IMAGE_FORMAT);
	glGenTextures(1, textures);
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, characteristics.width, characteristics.height, 0, characteristics.format, characteristics.type, characteristics.texture);
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(coordinateX, coordinateY);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2f(coordinateX + 0.5, coordinateY);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(coordinateX + 0.5, coordinateY + 0.5);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2f(coordinateX, coordinateY + 0.5);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();


	
	/*glViewport(0, 0, WindowSize::Weigth, WindowSize::Heigth);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glEnd();
*/
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

void display1()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, characteristics.width, characteristics.height, 0, characteristics.format, characteristics.type, characteristics.texture);
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(coordinateX, coordinateY);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2f(coordinateX + 0.5, coordinateY);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(coordinateX + 0.5, coordinateY + 0.5);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2f(coordinateX, coordinateY + 0.5);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
	glutSwapBuffers();
}


void Init(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	
	glutInitWindowSize(WindowSize::Weigth, WindowSize::Heigth);
	
	glutCreateWindow("Test Window");
	ilInit(); //Инициализация библиотеки
	TextureInitialization();
}



void main(int argc, char* argv[])
{
	Init(argc, argv);

	glutDisplayFunc(display);
	glewInit();
	glutMainLoop();
}