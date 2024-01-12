#include "main.h"

pros::Task telemetry(superstruct::chassis_telemetry);

void initialize() {
	pros::lcd::initialize();
	superstruct::initialize_superstruct();
	ary::printScr();
	pros::delay(700);

	/*
		initialize everything else
	*/

	ary::autonselector::auton_selector.add_autons({
		Auton("Testing Path\n\nTesting Path", autons::auton_test),
		Auton("Skills\n\nSkills route", autons::skills)
	});

	ary::autonselector::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		int leftY = globals::master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightY = globals::master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		globals::chassis.tank(leftY, rightY, DRIVE_GAIN);
		pros::delay(20);
	}
}
