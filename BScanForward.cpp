#include "BScanForward.h"

BScanForward::BScanForward() 
{
	max = 4;
	min = 2;
	goingUp = true;
	currentMoveOrder = min;
}

void BScanForward::execute()
{
	if (scan(currentMoveOrder, MOVE_DELAY))
	{
		lastMoveOrderTime = timer.getTime();
		moved = false;
		if (goingUp)
		{
			if (currentMoveOrder < max)
			{
				currentMoveOrder++;
			}
			else
			{
				currentMoveOrder--;
				goingUp = false;
			}
		}
		else
		{
			if (currentMoveOrder > min)
			{
				currentMoveOrder--;
			}
			else
			{
				currentMoveOrder++;
				goingUp = true;
			}
		}
	}
}