#ifndef __DATA_H__
#define __DATA_H__
#define __DATA_H___DEBUG 0

#define FS_MAX_RANGE 170
#define FS_OBSTRUCTION_RANGE 40
#define FS_AVOID_RANGE 100
#define FS_FRONT_STALE 500
#define FS_SIDE_STALE 1500

#define FS_LEFT_100 	180
#define FS_LEFT_66		150
#define FS_LEFT_33 		120
#define FS_CENTER	 	90
#define FS_RIGHT_33 	60
#define FS_RIGHT_66 	30
#define FS_RIGHT_100 	0

#define FS_LEFT_100_I   0
#define FS_LEFT_66_I    1
#define FS_LEFT_33_I    2
#define FS_CENTER_I     3
#define FS_RIGHT_33_I   4
#define FS_RIGHT_66_I   5
#define FS_RIGHT_100_I  6

#include <Servo.h>
#include <SimpleTimer.h>

class Data
{
private:
    bool calcStale(int pos, unsigned long age);

public:
	static const int FS_LEFT_100_ID;
    static const int FS_LEFT_66_ID;
    static const int FS_LEFT_33_ID;
    static const int FS_CENTER_ID;
    static const int FS_RIGHT_33_ID;
    static const int FS_RIGHT_66_ID;
    static const int FS_RIGHT_100_ID;

    static long ForwardRange[7];
    static unsigned long ForwardRangeUpdate[7];
    static int CompassX, CompassY, CompassZ;
    static Servo* FrontServo;
    static int ScanDegrees[7];

    bool AnyObstruction();
    bool FrontObstruction();
    bool RightObstruction();
    bool LeftObstruction();

    bool AnyStale();
    bool FrontStale();
    bool RightStale();
    bool LeftStale();

    bool AnyStale(unsigned long age);
    bool FrontStale(unsigned long age);
    bool RightStale(unsigned long age);
    bool LeftStale(unsigned long age);

};

extern Data data;

#endif