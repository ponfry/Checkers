#pragma once
#include "il.h"
#include "Helper.h"

class ChessBoard
{
public:
	void Draw() const;
	ChessBoard();
private:
	::Draw* draw;
};
