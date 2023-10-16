#pragma once
#ifndef _Wings_h
#define _Wings_h_

#include "main.h"

class Wings {
    public:
        Wings();
        void open();
        void close();
        void toggleLeft(int value);
        void toggleRight(int value);
        void openFor(double duration);
        int getState();
    
    private:
        int left_wing_state;
        int right_wing_state;
};

#endif