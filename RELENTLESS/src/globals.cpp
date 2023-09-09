#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_tlf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_blb(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_trf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_brf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_brb(4, MOTOR_GEARSET_06, true);

    pros::Motor_Group left_drive({ motor_fl, motor_ml, motor_bl });
    pros::Motor_Group right_drive({ motor_fr, motor_mr, motor_br });

    lemlib::Drivetrain_t chassis_odom {
        &left_drive,
        &right_drive,
        11.5,
        2.75, 
        450
    };

    Drive chassis(
        {-4,-4,-4,-4},
        {1,1,1,1},
        16,
        3.125,
        600,
        0.6
    ); 

    
    // Electronics / Pneumatics / Sensors
    // pros::Rotation enc_left();
    // pros::Rotation enc_right();
    // pros::Rotation enc_theta();

    // Misc

}