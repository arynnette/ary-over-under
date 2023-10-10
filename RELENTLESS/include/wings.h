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
    
    private:
        std::uint8_t wingsopen;
};

#endif