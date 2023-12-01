/*
    Wings.cpp
    Controls all of the logic for the wings in autonomous and driver control
*/

#include "main.h"
#include "Wings.h"

using namespace globals;

Wings::Wings() {
    /*
        The state of each wing needs to be manually tracked due to privitization errors.
        We cannot read the values of the pistons directly, in order to work around this we need to track the state manually.
    */
    left_wing_state = 0;
    right_wing_state = 0;
    close(); // Force close the wings for safety
};

void Wings::open() {
    left_wing_piston.set_value(1);
    left_wing_state = 1;
    right_wing_piston.set_value(1);
    right_wing_state = 1;
};

void Wings::close() {
    left_wing_piston.set_value(0);
    left_wing_state = 0;
    right_wing_piston.set_value(0);
    right_wing_state = 0;
};

void Wings::toggleLeft(int value) {
    left_wing_piston.set_value(value);  
    left_wing_state = value; 
};

void Wings::toggleRight(int value) {
    right_wing_piston.set_value(value);
    right_wing_state = value;
};

/*
    Opens the wings for a certain amount of time
    openFor(double duration) -> duration in seconds, converted to milliseconds
*/

void Wings::openFor(double duration) {
    open();
    pros::delay(duration * 1000);
    close();
};

/*
    returns int
    0 -> Both wings closed
    1 -> Right wing open
    2 -> Left wing open
    3 -> Both wings open
*/

int Wings::getState() {
    if (left_wing_state == 0 && right_wing_state == 0) {
        return 0;
    } else if (left_wing_state == 0 && right_wing_state == 1) {
        return 1;
    } else if (left_wing_state == 1 && right_wing_state == 0) {
        return 2;
    } else if (left_wing_state == 1 && right_wing_state == 1) {
        return 3;
    } else {
        return 0;
    }
}