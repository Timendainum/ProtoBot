#include "BScanFull.h"

BScanFull::BScanFull() 
{
	max = 6;
	min = 0;
	goingUp = true;
	currentMoveOrder = 3;
}

void BScanFull::execute()
{
	if (scan(currentMoveOrder, MOVE_DELAY))
	{
		lastMoveOrderTime = simpleTimer.getTime();
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