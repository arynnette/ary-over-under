#include "main.h"
#include "config.hpp"

namespace config {
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    pros::Motor mtr_x_ax_1(PORT_MOTOR_X_ONE);
    pros::Motor mtr_y_ax(PORT_MOTOR_Y);
    pros::Motor mtr_z_ax(PORT_MOTOR_Z_ONE);
    pros::Motor mtr_z_ax_2(PORT_MOTOR_Z_TWO);
    pros::Motor mtr_x_ax_2(PORT_MOTOR_X_TWO);

    pros::Rotation enc_x_ax(PORT_ENC_X);
    pros::Rotation enc_y_ax(PORT_ENC_Y);
    pros::Rotation enc_z_ax(PORT_ENC_Z);
}