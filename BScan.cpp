#include "BScan.h"

BScan::BScan() {}

void BScan::init()
{
	lastMoveOrderTime = simpleTimer.getTime();
	moved = false;
}

bool BScan::scan(int pos, unsigned long moveDelay)
{
	if ((simpleTimer.getTime() - lastMoveOrderTime) > moveDelay)
	{
		ping(pos);
		return true;
	} else {
		
		if (!moved)
		{

			#if __BSCAN_H__DEBUG
				Serial.println("Servo Move Order: " + (String)pos);
			#endif

			data.FrontServo->write(data.ScanDegrees[pos]);
			moved = true;
		}
		return false;
	}
}


//returns true when scan is complete
void BScan::ping(int pos)
{

	#if __BSCAN_H__DEBUG
		Serial.println("Scanning:" + (String)pos);
	#endif

	data.ForwardRange[pos] = rangeFinder.getDistance();
	data.ForwardRangeUpdate[pos] = simpleTimer.getTime();

	#if __BSCAN_H__DEBUG
		Serial.println("Range: " + (String)data.ForwardRange[pos]);
	#endif
}