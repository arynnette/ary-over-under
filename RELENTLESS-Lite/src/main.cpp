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

  chassis.set_curve_buttons(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);
  chassis.toggle_modify_curve_with_controller(true);
  chassis.set_active_brake(0.1);
  chassis.set_curve_default(0.5, 0.5);

  chassis.set_joystick_drivescale(1.0);
  chassis.set_joystick_turnscale(1.0);

  default_constants(); 
  exit_condition_defaults();

  ary::autonselector::auton_selector.add_autons({
    Auton("Test Auton\n\nTesting Autonomous on field", test_auton),
  });

  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  chassis.initialize();
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
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  default_constants();

  ary::autonselector::auton_selector.call_selected_auton();
}

void opcontrol() {
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  while (true) {
    //chassis.arcade_standard(ary::SdPLIT, ary::DEFAULT); 
    chassis.arcade_standard(ary::SPLIT, ary::DEFAULT);
    pros::delay(ary::util::DELAY_TIME);
  }
}