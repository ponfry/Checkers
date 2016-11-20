#include "player.h"
#include "CoordinateMouse.h"
#include "StateChecker.h"

Player::Player()
{
	InitChecker();
}
void Player::Draw()
{
	for(int i=0; i<12; i++)
	{
		checker[i].Draw();
	}
}

void Player::ControlCoordinate()
{
	checkCoordf = MyMouse::ConvertIntTOFloatForBoard(coordinateMouseMoveI.X,
		coordinateMouseMoveI.Y);
	for (int i = 0; i < 12; i++)
	{
		if (checker[i].CheckCoordinate(checkCoordf->X, checkCoordf->Y))
		{
			checker[i].SetState(StateChecker::select);
			return;
		}
		else
		{
			checker[i].SetState(StateChecker::draw);
		}
	}
}

bool Player::CheckCoordinatePassive()
{
	checkCoordf = MyMouse::ConvertIntTOFloatForBoard(coordinateMousePassiveMove.X,
		coordinateMousePassiveMove.Y);
	for (int i = 0; i < 12; i++)
	{
		if (checker[i].CheckCoordinate(checkCoordf->X, checkCoordf->Y))
		{
			checker[i].SetState(StateChecker::lighting);
			return true;
		}
		else
		{
			checker[i].SetState(StateChecker::draw);
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
			count = 1;
			break;
		}
	}
}
