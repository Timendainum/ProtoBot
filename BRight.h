#ifndef __BRIGHT_H__
#define __BRIGHT_H__
#define __BRIGHT_H__DEBUG 0


#include "Behavior.h"
#include "Timer.h"
#include "MotorDriver.h"

class BRight: public Behavior
{
private:

public:
	BRight();
    virtual void execute();
};

#endif