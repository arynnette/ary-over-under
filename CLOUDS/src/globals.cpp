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

    /*
        {-2, -6, 12, 5}, -> left
        {-16, 1, 4, -3}, -> right
    */

    pros::Motor motor_tlf(14, MOTOR_GEARSET_06, false);
    pros::Motor motor_blb(9, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(3, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(7, MOTOR_GEARSET_06, false);
    pros::Motor motor_trf(15, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(6, MOTOR_GEARSET_06, true);
    pros::Motor motor_brf(12, MOTOR_GEARSET_06, false);
    pros::Motor motor_brb(5, MOTOR_GEARSET_06, false);

    pros::Imu inertial_sensor(11);

    pros::Motor_Group left_drive({ motor_tlf, motor_tlb, motor_blf, motor_blb });
    pros::Motor_Group right_drive({ motor_trf, motor_trb, motor_brf, motor_brb });

    /* PNEUMATICS */
    pros::ADIDigitalOut pto_piston('A');
    pros::ADIDigitalOut left_wing_piston('E');
    pros::ADIDigitalOut right_wing_piston('F');
    pros::ADIDigitalOut climb_piston('B'); 

    Wings wings;
    Timer timer;

    Drive chassis(
        {14, -9, -3, 7},
        {-15, 12, 5, -6},
        18,
        WHEEL_SIZE,
        600,
        DRIVE_RATIO
    );

    pros::Motor& intake_mtr = chassis.left_motors[3];
    pros::Motor& cata_mtr = chassis.right_motors[3];
}