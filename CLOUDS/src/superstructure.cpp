#include "superstructure.hpp"

using namespace ary;
using namespace globals;

bool ptoEnabled = false;
bool wingsOpen = false;

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
    chassis.set_curve_default(1.075, 1.075);

    /* Adjust the adjust the factor by which the drive velocity is adjusted */ 
    chassis.set_joystick_drivescale(1.0);
    chassis.set_joystick_turnscale(1.0); 
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
    chassis.set_pid_constants(&chassis.forward_drivePID, 0.5, 0, 5, 0);
    chassis.set_pid_constants(&chassis.backward_drivePID, 0.5, 0, 5, 0);
    chassis.set_pid_constants(&chassis.turnPID, 6.25, 0.003, 57, 15);
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
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
  }

  // Drives forward, runs next commands AFTER waiting for the drive to complete 
  void driveSync(double dist, bool useHeadingCorrection) {
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
    chassis.wait_drive();
  }

  // Drives forward, runs next commands AFTER reaching a certain measurement/error along the path
  void driveWithMD(double dist, bool useHeadingCorrection, double waitUntilDist) {
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
    chassis.wait_until(waitUntilDist);
  }

  // Turns the chassis, runs other commands after it has run.
  void turnSync(double theta) {
    chassis.set_turn(theta, TURN_SPEED * turnScale);
    chassis.wait_drive();
  }

  // Turns the chassis, runs other commands immediately after call
  void turnAsync(double theta) {
    chassis.set_turn(theta, TURN_SPEED * turnScale);
  }

  // Moves only the right side of the chassis so it can make a left turn
  void leftSwing(double theta) {
    chassis.set_swing(LEFT_SWING, theta, SWING_SPEED * swingScale);
  }

  // Moves only the left side of the chassis so it can make a right turn
  void rightSwing(double theta) {
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
  void togglePto(bool toggle) {
    ptoEnabled = toggle;
    chassis.pto_toggle({intake_mtr, cata_mtr}, toggle); // Configure the listed PTO motors to whatever value toggle is.
    pto_piston.set_value(toggle);

    if (toggle) {
      intake_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
      cata_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
    }
  }

  void runCata(double inpt) {
    if (!ptoEnabled) return;
    cata_mtr.move_voltage(inpt);
  }

  void runIntake(double inpt) {
    if (!ptoEnabled) return;
    intake_mtr.move_voltage(inpt);
  }

  int lock = 0;
  void subsysControl(pros::controller_digital_e_t ptoToggleButton, pros::controller_digital_e_t cataRunButton, pros::controller_digital_e_t intakeButton, pros::controller_digital_e_t outtakeButton) {
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

    if (globals::master.get_digital(intakeButton)) {
      runIntake(-12000);
    } else if (globals::master.get_digital(outtakeButton)) {
      runIntake(12000);
    } else {
      runIntake(0);
    }
  }

  void wingsControl(pros::controller_digital_e_t wingControlButton) {
    if (globals::master.get_digital_new_press(wingControlButton)) {
      if (wings.getState() == 0) // A value of 0 indicates that both wings are closed
        wings.open();
      else if (wings.getState() == 3) // A value of 3 indicates that both wings are open
        wings.close();
    }
  }

  /*
    Controls -> For whoever is controlling the robot
  */
  void renu_control() {
    subsysControl(RENU_PTO_TOGGLE, RENU_CATA_CONTROL, RENU_INTAKE_CONTROL_INTAKE, RENU_INTAKE_CONTROL_OUTTAKE);
    wingsControl(RENU_WING_CONTROL);
  }
  
  void ria_control() {
    subsysControl(RENU_PTO_TOGGLE, RENU_CATA_CONTROL, RENU_INTAKE_CONTROL_INTAKE, RENU_INTAKE_CONTROL_OUTTAKE);
    wingsControl(RENU_WING_CONTROL);
  }

  void chris_control() {
    subsysControl(RENU_PTO_TOGGLE, RENU_CATA_CONTROL, RENU_INTAKE_CONTROL_INTAKE, RENU_INTAKE_CONTROL_OUTTAKE);
    wingsControl(RENU_WING_CONTROL);
  }
}