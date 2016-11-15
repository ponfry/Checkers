#pragma once
#include "DrawTexture.h"

class ChessBoard
{
public:
	void Draw();
	ChessBoard();
private:
	DrawTexture* draw;
};
