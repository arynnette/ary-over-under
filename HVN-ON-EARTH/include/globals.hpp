#pragma once

#include "main.h"
#include "Wings.h"
#include "Timer.h"

#define TRACK_WIDTH 11.5
#define PLACEHOLDER_TC_OFFSET 2.5
#define WHEEL_SIZE 2.75
#define DRIVE_RATIO 0.75
#define DRIVE_RPM 450

namespace globals {
    extern pros::Controller master;

    extern pros::Motor motor_tlf;
    extern pros::Motor motor_tlb;
    extern pros::Motor motor_blf;
    extern pros::Motor motor_blb;
    extern pros::Motor motor_trf;
    extern pros::Motor motor_trb;
    extern pros::Motor motor_brf;
    extern pros::Motor motor_brb;

    extern pros::Motor_Group left_drive;
    extern pros::Motor_Group right_drive;

    extern lemlib::Drivetrain_t dt_odom;

    extern lemlib::OdomSensors_t chassis_sensors;

    extern lemlib::ChassisController_t latController;
    extern lemlib::ChassisController_t angController;

    extern lemlib::Chassis chassis_odom;

    extern pros::Rotation rot_vert;
    extern pros::Rotation rot_horiz;
    extern pros::Rotation enc_theta;

    extern pros::ADIDigitalOut pto_piston;

    extern pros::ADIDigitalOut left_wing_piston;
    extern pros::ADIDigitalOut right_wing_piston;

    extern pros::ADIDigitalOut intake_piston;

    extern pros::ADIDigitalOut climb_piston;

    extern Wings wings;
    extern Timer timer;

    extern lemlib::TrackingWheel vert_tracking_wheel;
    extern lemlib::TrackingWheel horiz_tracking_wheel;

    extern pros::Imu inertial_sensor; 

    extern Drive chassis;

    extern pros::Motor& cata_left;
    extern pros::Motor& cata_right;

    enum e_controlsch {
        RENU,
        RIA,
        CHRIS
    };
}