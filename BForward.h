#ifndef __BFORWARD_H__
#define __BFORWARD_H__
#define __BFORWARD_H__DEBUG 0

#include "Timer.h"
#include "MotorDriver.h"
#include "Behavior.h"

class BForward: public Behavior
{
private:

public:
	BForward();
	virtual void init();
    virtual void execute();
};

#endif