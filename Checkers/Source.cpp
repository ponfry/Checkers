#include "glew.h" 
#include "glut.h" 
#include <iostream>
#include "Helper.h"
#include "il.h"
using namespace std;

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

ILuint *images = new ILuint[2];
Characteristc characteristics1, characteristics2, result;
unsigned int* textures;

class Texture
{
public:	
	static unsigned int* Init ()
	{
		unsigned int* textures = new unsigned int[2];
		ilGenImages(2, images);

		characteristics1 = Load(L"bumaga.jpg", images[0]);
		characteristics2 = Load(L"metall.jpg", images[1]);

		glGenTextures(2, textures);
		
		return textures;
	}
private:
	static Characteristc Load(const wchar_t *filename, ILuint image)
	{
		ilBindImage(image);
		ilLoadImage(filename);
		result.texture = ilGetData();
		result.width = ilGetInteger(IL_IMAGE_WIDTH);
		result.height = ilGetInteger(IL_IMAGE_HEIGHT);
		result.type = ilGetInteger(IL_IMAGE_TYPE);
		result.format = ilGetInteger(IL_IMAGE_FORMAT);
		return result;
	}
};

void display()
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glViewport(0, 0, WindowSize::Weigth, WindowSize::Heigth);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, characteristics1.width, characteristics1.height, 0, characteristics1.format, characteristics1.type, characteristics1.texture);
	
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0, 1);
	glVertex2f(-1.0f, -1.0f);
	glTexCoord2f(0, 0);
	glVertex2f(-1.0f, 1.0f);
	glTexCoord2f(1, 1);
	glVertex2f(1.0f, -1.0f);
	glTexCoord2f(1, 0);
	glVertex2f(1.0f, 1.0f);
	glEnd();
	
	glViewport(350, 100, 300, 300);
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
	glutDisplayFunc(display);
	glewInit();
	glutMainLoop();
}