#pragma once

#include "main.h"

namespace globals {
    extern pros::Motor left_front;
    extern pros::Motor left_middle;
    extern pros::Motor left_back;
    extern pros::Motor right_front;
    extern pros::Motor right_middle;
    extern pros::Motor right_back;
    
    extern pros::Motor_Group left_drive;
    extern pros::Motor_Group right_drive;
    
    extern pros::Imu imu;
}