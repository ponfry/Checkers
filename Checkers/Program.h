#pragma once
#include "CoordinateFloat.h"
#include "checker.h"
#include "ChessBoard.h"

class Program
{
public:
	void Run(int argc, char* argv[]);
	Program();
private:
	void Textout(char*, float, float, float phi = 0.02);
	void Textout(char*, CoordinateFloat, float phi = 0.02);
	void Init();
	void reDraw();
	void SetCoordinateMouse(int, int);
	void ChangeWH(int, int);
	int i;
	ChessBoard* chess_board;
	Checker* checker;
	float X, Y;
};

