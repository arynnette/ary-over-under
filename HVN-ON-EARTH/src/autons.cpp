#include "main.h"
#include <stdlib.h>

using namespace globals;
using namespace superstruct;

/*
  TODO:
    - AUTONS
      - SameBarQual
      - OppBarQual
      - SameBarElims
      - OppBar Elims
*/

/*
  chassis.wait_drive() -> Waits for the drivetrain to complete whatever movement is happening
  chassis.wait_until(double measurement) -> Waits for the drivetrain to reach a certain measurement before performing the next task.
*/

void near_side() {
  // Score the triball preload
  toggleIntake(true);
  driveSync(90, true);
  turnSync(90);

  toggleIntake(false);
  pros::delay(50);
  driveSync(22, true);
  driveSync(-19, true);

  turnSync(-118);
  driveSync(50, true);
  pros::delay(150);
  toggleIntake(true);
  pros::delay(100);

  driveSync(-35, true);
  turnSync(75);

  pros::delay(100);
  toggleIntake(false);
  driveSync(35, true);
  driveSync(-20, true);

  turnSync(300);
  driveSync(50, true);
  pros::delay(400);
  toggleIntake(true);
  driveSync(-31, true);
  turnSync(90);
  toggleIntake(false);
  wings.open();
  driveSync(50, true);
  wings.close();
  driveSync(-20, true);

  //driveSync(100, true);
  
}

void far_side() {
  toggleIntake(true);
  wings.open();
  pros::delay(1000);
  turnSync(-180);
}

// void far_side() {
//   driveSync(20, true);
//   rightSwing(25);
//   chassis.wait_drive();
  
// }

void skills() {
  
}

void test_seq() {
  driveSync(20, true);
}

void odom_test() {
  chassis_odom.moveTo(10, 10, 1000);
  chassis_odom.turnTo(15, 15, 1000);
};
