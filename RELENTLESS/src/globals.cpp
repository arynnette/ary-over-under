#include "globals.hpp"

namespace globals {
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_fl(4, MOTOR_GEARSET_6, true);
    pros::Motor motor_ml(4, MOTOR_GEARSET_6, true);
    pros::Motor motor_bl(4, MOTOR_GEARSET_6, true);
    pros::Motor motor_fr(4, MOTOR_GEARSET_6, false);
    pros::Motor motor_mr(4, MOTOR_GEARSET_6, false);
    pros::Motor motor_br(4, MOTOR_GEARSET_6, false);

    pros::Motor_Group left_drive({ motor_fl, motor_ml, motor_bl });
    pros::Motor_Group right_drive({ motor_fr, motor_mr, motor_br });

    

    // Chassis

    // Electronics / Pneumatics / Sensors

    // Misc

}