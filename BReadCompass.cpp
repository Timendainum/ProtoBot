#include "BReadCompass.h"

BReadCompass::BReadCompass() {}

void BReadCompass::init()
{

}

void BReadCompass::execute()
{
	if ((simpleTimer.getTime() - lastReadTime) > READ_DELAY)
	{
		#if __BREADCOMPASS_H__DEBUG
			Serial.println("Reading compass!");
		#endif
		compass.update(&data.CompassHeading);
		lastReadTime = simpleTimer.getTime();
	}
}