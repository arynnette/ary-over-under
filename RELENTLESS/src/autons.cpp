#include <stdlib.h>

#include "main.h"
#include "globals.hpp"
#include "superstructure.hpp"

using namespace globals;
using namespace superstruct;

void test_auton() {
  driveChassis(107, true);
  chassis.wait_drive();

  driveChassis(-38, true);
  chassis.wait_drive();

  turnChassis(-99);
  chassis.wait_drive();

  driveChassis(95, true);
  chassis.wait_drive();

  driveChassis(-10, true);
  chassis.wait_drive();

  turnChassis(15);
  chassis.wait_drive();

  driveChassis(40, true);
  chassis.wait_drive();

  leftSwing(60);
  chassis.wait_drive();

  driveChassis(-48, true);
  chassis.wait_drive();

  turnChassis(-90);
  chassis.wait_drive();
  
  driveChassis(12, true);
  chassis.wait_drive();

  // chassis.set_drive_pid(2, DRIVE_SPEED, false, true);
  // chassis.wait_drive();
}
  //pros::task_t intakeTask(run_intake_for, (void*) malloc(sizeof(double)), TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "runIntakeFor");
