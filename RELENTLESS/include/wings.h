#ifndef _wings_h_
#define _wings_h_

#include "main.h"

class Wings {
    public:
        Wings();
        void open();
        void close();
        void toggleLeft(int value);
        void toggleRight(int value);
        void openFor(double duration);
        std::uint8_t getState();
    
    private:
        std::uint8_t wingsopen;
};

#endif