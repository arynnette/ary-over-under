#include "main.h"
#include "globals.hpp"
#include "superstructure.hpp"
#include "wings.h"

using namespace globals;

Wings::Wings() {
    close();
    wingsopen = 0;
};

void Wings::open() {
    left_wing_piston.set_value(1);
    right_wing_piston.set_value(1);
}

void Wings::close() {
    left_wing_piston.set_value(0);
    right_wing_piston.set_value(0);
}

void Wings::toggleLeft(int value) {
    left_wing_piston.set_value(value);   
}

void Wings::toggleRight(int value) {
    right_wing_piston.set_value(value);
}

void Wings::openFor(double duration) {
    open();
    pros::delay(duration * 1000);
    close();
}


/*
    0 -> Both wings closed
    1 -> Only right wing opened
    2 -> Only left wing opened
    3-> Both wings open
*/
std::uint8_t getState() {
    // int stateLeft = left_wing_pisto;
    // int stateRight = right_wing_piston.get_value();
    return 0;
}



