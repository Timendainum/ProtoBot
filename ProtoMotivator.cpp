#include "ProtoMotivator.h"

ProtoMotivator::ProtoMotivator()
{
	//Configure behaviors
	addBehavior(new BForward());
	behaviors[B_FORWARD]->init();

	addBehavior(new BRight());
	behaviors[B_RIGHT]->init();

	addBehavior(new BLeft());
	behaviors[B_LEFT]->init();

	addBehavior(new BStop());
	behaviors[B_STOP]->init();

	addBehavior(new BBackward());
	behaviors[B_BACKWARD]->init();

	addBehavior(new BScanForward());
	behaviors[B_SCANFORWARD]->init();

	addBehavior(new BScanFull());
	behaviors[B_SCANFULL]->init();

	addBehavior(new BScanDirectForward());
	behaviors[B_SCANDIRECTFORWARD]->init();

	addBehavior(new BReadCompass());
	behaviors[B_READCOMPASS]->init();

	//configure behavior conflicts
	behaviors[B_FORWARD]->addConflict(behaviors[B_RIGHT]);
	behaviors[B_FORWARD]->addConflict(behaviors[B_LEFT]);
	behaviors[B_FORWARD]->addConflict(behaviors[B_STOP]);
	behaviors[B_FORWARD]->addConflict(behaviors[B_BACKWARD]);

	behaviors[B_RIGHT]->addConflict(behaviors[B_FORWARD]);
	behaviors[B_RIGHT]->addConflict(behaviors[B_LEFT]);
	behaviors[B_RIGHT]->addConflict(behaviors[B_STOP]);
	behaviors[B_RIGHT]->addConflict(behaviors[B_BACKWARD]);

	behaviors[B_LEFT]->addConflict(behaviors[B_FORWARD]);
	behaviors[B_LEFT]->addConflict(behaviors[B_RIGHT]);
	behaviors[B_LEFT]->addConflict(behaviors[B_STOP]);
	behaviors[B_LEFT]->addConflict(behaviors[B_BACKWARD]);

	behaviors[B_STOP]->addConflict(behaviors[B_FORWARD]);
	behaviors[B_STOP]->addConflict(behaviors[B_RIGHT]);
	behaviors[B_STOP]->addConflict(behaviors[B_LEFT]);
	behaviors[B_STOP]->addConflict(behaviors[B_BACKWARD]);

	behaviors[B_BACKWARD]->addConflict(behaviors[B_FORWARD]);
	behaviors[B_BACKWARD]->addConflict(behaviors[B_RIGHT]);
	behaviors[B_BACKWARD]->addConflict(behaviors[B_LEFT]);
	behaviors[B_BACKWARD]->addConflict(behaviors[B_STOP]);

	behaviors[B_SCANFORWARD]->addConflict(behaviors[B_SCANFULL]);
	behaviors[B_SCANFORWARD]->addConflict(behaviors[B_SCANDIRECTFORWARD]);

	behaviors[B_SCANFULL]->addConflict(behaviors[B_SCANFORWARD]);
	behaviors[B_SCANFULL]->addConflict(behaviors[B_SCANDIRECTFORWARD]);
	
	behaviors[B_SCANDIRECTFORWARD]->addConflict(behaviors[B_SCANFORWARD]);
	behaviors[B_SCANDIRECTFORWARD]->addConflict(behaviors[B_SCANFULL]);
}

