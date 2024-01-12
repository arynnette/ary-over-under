#include "main.h"
#include "globals.hpp"

using namespace lemlib;

namespace globals {
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    pros::Motor motor_LF(PORT_LF, pros::E_MOTOR_GEARSET_06, true);
    pros::Motor motor_LM(PORT_LM, pros::E_MOTOR_GEARSET_06, true);
    pros::Motor motor_LB(PORT_LB, pros::E_MOTOR_GEARSET_06, true);
    pros::Motor motor_RF(PORT_RF, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor motor_RM(PORT_RM, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor motor_RB(PORT_RB, pros::E_MOTOR_GEARSET_06, false);
    
    pros::Motor_Group left_drive({ motor_LF, motor_LM, motor_LB });
    pros::Motor_Group right_drive({ motor_RF, motor_RM, motor_RB });
    
    pros::Imu imu(7);

    //ODOM. SENSORS
    pros::Rotation horizontal_tw_enc(8, false);
    pros::Rotation vertical_tw_enc(9, false);

    //LEM IMPL.
    TrackingWheel horizontal_tw(&horizontal_tw_enc, Omniwheel::NEW_275, HORIZONTAL_TW_OFFSET);
    TrackingWheel vertical_tw(&vertical_tw_enc, Omniwheel::NEW_275, VERTICAL_TW_OFFSET);

    Drivetrain drivetrain(
        &left_drive,
        &right_drive,
        CHASSIS_TRACK_WIDTH,
        Omniwheel::NEW_325,
        CHASSIS_RPM,
        CHASE_POWER
    );

    ControllerSettings lateral_controller(
        10, // proportional gain (kP)
        0, // integral gain (kI)
        3, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        20 // maximum acceleration (slew)
    );

    ControllerSettings angular_controller(
        2, // proportional gain (kP)
        0, // integral gain (kI)
        10, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
    );

    OdomSensors odom_sensors(
        &vertical_tw,
        nullptr,
        &horizontal_tw,
        nullptr,
        &imu
    );

    Chassis chassis(
        drivetrain,
        lateral_controller,
        angular_controller,
        odom_sensors
    );

}