#include "main.h"

#define DRIVE_SPEED 120
#define TURN_SPEED 105
#define SWING_SPEED 90
// R1 -> WINGS, L1 -> CATA, L2 -> PTO, R2 -> INTAKE
// Renu's control preferences
#define RENU_PTO_TOGGLE DIGITAL_R2
#define RENU_CATA_CONTROL DIGITAL_R1
#define RENU_INTAKE_CONTROL_INTAKE DIGITAL_L1
#define RENU_INTAKE_CONTROL_OUTTAKE DIGITAL_B
#define RENU_LEFT_WING_CONTROL DIGITAL_LEFT
#define RENU_RIGHT_WING_CONTROL DIGITAL_RIGHT
#define RENU_WING_CONTROL DIGITAL_L2
#define RENU_CLIMB_CONTROL DIGITAL_A

// Ria's control preferences
#define RIA_PTO_TOGGLE DIGITAL_LEFT
#define RIA_CATA_CONTROL DIGITAL_A
#define RIA_INTAKE_CONTROL DIGITAL_R1
#define RIA_WINGS_CONTROL DIGITAL_L1


namespace superstruct {
    //configs
    void chassisInit();
    void telemetry();
    void opControlInit();
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
    //void intakeControl(pros::controller_digital_e_t intakeButton);
    void togglePto(bool toggle);
    void runCata(double inpt);
    void runAntiBlock(double inpt);
    void subsysControl(pros::controller_digital_e_t ptoToggleButton, pros::controller_digital_e_t cataRunButton, pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton);
    void wingsControl();
    void wingsControlSingle(pros::controller_digital_e_t wingControlButton);
    void wingsControlComplex(pros::controller_analog_e_t leftWingButton, pros::controller_analog_e_t rightWingButton, pros::controller_analog_e_t wingButton);
    void climbControl(pros::controller_digital_e_t climbButton);

    //More methods
    void toggleIntake(bool val);
    void toggleRemovalMech(bool val);

    void renu_control();
    void ria_control();
    void chris_control();
    
}