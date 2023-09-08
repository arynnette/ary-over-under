#include "main.h"
#include "okapi/api.hpp"
#include "lemlib/api.hpp"

namespace globals {
    extern std::shared_ptr<okapi::Controller> controller;

    extern okapi::Motor motor_fl;
    extern okapi::Motor motor_ml;
    extern okapi::Motor motor_bl;
    extern okapi::Motor motor_fr;
    extern okapi::Motor motor_mr;
    extern okapi::Motor motor_br;

    extern std::shared_ptr<okapi::MotorGroup> leftDrive;
    extern std::shared_ptr<okapi::MotorGroup> rightDrive;

    extern std::shared_ptr<okapi::ChassisController> chassis;
}