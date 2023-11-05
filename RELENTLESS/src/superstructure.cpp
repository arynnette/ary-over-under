#include "superstructure.hpp"

using namespace ary;
using namespace globals;

bool ptoEnabled = false;
bool wingsOpen = false;
bool intakeEngaged = false;

/*
  SCALE SPEEDS: Determines what percentage speeds of autonomous movements should move at
    speedScale -> The scale of how fast the drivetrain goes forward and backwards
    turnScale -> The scale of how fast the drivetrain turns
    swingScale -> The scale of fast one side of the chassis moves
*/

double speedScale = 1.0;
double turnScale = 1.0;
double swingScale = 1.0;
namespace superstruct {
  void chassisInit() {
    /*
      When the robot first starts up we want to do a couple things:
      - Adjust the drivetrain curve bottons so it does not interfere with any of the driver controls.
      - Enable the joystick curve
      - Enable active break on the drive
        - Active break is a P controller applied to the drivetrain in order to help it maintain it's position, resisting external forces.
        - 
    */

    chassis.set_curve_buttons(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);
    chassis.toggle_modify_curve_with_controller(true);
    chassis.set_active_brake(0.1);
    chassis.set_curve_default(0.375, 0.375);

    /* Adjust the adjust the factor by which the drive velocity is adjusted */ 
    chassis.set_joystick_drivescale(1.0);
    chassis.set_joystick_turnscale(1.0); 

    chassis_odom.calibrate();
    chassis_odom.setPose(0, 0, 0);
  }

