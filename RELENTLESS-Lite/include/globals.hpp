#include "main.h"

#define TRACK_WIDTH 11.5
#define DRIVE_RATIO 0.75
#define DRIVE_RPM 450
#define WHEEL_SIZE 2.75

extern pros::Task swing_other;

namespace globals {
    extern pros::Controller master;

    extern pros::Motor motor_fl;
    extern pros::Motor motor_ml;
    extern pros::Motor motor_bl;
    extern pros::Motor motor_fr;
    extern pros::Motor motor_mr;
    extern pros::Motor motor_br;

    extern pros::Motor_Group left_drive;
    extern pros::Motor_Group right_drive;

    extern lemlib::Drivetrain drivetrain;
    extern lemlib::linearController;
    extern lemlib::angularController;
    extern lemlib::sensors;
    extern lemlib::Chassis chassis;
    extern Drive chassisRight;
    extern Drive chassisLeft;