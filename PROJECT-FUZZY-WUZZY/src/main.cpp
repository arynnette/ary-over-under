#include "main.h"

// void on_center_button() {
// 	static bool pressed = false;
// 	pressed = !pressed;
// 	if (pressed) {
// 		pros::lcd::set_text(2, "I was pressed!");
// 	} else {
// 		pros::lcd::clear_line(2);
// 	}
// }

void initialize() {
	pros::lcd::initialize();
	ary::printScr();
	pros::delay(500);

	/*
		initialize everything else
	*/

	ary::autonselector::auton_selector.add_autons({
		Auton("Testing Path\n\nTesting Path", autons::auton_test),
		Auton("Skills\n\nSkills route", autons::skills)
	});

	ary::autonselector::initialize();


	//pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		pros::delay(20);
	}
}
