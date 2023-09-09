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
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 4, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 6, 0, 40, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

// ** other stufff** //

// ** AUTONS ** //

void test_auton() {
    chassis.set_drive_pid(5, DRIVE_SPEED, false, true);
    chassis.set_swing_pid(e_swing::LEFT_SWING, 50, TURN_SPEED);
    chassis.set_drive_pid(36, DRIVE_SPEED, true, true);
    chassis.wait_until(24);
    /* RUN THE INTAKE */
    pros::delay(500);
    chassis.set_drive_pid(-2, DRIVE_SPEED, false, false);
    chassis.set_turn_pid(130, TURN_SPEED);

  //pros::task_t intakeTask(run_intake_for, (void*) malloc(sizeof(double)), TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "runIntakeFor");
}