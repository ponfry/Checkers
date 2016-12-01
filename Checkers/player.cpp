#include "player.h"
#include "CoordinateMouse.h"
#include "StateChecker.h"
#include <ostream>
#include <iostream>
#include <windows.h>
#include "ControlMatrix.h"


Player::Player()
{
	CountCheckers = 12;
	checker = new CheckerWhite[CountCheckers+1];	
	InitChecker();	
}

void Player::Draw()
{
	for(int i=0; i<CountCheckers; i++)
	{
		checker[i].Draw();
	}
}

bool Player::SetStateSelectChecker()
{
	CheckCheckers();

	if (indexSelected < CountCheckers && indexSelected >= 0)
	{
		checker[indexSelected].SetState(selected);
		checker[12] = checker[indexSelected];
		checker[indexSelected] = checker[11];
		checker[11] = checker[12];

		return true;
	}
	return false;
}

void Player::SetStateUnSelectChecker()
{
	if (indexSelected < CountCheckers && indexSelected >= 0)
		checker[11].SetState(draw);
}

bool Player::CheckCoordinatePassive()
{
	delete checkCoordf;
	checkCoordf = MyMouse::ConvertIntTOFloatForBoard(coordinateMousePassiveMove.X,
		coordinateMousePassiveMove.Y);
	for (int i = 0; i < CountCheckers; i++)
	{
		if (checker[i].CheckContactCoordinate(checkCoordf))
		{
			checker[i].SetState(light);
			return true;
		}
		checker[i].SetState(draw);
	}
	return false;
}

void Player::InitChecker()
{
	int count = 0, i = 0;
	float x = -0.875, y = -0.875f;


	while (y <= -0.375f)
	{
		while (x < 1.0f)
		{
			checker[i].SetCoordinate(x, y);
			x += 0.5f;
			i++;
		}
		count++;
		if (count % 2 == 0)
		{
			x = -0.875f;			
		}
		else
		{
			x = -0.625f;
		}
		y += 0.25f;

		if (count == 3)
		{
			break;
		}
	}
}

void Player::CheckCheckers()
{
	for(int i = 0; i < CountCheckers; i++)
	{
		if(checker[i].CheckContactCoordinate(&coordinateMouseMove))
		{
			indexSelected = i;
			return;
		}
	}
	indexSelected = 12;
}

bool Player::SetStateNotDrawChecker()
{
	for (int i = 0; i < CountCheckers; i++)
	{
		if (checker[i].GetCurrentCoordinate() != nullptr &&
			checker[i].GetCurrentCoordinate()->operator==(&coordinateNotDrawChecker))
		{
			checker[i].SetState(notdraw);
			return true;
		}
	}
	return false;
}

void Player::ControlMovesCheckers()
{
	for (int i = 0; i < CountCheckers; i++)
	{
		checker[i].ControlMove();
	}
}

bool Player::SetNewCoordinateChecker(CoordinateFloat *coordinate)
{	
	if (CheckСonflictCoordinateCheckers(coordinate))
	{
		return false;
	}

	bool resultB = false, ismove = false;
	int* moves = new int[11];
	int j = 0;
	for (int i = 0; i < 12; i++)
	{
		if (checker[i].HaveBeatMove())
		{
			if (i != 11)
			{
				moves[j] = i;
				j++;
			}
			if(i==11)
				ismove = true;
		}
	}
	if ((j == 0) && !ismove)
	{
		if (checker[11].CheckMove(coordinate))
		{
			checker[11].SetCoordinate(coordinate->X, coordinate->Y);
			checker[11].SetState(draw);
			delete coordinate;

			resultB = true;
		}
	}
	else
	{
		if (ismove)
		{
			if (checker[11].CheckMove(coordinate))
			{
				CoordinateFloat* begin = checker[11].GetCurrentCoordinate();
				coordinateNotDrawChecker.Set(begin->X - (begin->X - coordinate->X) / 2.0,
					begin->Y - (begin->Y - coordinate->Y) / 2.0);
				if(ControlMatrix::GetStateForGameField(
					ControlMatrix::GetCoordinateForMatrix(&coordinateNotDrawChecker))
						== flags->Enemy)
				{
					flags->WasBeat = true;

					checker[11].SetCoordinate(coordinate->X, coordinate->Y);
					checker[11].SetState(draw);

					delete coordinate;
					delete begin;
					resultB = true;
				}
				else
				{
					flags->MustBeat = true;
				}
				
			}
		}
		else
		{
			flags->MustBeat = true;
			return false;
		}
	}

	return resultB;
}

bool Player::CheckСonflictCoordinateCheckers(CoordinateFloat* coordinate)
{
	if (coordinate == nullptr)
	{
		return false;
	}
	for (int i = 0; i < CountCheckers; i++)
	{
		if (checker[i].CheckContactCoordinate(coordinate))
		{
			return true;
		}
	}
	return false;
}

int Player::ControlCheckers()
{
	int count = 0;
	for (int i = 0; i < CountCheckers; i++)
	{
		 if(checker[i].GetState() == notdraw)
		 {
			 count++;
		 }
	}
	return count;
}
