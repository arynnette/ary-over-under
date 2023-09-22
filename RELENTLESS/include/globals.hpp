#include "main.h"
#include "okapi/api.hpp"
#include "lemlib/api.hpp"
#include "ary-lib/drive/drive.hpp"

#define TRACK_WDITH 11.5
#define PLACEHOLDER_TC_OFFSET 2.5
#define WHEEL_SIZE 2.75
#define DRIVE_RATIO 0.75

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

    extern lemlib::Drivetrain_t chassis_odom;

    extern pros::Rotation rot_vert;
    extern pros::Rotation rot_horiz;
    extern pros::Rotation enc_theta;

    extern lemlib::TrackingWheel vert_tracking_wheel;
    extern lemlib::TrackingWheel horiz_tracking_wheel;

    extern Drive chassis;
}