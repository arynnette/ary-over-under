#include "main.h"
#include "config.hpp"
#include "manager.hpp"

pros::Task t_telemetry(manager::telemetry_mgr);

void initialize() {
	pros::lcd::initialize();

	config::enc_x_ax.reset();
	config::enc_y_ax.reset();
	config::enc_z_ax.reset();


	config::enc_x_ax.reset_position();
	config::enc_y_ax.reset_position();
	config::enc_z_ax.reset_position();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	manager::yGoTo(2.5, 1500);
	manager::xGoTo(3.75, 1500);
	manager::yGoTo(-2.5, 1500);
	manager::xGoTo(-3.25, 350);
}

void opcontrol() {
	while (true) {
		manager::manualControl();
		pros::delay(20);
	}
}
