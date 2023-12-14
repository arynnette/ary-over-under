#include "main.h"

using namespace globals;
using namespace superstruct;

e_controlsch currentuser = RENU;

void initialize() {
	ary::printScr();
	pros::delay(500); // Ports config

	/*
		Construct the chassis and it's constants
		chassisInit() -> Adjusts drive curves, active brake constants, among other things 
		configureConstants() -> Sets PID constants on the chassis
		configureExitConditions() -> Sets default values for PID Exit conditions
	*/
	chassisInit();
	configureConstants();
	configureExitConditions();
	
	/*
		Add autonomous paths to the auto selection
	*/
	ary::autonselector::auton_selector.add_autons({
		Auton("Five triballl\n\nThey ain't believe in us..", five_triball_remove),
		Auton("Far side \n\nFar from alliance goal", near_side),
		Auton("Near side (far from alliance goal) \n\nCLOSE TO ALLIANCE GOAL", far_side),
		Auton("Four triball contact\n\nfour triballs and then contact elevation", four_triball_contact),
		Auton("Skills \n\nCLOUDABUNGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", skills)
	});

	superstruct::motorsCoast();

	globals::chassis.initialize();
	ary::autonselector::initialize();
}

void disabled() {
}

void competition_initialize() {}

void autonomous() {
	autonomousResets();
	ary::autonselector::auton_selector.call_selected_auton();
}

void opcontrol() {
	disableActiveBrake();
	opControlInit(); // Configure the chassis for driver control

	while (true) {
		globals::chassis.tank_control();
		renu_control();
		pros::delay(ary::util::DELAY_TIME);
	}
}