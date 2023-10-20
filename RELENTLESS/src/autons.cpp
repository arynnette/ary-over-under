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
  driveSync(107, true);
  // Go forward
  
  // Get the furthest triball
  driveSync(-38, true); // Move away from the goal
   turnSync(-99); // Turn towards the triball against the barrier
  driveSync(95, true); // Drive towards the triball

  // Turn towards the goal, and score the triball.
  driveSync(-10, true); // Move away from the point
  turnSync(15); // Turn towards the goal 
  driveSync(40, true); // Drive towards the goal and score the triball
  leftSwing(60);
  chassis.wait_drive();

  //Drive backwards, turn to get the next triball off the line
  driveSync(-48, true); // Move away from the goal towards the nearest triball
  turnSync(-90); // Turn to the triball and intake
  driveSync(12, true);

  
}

void far_side() {
  toggleIntake(true);
  driveSync(60, true);
  turnSync(-90);
  
  toggleIntake(false);
  driveSync(30, true);
  driveSync(-30, true);

  turnSync(-45);
  driveSync(100, true);
  toggleRemovalMech(true);
  driveSync(-35, true);
  toggleRemovalMech(false);

  turnSync(55);
  driveSync(70, true);

}
