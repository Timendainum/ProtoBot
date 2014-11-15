#include "Data.h"

const int Data::FS_LEFT_100_ID  = FS_LEFT_100_I;
const int Data::FS_LEFT_66_ID   = FS_LEFT_66_I;
const int Data::FS_LEFT_33_ID   = FS_LEFT_33_I;
const int Data::FS_CENTER_ID    = FS_CENTER_I;
const int Data::FS_RIGHT_33_ID  = FS_RIGHT_33_I;
const int Data::FS_RIGHT_66_ID  = FS_RIGHT_66_I;
const int Data::FS_RIGHT_100_ID = FS_RIGHT_100_I;

long Data::ForwardRange[7];
unsigned long Data::ForwardRangeUpdate[7];
int Data::ScanDegrees[7] = {FS_LEFT_100, FS_LEFT_66, FS_LEFT_33, FS_CENTER, FS_RIGHT_33, FS_RIGHT_66, FS_RIGHT_100};

float Data::CompassHeading;
Servo* Data::FrontServo;


///////////////////////////////////////////////////////////////////////////////
// Obstruction
bool Data::AnyObstruction()
{
	return FrontObstruction() || RightObstruction() || LeftObstruction();
}

bool Data::FrontObstruction() 
{
	return ForwardRange[FS_LEFT_33_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_CENTER_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_RIGHT_33_ID] < FS_OBSTRUCTION_RANGE;
}

bool Data::RightObstruction() 
{
	return ForwardRange[FS_RIGHT_100_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_RIGHT_66_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_RIGHT_33_ID] < FS_OBSTRUCTION_RANGE;
}
bool Data::LeftObstruction() 
{
	return ForwardRange[FS_LEFT_100_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_LEFT_66_ID] < FS_OBSTRUCTION_RANGE ||
		ForwardRange[FS_LEFT_33_ID] < FS_OBSTRUCTION_RANGE;
}


///////////////////////////////////////////////////////////////////////////////
// Stale
bool Data::AnyStale()
{
	return FrontStale() || RightStale() || LeftStale ();
}

bool Data::FrontStale()
{
	return FrontStale(FS_FRONT_STALE);
}
bool Data::RightStale()
{
	return RightStale(FS_SIDE_STALE);
}

bool Data::LeftStale()
{
	return LeftStale(FS_SIDE_STALE);
}

//specific
bool Data::AnyStale(unsigned long age)
{
	return FrontStale(age) || RightStale(age) || LeftStale (age);
}

bool Data::FrontStale(unsigned long age)
{
	return calcStale(FS_RIGHT_33_ID, age) ||
		calcStale(FS_CENTER_ID, age) ||
		calcStale(FS_LEFT_33_ID, age);
}
bool Data::RightStale(unsigned long age)
{
	return calcStale(FS_RIGHT_100_ID, age) ||
		calcStale(FS_RIGHT_66_ID, age) ||
		calcStale(FS_RIGHT_33_ID, age);
}
bool Data::LeftStale(unsigned long age)
{
	return calcStale(FS_LEFT_100_ID, age) ||
		calcStale(FS_LEFT_66_ID, age) ||
		calcStale(FS_LEFT_33_ID, age);
}

//privattes
bool Data::calcStale(int pos, unsigned long age)
{
	return simpleTimer.getTime() - ForwardRangeUpdate[pos] > age;
}

///////////////////////////////////////////////////////////////////////////////
// disting
Data data;