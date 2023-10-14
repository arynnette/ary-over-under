#include <stdlib.h>

#include "main.h"
#include "globals.hpp"
#include "superstructure.hpp"

using namespace globals;
using namespace superstruct;

// **CONSTANTS** //
const int DRIVE_SPEED = 110;
const int TURN_SPEED  = 101.5;
const int SWING_SPEED = 101.5;

void swingOther(void* p) {
  chassisLeft.initialize();
  chassisLeft.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
}

pros::Task swing_other(swingOther);

void default_constants() {
  chassisRight.set_slew_min_power(80, 80);
  chassisRight.set_slew_distance(7, 7);
  chassisRight.set_pid_constants(&chassisRight.headingPID, 11, 0, 17.5, 0);
  chassisRight.set_pid_constants(&chassisRight.forward_drivePID, 2, 0, 6.5, 0);
  chassisRight.set_pid_constants(&chassisRight.backward_drivePID, 2, 0, 6.5, 0);
  chassisRight.set_pid_constants(&chassisRight.turnPID, 8, 0.003, 27, 15);
  chassisRight.set_pid_constants(&chassisRight.swingPID, 7, 0, 35, 0);
  
  chassisLeft.set_slew_min_power(80, 80);
  chassisLeft.set_slew_distance(7, 7);
  chassisLeft.set_pid_constants(&chassisRight.headingPID, 11, 0, 17.5, 0);
  chassisLeft.set_pid_constants(&chassisRight.forward_drivePID, 2, 0, 6.5, 0);
  chassisLeft.set_pid_constants(&chassisRight.backward_drivePID, 2, 0, 6.5, 0);
  chassisLeft.set_pid_constants(&chassisRight.turnPID, 8, 0.003, 27, 15);
  chassisLeft.set_pid_constants(&chassisRight.swingPID, 7, 0, 35, 0);
}

void exit_condition_defaults() {
  chassisRight.set_exit_condition(chassisRight.turn_exit, 50, 2, 220, 3, 500, 500);//100, 3, 500, 7, 500, 500 //100, 2, 500, 4, 500, 500// 70, 1, 220, 3, 500, 500
  chassisRight.set_exit_condition(chassisRight.swing_exit, 100, 3, 500, 7, 500, 500);//100, 3, 500, 7, 500, 500
  chassisRight.set_exit_condition(chassisRight.drive_exit, 40, 80, 300, 150, 500, 500);//80, 50, 300, 150, 500, 500//20, 60, 300, 150, 500, 500

  chassisLeft.set_exit_condition(chassisRight.turn_exit, 50, 2, 220, 3, 500, 500);//100, 3, 500, 7, 500, 500 //100, 2, 500, 4, 500, 500// 70, 1, 220, 3, 500, 500
  chassisLeft.set_exit_condition(chassisRight.swing_exit, 100, 3, 500, 7, 500, 500);//100, 3, 500, 7, 500, 500
  chassisLeft.set_exit_condition(chassisRight.drive_exit, 40, 80, 300, 150, 500, 500);//80, 50, 300, 150, 500, 500//20, 60, 300, 150, 500, 500
}

// ** other stufff** //

// ** AUTONS ** //

void test_auton() {
  chassisRight.set_drive_pid(48, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();
  chassisRight.set_turn_pid(-65, TURN_SPEED);
  chassisRight.wait_drive();
  chassisRight.set_drive_pid(60, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();
  chassisRight.set_drive_pid(-10, DRIVE_SPEED, false, true);
  chassisRight.wait_drive();
  chassisRight.set_turn_pid(57, TURN_SPEED);
  chassisRight.wait_drive();
  chassisRight.set_drive_pid(43, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();
  chassisRight.set_swing_pid(LEFT_SWING, 80, SWING_SPEED);
  chassisRight.wait_drive();
  chassisRight.set_drive_pid(2, DRIVE_SPEED, false, true);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(-26, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  chassisRight.set_turn_pid(-45, TURN_SPEED);
  chassisRight.wait_drive();
}

void test_second() {
  chassisRight.set_drive_pid(107, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  //chassisRight.set_swing_pid(LEFT_SWING, 100, SWING_SPEED);
  //chassisRight.wait_drive();

  chassisRight.set_drive_pid(-38, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  chassisRight.set_turn_pid(-99, TURN_SPEED);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(95, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(-10, DRIVE_SPEED, false, true);
  chassisRight.wait_drive();

  chassisRight.set_turn_pid(15, TURN_SPEED);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(40, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  chassisRight.set_swing_pid(LEFT_SWING, 60, SWING_SPEED);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(-48, DRIVE_SPEED, true, true);
  chassisRight.wait_drive();

  chassisRight.set_turn_pid(-90, TURN_SPEED);
  chassisRight.wait_drive();

  chassisRight.set_drive_pid(12, DRIVE_SPEED, false, true);
  chassisRight.wait_drive();

  // chassisRight.set_drive_pid(2, DRIVE_SPEED, false, true);
  // chassisRight.wait_drive();
}

void arc_testing() {
  chassisRight.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  swing_other.resume();
}