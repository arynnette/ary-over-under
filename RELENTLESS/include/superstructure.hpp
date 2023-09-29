#include "main.h"
#include "ary-lib/api.hpp"
#include "globals.hpp"

#define DRIVE_SPEED 110
#define TURN_SPEED 90
#define SWING_SPEED 90

namespace superstruct {
    //configs
    void configureExitConditions();
    void configureConstants();
    void motorsCoast();
    void motorsHold();
    void motorsBrake();
    

    // Movement Methods
    void driveChassis(double dist, double speedScale, bool useHeadingCorrection);
    void turnChassis(double theta, double turnSpeedScale);
    void leftSwing(double theta, double swingSpeedScale);
    void rightSwing(double theta, double swingSpeedScale);

    //- Structure methods
    void togglePto();
    void runCata();
    void controlCata();
    
}