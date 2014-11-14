#include "BStop.h"

BStop::BStop() {}

void BStop::execute()
{
	#if __BSTOP_H__DEBUG
		Serial.println("Stop!");
	#endif
	motordriver.stop();
}
