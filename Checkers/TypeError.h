#pragma once

enum TypeErrors
{
	wrongMove=0,
	beatMove, 
	endGame
};
__declspec(selectany) TypeErrors type_errors;