#ifndef __BSTOP_H__
#define __BSTOP_H__
#define __BSTOP_H__DEBUG 0

#include "Behavior.h"
#include "MotorDriver.h"

class BStop: public Behavior
{
private:

public:
	BStop();
    virtual void execute();
};

#endif