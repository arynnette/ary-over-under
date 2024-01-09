#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_fl(15, MOTOR_GEARSET_6, true);
    pros::Motor motor_bl(20, MOTOR_GEARSET_6, true);
    pros::Motor motor_fr(12, MOTOR_GEARSET_6, false);
    pros::Motor motor_br(2, MOTOR_GEARSET_6, false);

    pros::Motor_Group left_drive({ motor_fl, motor_bl });
    pros::Motor_Group right_drive({ motor_fr, motor_br });

    Drive chassisRight(
        {1, 5},
        {-20, -15},
        19,
        3.25,
        600,
        0.75
    );

    lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
        &rightMotors, // right motor group
        10, // 10 inch track width
        lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
        360, // drivetrain rpm is 360
        2 // chase power is 2. If we had traction wheels, it would have been 8
    );

    // lateral motion controller
    lemlib::ControllerSettings linearController(10, // proportional gain (kP)
        30, // derivative gain (kD)
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        20 // maximum acceleration (slew)
    );

    // angular motion controller
    lemlib::ControllerSettings angularController(2, // proportional gain (kP)
        10, // derivative gain (kD)
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        20 // maximum acceleration (slew)
    );

// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
    lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
        nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
        &horizontal, // horizontal tracking wheel 1
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu // inertial sensor
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);
}