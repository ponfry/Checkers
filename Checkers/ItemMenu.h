#pragma once
#include "CoordinateFloat.h"
#include "MenuState.h"
#include "DrawTexture.h"

struct ItemMenu
{
	CoordinateFloat* coordinate;
	MenuState state;
	DrawTexture *drawed;
	DrawTexture *lighted;

	void SetTexture(DrawTexture *draws, DrawTexture *light)
	{
		drawed = draws;
		lighted = light;
	}
};
