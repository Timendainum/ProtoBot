#ifndef __BSCANFORWARD_H__
#define __BSCANFORWARD_H__
#define __BSCANFORWARD_H__DEGUG 0

#define MOVE_DELAY 150

#include <Servo.h>
#include "SimpleTimer.h"
#include "RangeFinder.h"
#include "Behavior.h"
#include "BScan.h"

class BScanForward: public BScan
{
private:
	int max;
	int min;
	bool goingUp;

public:
	BScanForward();
    virtual void execute();
};

#endif