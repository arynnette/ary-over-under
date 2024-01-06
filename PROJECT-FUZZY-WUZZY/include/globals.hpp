#pragma once

// CONSTANTS DEFINITIONS
#define HORIZONTAL_TW_OFFSET 1.0
#define VERTICAL_TW_OFFSET 1.0
#define CHASSIS_TRACK_WIDTH 12.5
#define CHASSIS_RPM 450
#define CHASE_POWER 2

#include "main.h"

namespace globals {
    extern pros::Controller master;

    extern pros::Motor left_front;
    extern pros::Motor left_middle;
    extern pros::Motor left_back;
    extern pros::Motor right_front;
    extern pros::Motor right_middle;
    extern pros::Motor right_back;
    
    extern pros::Motor_Group left_drive;
    extern pros::Motor_Group right_drive;
    
    extern pros::Imu imu;

    // ODOM. SENSORS
    extern pros::Rotation horizontal_tw_enc;
    extern pros::Rotation vertical_tw_enc;

    // LEM IMPL.
    extern lemlib::TrackingWheel horizontal_tw;
    extern lemlib::TrackingWheel vertical_tw;

    extern lemlib::Drivetrain drivetrain;
    extern lemlib::ControllerSettings lateral_controller;
    extern lemlib::ControllerSettings angular_controller;

    extern lemlib::OdomSensors odom_sensors;
    extern lemlib::Chassis chassis;
}