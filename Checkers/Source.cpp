#include <iostream>
#include <windows.h>
#include "glew.h"
#include "glut.h"

#include "WindowSize.h"
#include "FlagsGame.h"
#include "Game.h"
#include "MyErrors.h"

using namespace std;

Game game;

void mouseActive(int x, int y)
{
	coordinateMouseMove.Set(x, y);
	game.Redraw();
}	

void mousePassive(int x, int y)
{
	coordinateMousePassiveMove.Set(x, y);
	game.ControlPassive();	
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
}


void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		coordinateMouseMove.Set(x,y);
		game.CaptureCheckers();
	}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		coordinateMouseMove.Set(x, y);
		game.CheckPlayers();
	}
	if(flags_game.EndGame)
	{
		Errors::Draw(endGame);
	}
	else
	{
		game.Redraw();
	}
	
}


void init()
{
	if (flags_game.EndGame)
	{
		Errors::Draw(endGame);
	}
	else
	{
		game.InitDraw();
	}
}
void main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(window_size.Weigth, window_size.Heigth);
	glutCreateWindow("Checkers");

	ilInit();
	game.Init();

	glutMotionFunc(mouseActive);
	glutPassiveMotionFunc(mousePassive);
	glutMouseFunc(mouse);
	glutDisplayFunc(init);
	glutReshapeFunc(ChangeWH);
	glewInit();
	
	glutMainLoop();
	
}


/*char title[20];
sprintf_s(title, "%dx%dc%dx%d", window_size.Weigth, window_size.Heigth, coordinateMousePassiveMove.X, coordinateMousePassiveMove.Y);

glutSetWindowTitle(title);*/

//clock_t start, finish;
//start = clock();
//finish = clock();
//cout << "time=";
//cout << (finish - start) << endl;
