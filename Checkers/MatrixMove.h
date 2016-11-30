#pragma once
enum StateGameField
{
	incorrect = 0,
	white,
	black,
	freely
};

__declspec(selectany) StateGameField MatrixGameField[8][8];
__declspec(selectany) int SizeMatrix = 8 ;

