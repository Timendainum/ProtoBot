#ifndef __BLEFT_H__
#define __BLEFT_H__
#define __BLEFT_H__DEBUG 0

#include "Behavior.h"
#include "MotorDriver.h"

class BLeft: public Behavior
{
private:

public:
	BLeft();
    virtual void execute();
};

#endif