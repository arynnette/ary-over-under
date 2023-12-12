#pragma once

#include "main.h"
#include "Wings.h"
#include "Timer.h"

#define TRACK_WIDTH 11.5
#define PLACEHOLDER_TC_OFFSET 2.5
#define WHEEL_SIZE 2.75
#define DRIVE_RATIO 0.75
#define DRIVE_RPM 450

namespace globals
{
    extern pros::Controller master;

    extern pros::Motor motor_tlf;
    extern pros::Motor motor_tlb;
    extern pros::Motor motor_blf;
    extern pros::Motor motor_blb;
    extern pros::Motor motor_trf;
    extern pros::Motor motor_trb;
    extern pros::Motor motor_brf;
    extern pros::Motor motor_brb;

    extern pros::Imu inertial_sensor;

    extern pros::Motor_Group left_drive;
    extern pros::Motor_Group right_drive;

    /* PNEUMATICS */
    extern pros::ADIDigitalOut pto_piston;
    extern pros::ADIDigitalOut left_wing_piston;
    extern pros::ADIDigitalOut right_wing_piston;
    extern pros::ADIDigitalOut climb_piston_one;
    extern pros::ADIDigitalOut climb_piston_two;

    extern Wings wings;
    extern Timer timer;

    extern Drive chassis;

    extern pros::Motor &intake_mtr;
    extern pros::Motor &cata_mtr;

    enum e_controlsch
    {
        RENU,
        RIA,
        CHRIS
    };
}