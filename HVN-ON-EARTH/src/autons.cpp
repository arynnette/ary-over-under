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

/*
  To run when our robot is starting on the far side from our alliance zone
  /
  close to our alliance goal.
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

  //Collect and score the back outer triball
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


  //Gain control of third triball, use wings to score last one
  turnSync(313);
  driveSync(40, true);
  pros::delay(400);
  toggleIntake(true);
  driveSync(-2, true);
  setTurnScale(0.75);
  turnSync(90);
  toggleIntake(false);
  wings.open();
  driveSync(65, true);
  wings.close();
  driveSync(-20, true);
}

/*
  To run when our robot is starting on the near side from our alliance zone
  /
  far from our alliance goal.
*/
void far_side() {
  wings.open(); // Prepare for removal of match load triball
  toggleIntake(true); // Secure preload triball

  // Drive forward to removal match load triball with wings, close wings immediately
  driveSync(30, true); 
  wings.close();

  //Score the preload
  turnSync(40);
  toggleIntake(false);
  driveSync(35, true);
  driveSync(-10, true);

  //Turn towards the elevation bar area
  turnSync(135);
  driveSync(90, true);
  wings.open(); // Open our wings as they are being used to contact the bar
  turnSync(120); // Turn slightly to guarantee contact
}

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