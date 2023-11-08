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

  driveSync(-28, true);
  turnSync(75);

  pros::delay(100);
  toggleIntake(false);
  driveSync(35, true);
  driveSync(-35, true);

  turnSync(313);
  driveSync(40, true);
  pros::delay(400);
  toggleIntake(true);
  driveSync(-2, true);
  setTurnScale(0.75);
  turnSync(90);
  toggleIntake(false);
  wings.open();
  driveSync(55, true);
  wings.close();
  driveSync(-20, true);

  //driveSync(100, true);
}

void far_side() {
  wings.open();
  toggleIntake(true);
  driveSync(30, true);
  wings.close();
  turnSync(40);
  toggleIntake(false);
  driveSync(35, true);
  driveSync(-10, true);
  turnSync(135);
  driveSync(90, true);
  wings.open();
  turnSync(120);
}

// void far_side() {
//   driveSync(20, true);
//   rightSwing(25);
//   chassis.wait_drive();
  
// }

void skills() {
  toggleIntake(true);
  driveSync(30, true);
  toggleIntake(false);
  turnSync(45);
  driveSync(35, true);
  driveSync(-35, true);
  turnSync(-60);
  driveSync(10, true);
  wings.open();
}