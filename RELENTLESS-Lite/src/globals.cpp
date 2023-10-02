#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_fl(20, MOTOR_GEARSET_6, true);
    pros::Motor motor_ml(17, MOTOR_GEARSET_6, true);
    pros::Motor motor_bl(8, MOTOR_GEARSET_6, false);
    pros::Motor motor_fr(12, MOTOR_GEARSET_6, false);
    pros::Motor motor_mr(1, MOTOR_GEARSET_6, false);
    pros::Motor motor_br(2, MOTOR_GEARSET_6, true);

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
        {-20, -17, 8},
        {12, 1, -4},
        2,
        2.75,
        600,
        0.75
    );

    // pros::Motor cata_left(15, MOTOR_GEAR_100, true);
    // pros::Motor cata_right(13, MOTOR_GEAR_100, false);

    
    // Electronics / Pneumatics / Sensors
    // pros::Rotation enc_left();
    // pros::Rotation enc_right();
    // pros::Rotation enc_theta();

    // Misc

}