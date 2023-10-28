#include "main.h"
#include "globals.hpp"
#include "autons.hpp"
#include "superstructure.hpp"
#include "arylib/autonselector.hpp"

using namespace superstruct;
using namespace globals;

void initialize() {
  ary::print_ez_template();
  
  pros::delay(500); // legacy ports configure

  /*
    When the robot first starts up we want to do a couple things:
      - Adjust the drivetrain curve bottons so it does not interfere with any of the driver controls.
      - Enable the joystick curve
      - Enable active break on the drive
        - Active break is a P controller applied to the drivetrain in order to help it maintain it's position, resisting external forces.
        - 
  */

  chassisRight.set_curve_buttons(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);
  chassisRight.toggle_modify_curve_with_controller(true);
  chassisRight.set_active_brake(0.1);
  chassisRight.set_curve_default(0.5, 0.5);

  chassisRight.set_joystick_drivescale(1.0);
  chassisRight.set_joystick_turnscale(1.0);

  chassisLeft.set_curve_buttons(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);
  chassisLeft.toggle_modify_curve_with_controller(true);
  chassisLeft.set_active_brake(0.1);
  chassisLeft.set_curve_default(0.5, 0.5);

  chassisLeft.set_joystick_drivescale(1.0);
  chassisLeft.set_joystick_turnscale(1.0);

  default_constants(); 
  exit_condition_defaults();

  ary::autonselector::auton_selector.add_autons({
    Auton("Test Auton\n\nTesting Autonomous on field", test_auton),
    Auton("Test Auton - The Sequel\n\nyo mama", test_second), // TODO: Change this before putting this in the notebook LOL
    Auton("CURVATURE, ARCING, AND EVERYTHING IN BETWEEN more like motion profiles", motion_profile_test)
  });

  chassisRight.set_drive_brake(MOTOR_BRAKE_COAST);
  chassisLeft.set_drive_brake(MOTOR_BRAKE_COAST);

  //handle pto and stuff 
  //chassisRight.pto_add();

  chassisRight.initialize();
  ary::autonselector::initialize();
}



// fms / comp switch disable
void disabled() {
  // . . .
}



// run after init if comp control
void competition_initialize() {
  // . . .
}

void autonomous() {
  chassisRight.reset_pid_targets();
  chassisRight.reset_gyro();
  chassisRight.reset_drive_sensor();
  chassisRight.set_drive_brake(MOTOR_BRAKE_COAST);

  chassisLeft.reset_pid_targets();
  chassisLeft.reset_gyro();
  chassisLeft.reset_drive_sensor();
  chassisLeft.set_drive_brake(MOTOR_BRAKE_COAST);
  default_constants();

  ary::autonselector::auton_selector.call_selected_auton();
}

void opcontrol() {
  chassisRight.set_drive_brake(MOTOR_BRAKE_COAST);
  chassisRight.set_active_brake(0);

  while (true) {
    //chassisRight.arcade_standard(ary::SdPLIT, ary::DEFAULT); 
    //chassisRight.arcade_standard(ary::SPLIT, ary::DEFAULT);
    chassisRight.tank();

    // if  (globals::master.get_digital(DIGITAL_R1)) {
    //   cata_left.move_voltage(12000);
    //   cata_right.move_voltage(-12000);
    // } else {
    //   cata_left.move_voltage(0);
    //   cata_right.move_voltage(0);
    // }
    pros::delay(ary::util::DELAY_TIME);
  }
  
}