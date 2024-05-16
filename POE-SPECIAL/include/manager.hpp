#include "main.h"
#include <string>

#define STD_DELAY_MS 10 // match the rotation sensor
#define LOOP while(true)

#define CONVERSION_FACTOR_X 0.000140488901377 // Unit: inches / centidegrees
#define CONVERSION_FACTOR_Y 0.0000428867040496
#define CONVERSION_FACTOR_Z 0.000112429029175

#define KP_X 19.1
#define KP_Y 19.1
#define KP_Z 19.1

extern Timer timer;

namespace manager {
    //control
    void home();
    void writeLetter(char letter);
    void writeSentence(std::string str);
    void manualControl();

    //misc
    void telemetry();

    // managers
    void x_axis_mgr();
    void y_axis_mgr();
    void z_axis_mgr();
    void telemetry_mgr();

    double getPosX_inches();
    double getPosY_inches();
    double getPosZ_inches();

    void xGoTo(double sp, double timeoutMS);
    void yGoTo(double sp, double timeoutMS);
    void zGoTo(double sp, double timeoutMS);

    void writeA();
    void writeB();
    void writeC();
    void writeD();
    void writeE();
    void writeF();
    void writeG();
    void writeH();
    void writeI();
    void writeJ();
    void writeK();
    void writeL();
    void writeM();
    void writeN();
    void writeO();
    void writeP();
    void writeQ();
    void writeR();
    void writeS();
    void writeT();
    void writeU();
    void writev();
    void writeW();
    void writeX();
    void writeY();
    void writeZ();

}