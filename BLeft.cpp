#include "BLeft.h"

BLeft::BLeft() {}

void BLeft::execute()
{
	#if __BLEFT_H__DEBUG
		Serial.println("Go left!");
	#endif
	motordriver.goLeft();
}
