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

    pros::Motor motor_tlf(12, MOTOR_GEARSET_06, false);
    pros::Motor motor_blb(6, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(2, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(5, MOTOR_GEARSET_06, false);
    pros::Motor motor_trf(16, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(3, MOTOR_GEARSET_06, true); // cata running
    pros::Motor motor_brf(1, MOTOR_GEARSET_06, false);
    pros::Motor motor_brb(4, MOTOR_GEARSET_06, false);

    pros::Motor_Group left_drive({ motor_tlf, motor_tlb, motor_blf, motor_blb });
    pros::Motor_Group right_drive({ motor_trf, motor_trb, motor_brf, motor_brb });

    // Electronics / Pneumatics / Sensors
    pros::ADIDigitalOut pto_piston('A');

    pros::ADIDigitalOut left_wing_piston('E');
    pros::ADIDigitalOut right_wing_piston('F');

    pros::ADIDigitalOut intake_piston('D');

    pros::ADIDigitalOut climb_piston('B'); 

    Wings wings;
    Timer timer;

    pros::Imu inertial_sensor(18);

    lemlib::Drivetrain_t dt_odom {
        &left_drive,
        &right_drive,
        TRACK_WIDTH,
        WHEEL_SIZE,
        DRIVE_RPM
    };

    lemlib::OdomSensors_t chassis_sensors {
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        &inertial_sensor
    };

    lemlib::ChassisController_t latController {
        0.55, // kP
        5, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
    };

    lemlib::ChassisController_t angController {
        6.5, // kP
        35, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        40 // slew rate
    };

    Drive chassis(
        {-2, -6, 12, 5},
        {-16, 1, 4, -3},
        18,
        WHEEL_SIZE,
        600,
        DRIVE_RATIO
    );
    
    lemlib::Chassis chassis_odom(dt_odom, latController, angController, chassis_sensors);

    pros::Motor& intake_mtr = chassis.left_motors[3];
    pros::Motor& cata_mtr = chassis.right_motors[3];
}