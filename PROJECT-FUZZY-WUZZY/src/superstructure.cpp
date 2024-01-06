#include "main.h"
#include "superstructure.hpp"

namespace superstruct {
    void initialize_superstruct() {
        globals::chassis.calibrate();
    }

    void chassis_telemetry() {
        pros::delay(2500); // give time for the chassis to calibrate
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", globals::chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", globals::chassis.getPose().y); //s y
            pros::lcd::print(2, "Theta: %f", globals::chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", globals::chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    }
}