  void telemetry() {
    while (true) {
      lemlib::Pose bot_pose = chassis_odom.getPose();
      pros::lcd::print(0, "x: %f", bot_pose.x); // print the x position
        pros::lcd::print(1, "y: %f", bot_pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", bot_pose.theta); // print the heading
        pros::delay(10);
    }
  }

  void opControlInit() {
    motorsCoast();
	  disableActiveBrake();
  }

  // Adjust exit conditions to allow for quick movements
  void configureExitConditions() {
    chassis.set_exit_condition(chassis.turn_exit, 50, 2, 220, 3, 500, 500);
    chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
    chassis.set_exit_condition(chassis.drive_exit, 40, 80, 300, 150, 500, 500);
  }

  // Adjust PID constants for accurate movements
  void configureConstants() {
    chassis.set_slew_min_power(80, 80);
    chassis.set_slew_distance(7, 7);
    chassis.set_pid_constants(&chassis.headingPID, 16, 0, 32, 0);
    chassis.set_pid_constants(&chassis.forward_drivePID, 0.55, 0, 5, 0);
    chassis.set_pid_constants(&chassis.backward_drivePID, 0.55, 0, 5, 0);
    chassis.set_pid_constants(&chassis.turnPID, 6.5, 0.003, 35, 15);
    chassis.set_pid_constants(&chassis.swingPID, 8.5, 0, 50, 0);
  }

  // Prepare the bot for the autonomous period of a match
  void autonomousResets() {
    chassis.reset_pid_targets();
  	chassis.reset_gyro();
  	chassis.reset_drive_sensor();
    configureConstants();
    configureExitConditions();
    motorsBrake();
    
  }

  void motorsCoast() {
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  }

  void motorsHold() {
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  }

  void motorsBrake() {
    chassis.set_drive_brake(MOTOR_BRAKE_BRAKE);
  }

  // The chassis will not apply a constant voltage to prevent it from being moved
  void disableActiveBrake() {
    chassis.set_active_brake(0.0);
  }


  // Drives forward, runs next commands WITHOUT waiting for the drive to complete 
  void driveAsync(double dist, bool useHeadingCorrection) {
    //chassis.set_mode(ary::DRIVE);
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
  }

  // Drives forward, runs next commands AFTER waiting for the drive to complete 
  void driveSync(double dist, bool useHeadingCorrection) {
    //chassis.set_mode(ary::DRIVE);
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
    chassis.wait_drive();
  }

  // Drives forward, runs next commands AFTER reaching a certain measurement/error along the path
  void driveWithMD(double dist, bool useHeadingCorrection, double waitUntilDist) {
    //chassis.set_mode(ary::DRIVE);
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
    chassis.wait_until(waitUntilDist);
  }

  // Turns the chassis, runs other commands after it has run.
  void turnSync(double theta) {
    //chassis.set_mode(ary::TURN);
    chassis.set_turn(theta, TURN_SPEED * turnScale);
    chassis.wait_drive();
  }

  // Turns the chassis, runs other commands immediately after call
  void turnAsync(double theta) {
    //chassis.set_mode(ary::TURN);
    chassis.set_turn(theta, TURN_SPEED * turnScale);
  }

  // Moves only the right side of the chassis so it can make a left turn
  void leftSwing(double theta) {
    //chassis.set_mode(SWING);
    chassis.set_swing(LEFT_SWING, theta, SWING_SPEED * swingScale);
  }

  // Moves only the left side of the chassis so it can make a right turn
  void rightSwing(double theta) {
    //chassis.set_mode(SWING);
    chassis.set_swing(RIGHT_SWING, theta, SWING_SPEED * swingScale);
  }

  /*
    Each of the scale values must be clamed between 0.1 - 1 (10% to 100%) to avoid saturation of motors.
  */

  void setDriveScale(double val) {
    speedScale = std::clamp(val, 0.1, 1.0);
  }

  void setTurnScale(double val) {
    turnScale = std::clamp(val, 0.1, 1.0);
  }

  void setSwingScale(double val) {
    swingScale = std::clamp(val, 0.1, 1.0); // 
  }

  // Structure methods
  void intakeControl(pros::controller_digital_e_t intakeButton) {
    if (globals::master.get_digital_new_press(intakeButton)) {
      if (intakeEngaged == false) {
        intake_piston.set_value(1);
        intakeEngaged = true;
      } else if (intakeEngaged == true) {
        intake_piston.set_value(0);
        intakeEngaged = false;
      }
    }
  }

  void togglePto(bool toggle) {
    ptoEnabled = toggle;
    chassis.pto_toggle({cata_left, cata_right}, toggle); // Configure the listed PTO motors to whatever value toggle is.
    pto_piston.set_value(toggle);

    if (toggle) {
      cata_left.set_brake_mode(MOTOR_BRAKE_COAST);
      cata_right.set_brake_mode(MOTOR_BRAKE_COAST);
    }
  }

  void runCata(double inpt) {
    if (!ptoEnabled) return;
    cata_left = inpt;
    cata_right = inpt;
  }

  int lock = 0;
  void cataControl(pros::controller_digital_e_t ptoToggleButton, pros::controller_digital_e_t cataRunButton) {
    if (globals::master.get_digital(ptoToggleButton) && lock == 0) { // If the PTO button has been pressed and the PTO is not engaged
      togglePto(!ptoEnabled); // Toggle the PTO so that cataput is useable
      lock = 1;
    } else if(!globals::master.get_digital(ptoToggleButton)) {
      lock = 0;
    }

    if (globals::master.get_digital(cataRunButton)) {
			runCata(-12000);
		} else {
			runCata(0);
		}
  }

  void wingsControlSingle(pros::controller_digital_e_t wingControlButton) {
    if (globals::master.get_digital_new_press(wingControlButton)) {
      if (wings.getState() == 0) // A value of 0 indicates that both wings are closed
        wings.open();
      else if (wings.getState() == 3) // A value of 3 indicates that both wings are open
        wings.close();
    }
  }

  void toggleIntake(bool val) {
    int valTo = (val == true) ? 1 : 0;
    intake_piston.set_value(valTo);
  }

  // void toggleRemovalMech(bool val) {
  //   int valTo = (val == true) ? 1 : 0;
  //   doinker_piston.set_value(valTo);
  // }

  /*
    Handle respective controls
  */

  void renu_control() {
    cataControl(RENU_PTO_TOGGLE, RENU_CATA_CONTROL);
    wingsControlSingle(RENU_WING_CONTROL);
    intakeControl(RENU_INTAKE_CONTROL);
  }
  
  void ria_control() {
    cataControl(RIA_PTO_TOGGLE, RIA_CATA_CONTROL);
    wingsControlSingle(RIA_WINGS_CONTROL);
    intakeControl(RIA_INTAKE_CONTROL);
  }

  void chris_control() {
    cataControl(RENU_PTO_TOGGLE, RENU_CATA_CONTROL);
    wingsControlSingle(RENU_WING_CONTROL);
    intakeControl(RENU_INTAKE_CONTROL);
  }
}