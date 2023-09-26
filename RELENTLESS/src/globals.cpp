#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_tlf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_blb(3, MOTOR_GEARSET_06, true);
    pros::Motor motor_trf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(5, MOTOR_GEARSET_06, true);
    pros::Motor motor_brf(4, MOTOR_GEARSET_06, true);
    pros::Motor motor_brb(4, MOTOR_GEARSET_06, true);

    pros::Motor_Group left_drive({ motor_tlf, motor_tlb, motor_blf, motor_blb });
    pros::Motor_Group right_drive({ motor_trf, motor_trb, motor_brf, motor_brb });

    // Electronics / Pneumatics / Sensors
    pros::Rotation rot_vert(0);
    pros::Rotation rot_horiz(1);
    // pros::Rotation enc_right();
    // pros::Rotation enc_theta();

    lemlib::Drivetrain_t chassis_odom {
        &left_drive,
        &right_drive,
        TRACK_WIDTH,
        WHEEL_SIZE, 
        DRIVE_RPM
    };

    lemlib::TrackingWheel vert_tracking_wheel(&rot_vert, WHEEL_SIZE, PLACEHOLDER_TC_OFFSET, 1); // subject to change: p3 -> tracking center offset
    lemlib::TrackingWheel hroiz_tracking_wheel(&rot_horiz, WHEEL_SIZE, PLACEHOLDER_TC_OFFSET, 1); 

    Drive chassis(
        {-4,-4,-4,-4},
        {1,1,1,1},
        16,
        WHEEL_SIZE,
        600,
        DRIVE_RATIO
    ); 

    // Misc

}