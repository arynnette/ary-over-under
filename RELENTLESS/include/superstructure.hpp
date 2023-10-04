#include "main.h"
#include "ary-lib/api.hpp"
#include "globals.hpp"

#define DRIVE_SPEED 110
#define TURN_SPEED 90
#define SWING_SPEED 90

namespace superstruct {
    //configs
    void chassisInit();
    void configureExitConditions();
    void configureConstants();
    void autonomousResets();
    void motorsCoast();
    void motorsHold();
    void motorsBrake();

    void disableActiveBrake();
    

    // Movement Methods
    void driveAsync(double dist, bool useHeadingCorrection);
    void driveSync(double dist, bool useHeadingCorrection);
    void driveWithMD(double dist, bool useHeadingCorrection, double waitUntilDist);

    void turnSync(double theta);
    void turnAsync(double theta);

    void leftSwing(double theta);
    void rightSwing(double theta);
    
    void setDriveScale(double val);
    void setTurnScale(double val);
    void setSwingScale(double val);

    //- Structure methods
    void togglePto();
    void runCata();
    void cataControl();
    
}