#pragma once
#include "Helper.h"


class ChessBoard
{
public:
	void Draw(WindowSize*);
	ChessBoard();
private:
	DrawTexture* draw;
};
