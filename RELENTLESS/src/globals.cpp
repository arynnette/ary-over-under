/*
    globals.cpp
    
    Contains all devices and electronics used for the robot
    Holds other mechanicsm classes.
*/

#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_tlf(12, MOTOR_GEARSET_06, false);
    pros::Motor motor_blb(6, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(2, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(5, MOTOR_GEARSET_06, false);
    pros::Motor motor_trf(16, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(3, MOTOR_GEARSET_06, true);
    pros::Motor motor_brf(1, MOTOR_GEARSET_06, false);
    pros::Motor motor_brb(4, MOTOR_GEARSET_06, false);

    pros::Motor_Group left_drive({ motor_tlf, motor_tlb, motor_blf, motor_blb });
    pros::Motor_Group right_drive({ motor_trf, motor_trb, motor_brf, motor_brb });

    // Electronics / Pneumatics / Sensors
    pros::Distance intake_dist_sens(21);

    pros::ADIDigitalOut pto_piston('A');

    pros::ADIDigitalOut left_wing_piston('C');
    pros::ADIDigitalOut right_wing_piston('B');

    pros::ADIDigitalOut intake_piston('D');

    pros::ADIDigitalOut doinker_piston('E');

    Wings wings;

    Drive chassis(
        {-2, -6, 12, 5},
        {-16, 1, 4, -3},
        16,
        WHEEL_SIZE,
        600,
        DRIVE_RATIO
    ); 

    pros::Motor& cata_left = chassis.left_motors[3];
    pros::Motor& cata_right = chassis.right_motors[3];
}