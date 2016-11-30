#include "player.h"
#include "CoordinateMouse.h"
#include "StateChecker.h"
#include <ostream>
#include <iostream>
int CountCheckers = 12;
Player::Player()
{
	checker = new CheckerWhite[CountCheckers];
	Player::InitChecker();	
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
		result = checker[indexSelected];
		checker[indexSelected] = checker[11];
		checker[11] = result;
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

bool Player::SetWalkCoordinateSelectedChecker(CoordinateFloat* coordinate)
{
	if (coordinate == nullptr)
	{
		return false;
	}
	if (indexSelected < CountCheckers && indexSelected >= 0)
	{
		if(checker[11].CheckWalkCoordinate(coordinate) && 
			!CheckСonflictCoordinateCheckers(coordinate))
		{
			checker[11].SetCoordinate(coordinate->X, coordinate->Y);
			delete coordinate;
			checker[11].SetState(draw);
			return true;
		}		
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

bool Player::CheckСonflictCoordinateCheckers(CoordinateFloat* coordinate)
{
	if (coordinate == nullptr)
	{
		return false;
	}
	for (int i = 0; i < CountCheckers; i++)
	{
		if(checker[i].CheckContactCoordinate(coordinate))
		{
			return true;
		}
			
	}
	return false;
}

bool Player::SetBeatCoordinateSelectedChecker(CoordinateFloat* coordinate)
{
	if (coordinate == nullptr)
	{
		return false;
	}
	if (indexSelected < CountCheckers && indexSelected >= 0)
	{
		if (checker[11].CheckBeatCoordinate(coordinate) &&
			!CheckСonflictCoordinateCheckers(coordinate))
		{
			checker[11].SetCoordinate(coordinate->X, coordinate->Y);

			delete coordinate;
			checker[11].SetState(draw);
			return true;
		}
	}
	return false;
}

bool Player::SetStateNotDrawChecker(CoordinateFloat* coordinate)
{
	for (int i = 0; i < CountCheckers; i++)
	{
		if (checker[i].GetCurrentCoordinate() != nullptr &&
			checker[i].GetCurrentCoordinate()->operator==(coordinate))
		{
			checker[i].SetState(notdraw);
			return true;
		}
	}
	return false;
}

void Player::InitStartEndBeatCoordinate(CoordinateFloat* coordinate)
{
	CoordinateFloat* res = checker[11].GetCurrentCoordinate();
	startBeatCoordinateChecker.Set(res);
	delete res;

	endBeatCoordinateChecker.Set(coordinate);
}

void Player::ControlMovesCheckers()
{
	for (int i = 0; i < CountCheckers; i++)
	{
		checker[i].GetCountMove();
	}
}
