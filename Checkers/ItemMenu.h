#pragma once
#include "CoordinateInt.h"
#include "MenuState.h"
#include "DrawTexture.h"

struct ItemMenu
{
	CoordinateInt* coordinate;
	MenuState state;
	DrawTexture *drawed;
	DrawTexture *lighted;

	void SetTexture(DrawTexture *draws, DrawTexture *light)
	{
		drawed = draws;
		lighted = light;
	}
};
