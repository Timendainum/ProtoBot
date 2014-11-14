#include "BRight.h"

BRight::BRight() {}

void BRight::execute()
{
	#if __BRIGHT_H__DEBUG
		Serial.println("Go right!");
	#endif
	motordriver.goRight();
}
