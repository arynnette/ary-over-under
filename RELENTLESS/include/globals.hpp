#include "main.h"
#include "okapi/api.hpp"
#include "lemlib/api.hpp"

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

    extern lemlib::Drivetrain_t drivetrain;
}