#include "BForward.h"

BForward::BForward() {}

//tasks
// 0 - stop
// 1 - foreward
// 2 - left
// 3 - right

void BForward::init()
{

}

void BForward::execute()
{
	#if __BFORWARD_H__DEBUG
		Serial.println("Forward!");
	#endif
	motordriver.goForward();

}