#include "player.h"
#include "CoordinateMouse.h"
#include "StateChecker.h"

Player::Player()
{
	checker = new CheckerWhite[12];
	Player::InitChecker();	
}

void Player::Draw()
{
	for(int i=0; i<12; i++)
	{
		checker[i].Draw();
	}
}

bool Player::SetStateSelectChecker()
{
	CheckCheckers();

	if (indexSelected < 12 && indexSelected >= 0)
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
	if (indexSelected < 12 && indexSelected >= 0)
		checker[11].SetState(draw);
}

bool Player::CheckCoordinatePassive()
{
	delete checkCoordf;
	checkCoordf = MyMouse::ConvertIntTOFloatForBoard(coordinateMousePassiveMove.X,
		coordinateMousePassiveMove.Y);
	for (int i = 0; i < 12; i++)
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

bool Player::SetCoordinateSelectedChecker(CoordinateFloat* coordinate)
{
	if (coordinate == nullptr)
	{
		return false;
	}
	if (indexSelected < 12 && indexSelected >= 0)
	{
		if((checker[11].CheckWalkCoordinate(coordinate) || 
			checker[11].CheckBeatCoordinate(coordinate)) && 
			!CheckСonflictCoordinateCheckers(coordinate))
		{
			checker[11].SetCoordinate(coordinate->X, coordinate->Y);
			checker[11].SetState(draw);
			return true;
		}		
	}
	return false;
}

void Player::InitChecker()
{
	int count = 0, i = 0;
	float x = -0.625f, y = -0.875f;


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
			x = -0.625f;
		}
		else
		{
			x = -0.875f;
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
	for(int i = 0; i < 12; i++)
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
	for (int i = 0; i < 12; i++)
	{
		if(checker[i].CheckContactCoordinate(coordinate))
		{
			return true;
		}
			
	}
	return false;
}
