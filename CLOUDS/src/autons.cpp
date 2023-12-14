#include "main.h"
#include <stdlib.h>

using namespace globals;
using namespace superstruct;

/*
  To run when our robot is starting on the far side from our alliance zone
  /
  close to our alliance goal.
*/
void near_side() {
  // Score the triball preload
  //togglePto(true);
  setIntakeSpeed(-12000);
  driveSync(90, true);
  turnSync(90);

  // INTAKE PLACERHOLDER -> OUT
  pros::delay(125);
  driveSync(22, true);
  driveSync(-19, true);

  //Collect and score the back outer triball
  turnSync(-118);
  driveSync(50, true);
  pros::delay(150);
  // INTAKE PLACEHOLDER -> OUT
  pros::delay(100);

  driveSync(-28, true);
  turnSync(75);

  pros::delay(100);
  // INTAKE PLACEHOLDER -> OUT
  driveSync(35, true);
  driveSync(-35, true);


  //Gain control of third triball, use wings to score last one
  turnSync(313);
  driveSync(40, true);
  pros::delay(400);
  // INTAKE PLACEHOLDER -> IN
  driveSync(-2, true);
  setTurnScale(0.75);
  turnSync(90);
  // INTAKE PLACEHOLDER -> IN
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
  //toggleIntake(true); // Secure preload triball

  // Drive forward to removal match load triball with wings, close wings immediately
  driveSync(30, true);
  wings.close();

  //Score the preload
  turnSync(40);
  //toggleIntake(false);
  driveSync(35, true);
  driveSync(-10, true);

  //Turn towards the elevation bar area
  turnSync(135);
  driveSync(90, true);
  wings.open(); // Open our wings as they are being used to contact the bar
  turnSync(120);
}

void four_triball_contact() {
  /*  */
  togglePto(true);
  driveSync(25, true);
  turnSync(-37);
  setIntakeSpeed(-12000);
  driveSync(35, true);
  turnSync(80);
  setIntakeSpeed(8000);
  driveSync(10, true);
  driveSync(-20, true);
  pros::delay(250);
  turnSync(-37);
  setIntakeSpeed(-12000);
  driveSync(25, true);
  turnSync(90);
  wings.open();
  setIntakeSpeed(12000);
  driveSync(53, true);
  wings.close();
  driveSync(-10, true);
  turnSync(-134);
  setIntakeSpeed(-12000);
  driveSync(53, true);
  driveSync(-10, true);


  turnSync(67);
  setIntakeSpeed(12000);
  wings.open();
  driveSync(45, true);
  driveSync(-15, true);
  wings.close();
  pros::delay(250);
  turnSync(180);
  driveSync(35, true);
  turnSync(125);
  driveSync(30, true);
  wings.open();
  turnSync(30);
  driveSync(12, true);
  rightSwing(0);
  wings.close();
  driveSync(35, true);
}

void five_triball_remove() {
  /*  */
  togglePto(true);
  driveSync(25, true);
  turnSync(-37);
  setIntakeSpeed(-12000);
  driveSync(35, true);
  turnSync(80);
  setIntakeSpeed(8000);
  driveSync(10, true);
  driveSync(-20, true);
  pros::delay(250);
  turnSync(-37);
  setIntakeSpeed(-12000);
  driveSync(25, true);
  turnSync(90);
  wings.open();
  setIntakeSpeed(12000);
  driveSync(53, true);
  wings.close();
  driveSync(-10, true);
  turnSync(-134);
  setIntakeSpeed(-12000);
  driveSync(53, true);
  driveSync(-20, true);

  turnSync(125);
  driveSync(65, true);

  wings.open();
  turnSync(30);

  driveSync(12, true);
  rightSwing(0);
  wings.close();
  driveSync(35, true);
  togglePto(false);
}

void skills() {
  //toggleIntake(true);
  driveSync(10, true);
  //toggleIntake(false);
  turnSync(45);
  driveSync(35, true);
  driveSync(-35, true);
  turnSync(-60);
  driveSync(10, true);
  wings.open();

  togglePto(true);
  pros::delay(100);
  timer.reset();
  while (timer.getElapsedTimeMS() < 35000) {
    motor_trb.move_voltage(-12000);
  }
  motor_trb.move_voltage(0); // i hate my life
  togglePto(false);

  wings.close();

  driveSync(-35, true); 
  turnSync(10);
  driveSync(-40, true);
  turnSync(45);
  driveSync(125, true);
  //turnSync();
}

void testingAsyncRunning() {
  togglePto(true);
  setIntakeSpeed(-12000);
  pros::delay(5000);
  driveSync(30, true);
}