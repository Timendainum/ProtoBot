/******************************************************************************
* The motivator is aware of sensory input (via another class?) and uses that 
* that information to choose the best behavior.
*/
#ifndef __PROTOMOTIVATOR_H__
#define __PROTOMOTIVATOR_H__
#define __PROTOMOTIVATOR_H__DEBUG 0

#define GOAL_AVOID_OBSTRUCTION 0
#define GOAL_DEFAULT 1

#define B_FORWARD 		0
#define B_RIGHT			1
#define B_LEFT			2
#define B_STOP			3
#define B_BACKWARD		4
#define B_SCANFORWARD	5
#define B_SCANFULL		6
#define B_READCOMPASS	7

#define G_AVOIDSCANTIME 2000

#include <Arduino.h>
#include <Servo.h>
#include "Motivator.h"
#include "Behavior.h"
#include "BForward.h"
#include "BLeft.h"
#include "BRight.h"
#include "BStop.h"
#include "BBackward.h"
#include "BScanForward.h"
#include "BScanFull.h"
#include "BReadCompass.h"

class ProtoMotivator: public Motivator
{
private:
	int goal;
	unsigned long goalStartTime;
	bool avoidChosen;
	bool avoidRight;

public:
    ProtoMotivator();

    virtual void motivate();
};

#endif