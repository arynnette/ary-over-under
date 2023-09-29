#ifndef _wings_h_
#define _wings_h_

#include "main.h"

class Wings {
    public:
        Wings();
        void open();
        void close();
        void openFor(double duration);
        bool getState();
    
    private:
        std::uint8_t wingsopen;
};

#endif