void ProtoMotivator::motivate()
{
#if __PROTOMOTIVATOR_H__DEBUG
	Serial.println("Motivating!");
#endif
	///////////////////////////////////////////////////////////////////////////
	// Enable always active behaviors
	enableBehavior(B_READCOMPASS);

	//select goal, see if goal should be called based on current goal.
	//lower number goals have priotity and can override higher level goals.
	///////////////////////////////////////////////////////////////////////////
	// GOAL_AVOID_CRITICAL
	if (GOAL_AVOID_CRITICAL <= goal)
	{
		bool shouldBeActive = data.DirectFrontObstructionRange() <= G_AVOIDCRITICALRANGE;
		bool isActive = goal == GOAL_AVOID_CRITICAL;
		
		//if goal should be active
		if (shouldBeActive && !isActive)
		{
			Serial.println("New goal: GOAL_AVOID_CRITICAL");
			goal = GOAL_AVOID_CRITICAL;
			goalStartTime = simpleTimer.getTime();
		}
		if (shouldBeActive && isActive)
		{
			//carry out the behaviors
			//scan logic
			if (data.DirectFrontStale(200))
			{
				enableBehavior(B_SCANDIRECTFORWARD);
				enableBehavior(B_STOP);
			}
			else
			{
				enableBehavior(B_SCANDIRECTFORWARD);
				//Move
				enableBehavior(B_BACKWARD);
			}
		}
		//if goal should not be active, and is
		if (!shouldBeActive && isActive)
		{
			goal = GOAL_DEFAULT;
		}
	}
	///////////////////////////////////////////////////////////////////////////
	// GOAL_AVOID_OBSTRUCTION
	if (GOAL_AVOID_OBSTRUCTION <= goal)
	{
		bool shouldBeActive = data.FrontObstruction();
		bool isActive = goal == GOAL_AVOID_OBSTRUCTION;
		//if goal should be active
		if (shouldBeActive && !isActive)
		{
			Serial.println("New goal: GOAL_AVOID_OBSTRUCTION");
			goal = GOAL_AVOID_OBSTRUCTION;
			goalStartTime = simpleTimer.getTime();
			heading = data.CompassHeading;
			avoidChosen = false;
		}
		if (shouldBeActive && isActive)
		{
			//carry out the behaviors
			#if __PROTOMOTIVATOR_H__DEBUG
				Serial.println("GOAL_AVOID_OBSTRUCTION");
			#endif
			if (simpleTimer.getTime() > (goalStartTime + G_AVOIDSCANTIME))
			{
				//
				if (!avoidChosen)
				{
					//choose avoid direction
					if (data.RightObstruction() && data.RightObstructionRange() < data.LeftObstructionRange())
					{
						avoidRight = false;
					} 
					else if (data.LeftObstruction() && data.RightObstructionRange() > data.LeftObstructionRange())
					{
						avoidRight = true;
					} 
					else if (data.FrontObstruction())
					{
						if (data.RightObstructionRange() > data.LeftObstructionRange())
							avoidRight = false;
						else
							avoidRight = true;
					}

					if (avoidRight)
						heading = data.CompassHeading + G_AVOIDTURNDEGREES;
					else
						heading = data.CompassHeading - G_AVOIDTURNDEGREES;
					avoidChosen = true;
				}

				//avoid -------------------------------------------------------
				// scan forward while avoiding
				enableBehavior(B_SCANFORWARD);
				//enable avoid behavior
				if (!compass.headingMatches(data.CompassHeading, heading, G_AVOIDTURNSLOP))
				{
					if (avoidRight)
					{
						enableBehavior(B_RIGHT);
					}
					else
					{
						enableBehavior(B_LEFT);
					}
				}
				else
				{
					goal = GOAL_DEFAULT;
				}
			}
			else
			{
				//enable full scan for scan time
				enableBehavior(B_SCANFULL);
				enableBehavior(B_STOP);
			}
		}
		//if goal should not be active, and is
		if (!shouldBeActive && isActive)
		{
			goal = GOAL_DEFAULT;
		}
	}


	
	///////////////////////////////////////////////////////////////////////////
	// GOAL_FORWARD
	if (GOAL_FORWARD <= goal)
	{
		bool shouldBeActive = true;
		bool isActive = goal == GOAL_FORWARD;
		
		//if goal should be active
		if (shouldBeActive && !isActive)
		{
			Serial.println("New goal: GOAL_FORWARD");
			goal = GOAL_FORWARD;
			goalStartTime = simpleTimer.getTime();
		}
		if (shouldBeActive && isActive)
		{
			//carry out the behaviors
			//scan logic
			if (data.FrontStale(200))
			{
				enableBehavior(B_SCANFORWARD);
			}
			else if (data.FrontStale())
			{
				enableBehavior(B_SCANFORWARD);
			}
			else
			{
				enableBehavior(B_SCANFULL);
			}

			//Move
			enableBehavior(B_FORWARD);
			
		}
		//if goal should not be active, and is
		if (!shouldBeActive && isActive)
		{
			goal = GOAL_DEFAULT;
		}
	}


	///////////////////////////////////////////////////////////////////////////
	//make it happen!
	executeBehaviors();
}