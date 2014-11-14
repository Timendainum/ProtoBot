#ifndef __BREADCOMPASS_H__
#define __BREADCOMPASS_H__
#define __BREADCOMPASS_H__DEBUG 1
#define READ_DELAY 100

#include <Wire.h>
#include "ThreeDCompass.h"
#include "Timer.h"
#include "MotorDriver.h"
#include "Behavior.h"
#include "Data.h"


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