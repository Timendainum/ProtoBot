#ifndef __BBACKWARD_H__
#define __BBACKWARD_H__
#define __BBACKWARD_H__DEBUG 0

#include "MotorDriver.h"
#include "Behavior.h"

class BBackward: public Behavior
{
private:

public:
	BBackward();
	virtual void init();
    virtual void execute();
};

#endif