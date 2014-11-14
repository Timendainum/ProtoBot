#ifndef __BSCAN_H__
#define __BSCAN_H__
#define __BSCAN_H__DEBUG 0

#include <Servo.h>
#include "Timer.h"
#include "RangeFinder.h"
#include "Behavior.h"
#include "Data.h"

class BScan: public Behavior
{
protected:
	unsigned long lastMoveOrderTime;
	int currentMoveOrder;
	bool moved;
	bool scan(int pos, unsigned long moveDelay);
	void ping(int pos);

public:
	BScan();
	virtual void init();
    virtual void execute() =0;
};

#endif