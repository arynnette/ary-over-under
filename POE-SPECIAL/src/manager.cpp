#include "main.h"
#include "manager.hpp"
#include "config.hpp"
#include "pros/misc.h"
#include "Timer.h"

using namespace config;

Timer timer;

namespace manager {
    void manualControl() {
        if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            config::mtr_y_ax.move_voltage(4000);
        } else if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            config::mtr_y_ax.move_voltage(-4000);
        } else {
            config::mtr_y_ax.move_voltage(0);
        }

        if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            config::mtr_z_ax.move_voltage(4000);
            config::mtr_z_ax_2.move_voltage(-4000);
        } else if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            config::mtr_z_ax.move_voltage(-4000);
            config::mtr_z_ax_2.move_voltage(4000);
        } else {
            config::mtr_z_ax.move_voltage(0);
            config::mtr_z_ax_2.move_voltage(0);
        }

        if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            config::mtr_x_ax_1.move_voltage(4000);
            config::mtr_x_ax_2.move_voltage(4000);
        } else if (config::master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            config::mtr_x_ax_1.move_voltage(-4000);
            config::mtr_x_ax_2.move_voltage(-4000);
        } else {
            config::mtr_x_ax_1.move_voltage(0);
            config::mtr_x_ax_2.move_voltage(0);
        }

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            enc_x_ax.reset();
            enc_x_ax.reset_position();
            enc_y_ax.reset();
            enc_y_ax.reset_position();
            enc_z_ax.reset();
            enc_z_ax.reset_position();
        }

        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            xGoTo(3.75, 1500); // 
        }
    }

    void home() {

    }

    void writeLetter(char letter) {

    }

    void writeSentence(std::string str) {
        
    }

    void telemetry() {
        // pros::lcd::print(0, "x axis distance value: %.2f", getPosX_inches());
        // pros::lcd::print(1, "err: %.2f", (3.75 - getPosX_inches()));
        // pros::lcd::print(2, "x axis distance value: %.2f", getPosY_inches());
        // pros::lcd::print(3, "err: %.2f", (2.0 - getPosY_inches()));
        // pros::lcd::print(3, "x axis position value: %d", config::enc_x_ax.get_position());
        // pros::lcd::print(4, "y axis position value: %d", config::enc_y_ax.get_position());
        // pros::lcd::print(5, "z axis position value: %d", config::enc_z_ax.get_position());
    }

    void telemetry_mgr() {
        LOOP {
            telemetry();
            pros::delay(STD_DELAY_MS);
        }
    }

    double getPosX_inches() {
        return enc_x_ax.get_position() * CONVERSION_FACTOR_X;
    }

    double getPosY_inches() {
        return enc_y_ax.get_position() * CONVERSION_FACTOR_Y;
    }

    double getPosZ_inches() {
        return enc_z_ax.get_position() * CONVERSION_FACTOR_Z;
    }

    

    void xGoTo(double sp, double timeoutMS) {
        timer.reset();
        double startTime = timer.getElapsedTimeMS();
        double err = sp - getPosX_inches(); // err = setpoint - current

        while (fabs(err) > 0.3) {
            double p = KP_X * err;
            mtr_x_ax_1.move(p);
            mtr_x_ax_2.move(p);

            err = sp - getPosX_inches();

            if (timer.getElapsedTimeMS() - startTime > timeoutMS) {
                break;
            }
        }
        mtr_x_ax_1.move(0);
        mtr_x_ax_2.move(0);
        
    }

    void yGoTo(double sp, double timeoutMS) {
        timer.reset();
        double startTime = timer.getElapsedTimeMS();
        double err = sp - getPosY_inches(); // err = setpoint - current

        while (fabs(err) > 0.3) {
            double p = KP_Y * err;
            mtr_y_ax.move(-p);

            err = sp - getPosY_inches();
            pros::lcd::print(0, "y elapsed time ms: %.2f", timer.getElapsedTimeMS() - startTime);
            pros::lcd::print(1, "y err: %.2f", err);

            if (timer.getElapsedTimeMS() - startTime > timeoutMS) {
                pros::lcd::print(2, "y exited loop: {}", true);
                break;
            }
        }
        mtr_y_ax.move(0);
        pros::lcd::print(3, "y ended: {}", true);
    }

    void zGoTo(double sp) {
        double err = sp - getPosZ_inches(); // err = setpoint - current

        while (err > 0.1) {
            double p = KP_Z * err;
            mtr_z_ax.move(p);
            mtr_z_ax_2.move_voltage(p);

            err = sp - getPosZ_inches();
            pros::delay(20);
        }
        mtr_z_ax.move(0);
        mtr_z_ax_2.move_voltage(0);
    }

    void writeA() {
        zGoTo(0.5);

    }

    void x_axis_mgr() {

    }

    void y_axis_mgr() {
        
    }

    void z_axis_mgr() {
        
    }


}