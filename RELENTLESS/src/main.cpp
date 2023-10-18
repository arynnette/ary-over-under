/*
	main.cpp

	The entry point for the bot
*/

#include "main.h"
#include "wings.h"

using namespace globals;
using namespace superstruct;

e_controlsch currentuser = RENU;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	ary::printScr();
  
	pros::delay(500); // Give time for legacy ports configure

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
		Auton("Near side (close to alliance goal) \n\nTo run when near alliance goal", near_side),
		Auton("Far side (far from alliance goal) \n\nTo run when far from alliance goal", far_side)
	});

	motorsCoast(); // Allow the motors to coast initially

	chassis.initialize();
	ary::autonselector::initialize();
}

void disabled() {}
void competition_initialize() {}

void autonomous() {
	autonomousResets();
	ary::autonselector::auton_selector.call_selected_auton();
}

void opcontrol() {
	opControlInit(); // Configure the chassis for driver control

	while (true) {	

		/*
			Handle controls for whoever is driving the bot at the moment, each available user a respective set of controls'
			Available Options:
			RENU, RIA, CHRIS
		*/

		if (currentuser == RENU) {
			chassis.tank_control();
			renu_control();
		} else if (currentuser = RIA) {
			chassis.tank_control(); // 
			ria_control();
		} else if (currentuser == CHRIS) {
			chassis.arcade_standard(ary::SPLIT, ary::DEFAULT);
			renu_control();
		} else {
			renu_control(); 
		}

 		pros::delay(ary::util::DELAY_TIME);
	}
}
