#include "PlayerOne.h"

PlayerOne::PlayerOne()
{
	checker = new CheckerWhite[12];
	InitChecker();
}

void PlayerOne::InitChecker()
{
	int count = 0, i = 0;
	float x = -0.875f, y = -0.875f;


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
