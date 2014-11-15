#ifndef __BREADCOMPASS_H__
#define __BREADCOMPASS_H__
#define __BREADCOMPASS_H__DEBUG 0
#define READ_DELAY 100

#include <Wire.h>
#include "ThreeDCompass.h"
#include "SimpleTimer.h"
#include "MotorDriver.h"
#include "Behavior.h"
#include "Data.h"


/*

-159.00:-161.00:-800:176:-583:253:-312:-165


*/

class BReadCompass: public Behavior
{
private:
	unsigned long lastReadTime;
public:
	BReadCompass();
	virtual void init();
    virtual void execute();
};

#endif