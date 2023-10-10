#include "main.h"
#include "wings.h"

using namespace globals;

Wings::Wings() {
    close();
};

void Wings::open() {
    left_wing_piston.set_value(1);
    right_wing_piston.set_value(1);
};

void Wings::close() {
    left_wing_piston.set_value(0);
    right_wing_piston.set_value(0);
};

void Wings::toggleLeft(int value) {
    left_wing_piston.set_value(value);   
};

void Wings::toggleRight(int value) {
    right_wing_piston.set_value(value);
};

void Wings::openFor(double duration) {
    open();
    pros::delay(duration * 1000);
    close();
};



