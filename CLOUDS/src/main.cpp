#include "main.h"

using namespace globals;
using namespace superstruct;

e_controlsch currentuser = RENU;

void taskMethods() {
	while (true) {
		/*
			Handle controls for whoever is driving the bot at the moment, each available user a respective set of controls
			Available Options:
			RENU, RIA, CHRIS
		*/
		if (currentuser == RENU) {
			chassis.tank_control();
			renu_control();
		} else if (currentuser == RIA) {
			chassis.tank_control();
			renu_control();
		} else if (currentuser == CHRIS) {
			chassis.arcade_standard(ary::SINGLE, ary::DEFAULT);
			chris_control();
		} else {
			renu_control(); 
		}

 		pros::delay(ary::util::DELAY_TIME);
	}
}

pros::Task subsystemsTask(taskMethods);

void initialize() {
	subsystemsTask.suspend();
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
		Auton("Far side \n\nFar from alliance goal", near_side),
		Auton("Near side (far from alliance goal) \n\nCLOSE TO ALLIANCE GOAL", far_side),
		Auton("Skills \n\ncloudabunga", skills)
	});

	motorsCoast();

	chassis.initialize();
	ary::autonselector::initialize();
}

void disabled() {
	subsystemsTask.suspend();
}
void competition_initialize() {}

void autonomous() {
	subsystemsTask.resume();
	autonomousResets();
	ary::autonselector::auton_selector.call_selected_auton();
}

void opcontrol() {
	subsystemsTask.resume();
	disableActiveBrake();
	opControlInit(); // Configure the chassis for driver control
}
