#ifndef __BSCANDIRECTFORWARD_H__
#define __BSCANDIRECTFORWARD_H__
#define __BSCANDIRECTFORWARD_H__DEGUG 0

#define MOVE_DELAY 150

#include <Servo.h>
#include "SimpleTimer.h"
#include "RangeFinder.h"
#include "Behavior.h"
#include "BScan.h"
#include "Data.h"

class BScanDirectForward: public BScan
{
private:
public:
	BScanDirectForward();
    virtual void execute();
};

#endif