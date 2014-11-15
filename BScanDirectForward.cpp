#include "BScanDirectForward.h"

BScanDirectForward::BScanDirectForward() 
{
	currentMoveOrder = data.FS_CENTER_ID;
}

void BScanDirectForward::execute()
{
	if (scan(currentMoveOrder, MOVE_DELAY))
	{
		lastMoveOrderTime = simpleTimer.getTime();
		moved = false;
	}
}