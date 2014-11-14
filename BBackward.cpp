#include "BBackward.h"

BBackward::BBackward() {}

//tasks
// 0 - stop
// 1 - foreward
// 2 - left
// 3 - right

void BBackward::init()
{

}

void BBackward::execute()
{
	#if __BBACKWARD_H__DEBUG
		Serial.println("Backward!");
	#endif

	motordriver.goBackward();

}