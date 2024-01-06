#include "main.h"
#include "globals.hpp"

namespace globals {
    pros::Motor left_front(1, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor left_middle(2, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor left_back(3, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor right_front(4, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor right_middle(5, pros::E_MOTOR_GEARSET_06, false);
    pros::Motor right_back(6, pros::E_MOTOR_GEARSET_06, false);
    
    pros::Motor_Group left_drive({ left_front, left_middle, left_back });
    pros::Motor_Group right_drive({ right_front, right_middle, right_back });
    
    pros::Imu imu(7);
}