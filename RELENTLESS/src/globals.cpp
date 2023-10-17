#include "globals.hpp"

using namespace ary;
namespace globals {
    // Chassis
    pros::Controller master(CONTROLLER_MASTER);

    pros::Motor motor_tlf(12, MOTOR_GEARSET_06, false);
    pros::Motor motor_blb(6, MOTOR_GEARSET_06, true);
    pros::Motor motor_blf(2, MOTOR_GEARSET_06, true);
    pros::Motor motor_tlb(5, MOTOR_GEARSET_06, false);
    pros::Motor motor_trf(16, MOTOR_GEARSET_06, true);
    pros::Motor motor_trb(3, MOTOR_GEARSET_06, true);
    pros::Motor motor_brf(1, MOTOR_GEARSET_06, false);
    pros::Motor motor_brb(4, MOTOR_GEARSET_06, false);

    pros::Motor_Group left_drive({ motor_tlf, motor_tlb, motor_blf, motor_blb });
    pros::Motor_Group right_drive({ motor_trf, motor_trb, motor_brf, motor_brb });

    // Electronics / Pneumatics / Sensors
    pros::Rotation rot_vert(0);
    pros::Rotation rot_horiz(1);

    pros::ADIDigitalOut pto_piston('A');

    pros::ADIDigitalOut left_wing_piston('C');
    pros::ADIDigitalOut right_wing_piston('B');

    pros::ADIDigitalOut intake_piston('D');

    pros::ADIDigitalOut doinker_piston('E');

    Wings wings;

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
        {-2, -6, 12, 5},
        {-16, 1, 4, -3},
        16,
        WHEEL_SIZE,
        600,
        DRIVE_RATIO
    ); 

    pros::Motor& cata_left = chassis.left_motors[3];
    pros::Motor& cata_right = chassis.right_motors[3];
}