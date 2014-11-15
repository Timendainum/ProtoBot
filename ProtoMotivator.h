/******************************************************************************
* The motivator is aware of sensory input (via another class?) and uses that 
* that information to choose the best behavior.
*/
#ifndef __PROTOMOTIVATOR_H__
#define __PROTOMOTIVATOR_H__
#define __PROTOMOTIVATOR_H__DEBUG 0

#define GOAL_AVOID_CRITICAL 0
#define GOAL_AVOID_OBSTRUCTION 1
#define GOAL_FORWARD 2
#define GOAL_DEFAULT 3

#define B_FORWARD 			0
#define B_RIGHT				1
#define B_LEFT				2
#define B_STOP				3
#define B_BACKWARD			4
#define B_SCANFORWARD		5
#define B_SCANFULL			6
#define B_SCANDIRECTFORWARD	7
#define B_READCOMPASS		8

#define G_AVOIDSCANTIME 		2000
#define G_AVOIDTURNDEGREES		30
#define G_AVOIDTURNSLOP			3
#define G_AVOIDCRITICALRANGE	10

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
#include "BScanDirectForward.h"
#include "BScanFull.h"
#include "BReadCompass.h"

class ProtoMotivator: public Motivator
{
private:
	int goal;
	unsigned long goalStartTime;
	bool avoidChosen;
	bool avoidRight;
	float heading;

public:
    ProtoMotivator();

    virtual void motivate();
};

#endif