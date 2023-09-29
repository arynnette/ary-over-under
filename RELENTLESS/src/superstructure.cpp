#include "superstructure.hpp"

using namespace ary;
using namespace globals;

bool ptoEnabled = false;
namespace superstruct {
  void configureExitConditions() {
    chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
    chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
    chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
  }

  void configureConstants() {
    chassis.set_slew_min_power(80, 80);
    chassis.set_slew_distance(7, 7);
    chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
    chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
    chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
    chassis.set_pid_constants(&chassis.turnPID, 4, 0.003, 35, 15);
    chassis.set_pid_constants(&chassis.swingPID, 6, 0, 40, 0);
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


  // motion and stuff
  void driveChassis(double dist, double speedScale, bool useHeadingCorrection) {
    //chassis.set_mode(ary::DRIVE);
    chassis.set_drive(dist, DRIVE_SPEED * speedScale, (dist > 14.0) ? true : false, useHeadingCorrection); 
  }

  void turnChassis(double theta, double turnSpeedScale) {
    //chassis.set_mode(ary::TURN);
    chassis.set_turn(theta, TURN_SPEED * turnSpeedScale);
  }

  void leftSwing(double theta, double swingSpeedScale) {
    //chassis.set_mode(SWING);
    chassis.set_swing(LEFT_SWING, theta, SWING_SPEED * swingSpeedScale);
  }

  void rightSwing(double theta, double swingSpeedScale) {
    //chassis.set_mode(SWING);
    chassis.set_swing(RIGHT_SWING, theta, SWING_SPEED * swingSpeedScale);
  }

  // Structure methods

  void togglePto(bool toggle) {
    ptoEnabled = toggle;
    chassis.pto_toggle({cata_left, cata_right}, toggle);
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
  void cataControl() {
    if (globals::master.get_digital(DIGITAL_LEFT) && lock == 0) {
      togglePto(!ptoEnabled);
      lock = 1;
    } else if(!globals::master.get_digital(DIGITAL_LEFT)) {
      lock = 0;
    }

    if (globals::master.get_digital(DIGITAL_R1)) {
			runCata(12000);
		} else {
			runCata(0);
		}
  }
}