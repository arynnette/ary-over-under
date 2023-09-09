#include "main.h"
#include "okapi/api.hpp"
#include "lemlib/api.hpp"
#include "ary-lib/drive/drive.hpp"

#define TRACK_WDITH 11.5;

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
    extern Drive chassis;

    extern pros::Rotation enc_left;
    extern pros::Rotation enc_right;
    extern pros::Rotation enc_theta;
}