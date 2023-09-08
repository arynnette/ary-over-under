#include "globals.hpp"

namespace globals {
    std::shared_ptr<okapi::Controller> controller(new Controller(ControllerId::master));

    // Chassis
    okapi::Motor motor_fl(1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
    okapi::Motor motor_ml(2, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
    okapi::Motor motor_bl(3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
    okapi::Motor motor_fr(4, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
    okapi::Motor motor_mr(5, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
    okapi::Motor motor_br(6, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

    std::shared_ptr<okapi::MotorGroup> left_drive(new MotorGroup({motor_fl, motor_ml, motor_bl}));
    std::shared_ptr<okapi::MotorGroup> right_drive(new MotorGroup({motor_fr, motor_mr, motor_br}));

    std::shared_ptr<okapi::ChassisController> chassis =
        ChassisControllerBuilder()
        .withMotors(left_drive, right_drive)
        .withDimensions({AbstractMotor::gearset::blue, 1.5}, {{3.25_in, 28_cm}, 300 * 1.5})
        .withGains(
            {0.45, 0, 5},
            {11, 0, 20},
            {0.001, 0, 0.0001}
        )
        .build();

    // Electronics / Pneumatics / Sensors

    // Misc

}