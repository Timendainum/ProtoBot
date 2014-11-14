#ifndef __BSCANFULL_H__
#define __BSCANFULL_H__
#define __BSCANFULL_H__DEBUG 0

#define MOVE_DELAY 150

#include <Servo.h>
#include "Timer.h"
#include "RangeFinder.h"
#include "Behavior.h"
#include "BScan.h"

class BScanFull: public BScan
{
private:
	int max;
	int min;
	bool goingUp;

public:
	BScanFull();
    virtual void execute();
};

#endif