#define PORT_MOTOR_X_ONE 2
#define PORT_MOTOR_X_TWO 10
#define PORT_MOTOR_Y 9
#define PORT_MOTOR_Z_ONE 20
#define PORT_MOTOR_Z_TWO 8


#define PORT_ENC_X 3
#define PORT_ENC_Y 12
#define PORT_ENC_Z 6

#include "main.h"

namespace config {
    extern pros::Controller master;

    extern pros::Motor mtr_x_ax_1;
    extern pros::Motor mtr_y_ax;
    extern pros::Motor mtr_z_ax;
    extern pros::Motor mtr_z_ax_2;
    extern pros::Motor mtr_x_ax_2;

    extern pros::Rotation enc_x_ax;
    extern pros::Rotation enc_y_ax;
    extern pros::Rotation enc_z_ax;
}