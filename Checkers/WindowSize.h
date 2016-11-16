#pragma once

struct WindowSize
{
	int Weigth;
	int Heigth;
	int IndentX;
	int IndentY;
	int Board;
	int Board2;

	WindowSize()
	{
		Weigth = 1300;
		Heigth = 650;
		IndentX = 230;
		IndentY = 37;
		Board = 575;
		Board2 = Board / 2.0;
	}

	void Set(int weigth, int heigth)
	{
		Weigth = weigth;
		Heigth = heigth;
		Board = Weigth / 2.26;
		Board2 = Board / 2.0;
		IndentX = Board * 0.4;
		IndentY = (Heigth - Board - 33) / 2.0;
	}

	bool CheckBoardHeigth(int weigth, int heigth)
	{
		return true;
	}
};



__declspec(selectany) WindowSize window_size;