#include "player.h"

Player::Player()
{
	//checker = new Checker[12];
}
void Player::Draw()
{
	int count = 0;
	float x = -0.625f, y = -0.875f;


	while (y <= -0.375f)
	{
		while (x < 1.0f)
		{
			
			x += 0.5f;
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

	y = 0.375f;
	while (y <= 1.0f)
	{
		while (x < 1.0f)
		{
			
			x += 0.5f;
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
		if (count == 4)
		{
			break;
		}
	}
}

