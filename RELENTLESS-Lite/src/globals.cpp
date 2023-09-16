#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_fl(8, MOTOR_GEARSET_6, true);
    pros::Motor motor_ml(17, MOTOR_GEARSET_6, true);
    pros::Motor motor_bl(7, MOTOR_GEARSET_6, false);
    pros::Motor motor_fr(11, MOTOR_GEARSET_6, false);
    pros::Motor motor_mr(20, MOTOR_GEARSET_6, false);
    pros::Motor motor_br(4, MOTOR_GEARSET_6, true);

    pros::Motor_Group left_drive({ motor_fl, motor_ml, motor_bl });
    pros::Motor_Group right_drive({ motor_fr, motor_mr, motor_br });
    
    /*
        Two seperate drivetrains, chassis 
    */
    lemlib::Drivetrain_t chassis_odom {
        &left_drive,
        &right_drive,
        11.5,
        2.75, 
        450
    };

    Drive chassis(
        {-8, -17, 7},
        {11, 20, -4},
        2,
        3.25,
        600,
        0.6
    );

    
    // Electronics / Pneumatics / Sensors
    // pros::Rotation enc_left();
    // pros::Rotation enc_right();
    // pros::Rotation enc_theta();

    // Misc

}