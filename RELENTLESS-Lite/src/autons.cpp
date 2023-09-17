#include <stdlib.h>

#include "main.h"
#include "globals.hpp"
#include "superstructure.hpp"

using namespace globals;
using namespace superstruct;

// **CONSTANTS** //
const int DRIVE_SPEED = 110;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 17.5, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 2, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 2, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 30, 15);
  chassis.set_pid_constants(&chassis.swingPID, 6, 0, 40, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 50, 2, 220, 3, 500, 500);//100, 3, 500, 7, 500, 500 //100, 2, 500, 4, 500, 500// 70, 1, 220, 3, 500, 500
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);//100, 3, 500, 7, 500, 500
  chassis.set_exit_condition(chassis.drive_exit, 20, 40, 300, 150, 500, 500);//80, 50, 300, 150, 500, 500//20, 60, 300, 150, 500, 500
}

// ** other stufff** //

// ** AUTONS ** //

void test_auton() {
  chassis.set_drive_pid(48, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-65, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(60, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, DRIVE_SPEED, false, true);
  chassis.wait_drive();
  chassis.set_turn_pid(57, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(48, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 80, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(2, DRIVE_SPEED, false, true);
  chassis.wait_drive();
}