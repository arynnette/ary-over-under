#ifndef _Kalman_h_
#define _Kalman_h_

class Kalman {
public:
    Kalman();

    double getAngle(double newAngle, double newRate, double dt);

    void setAngle(double angle); 
    double getRate();

    void setQangle(double Q_angle);
    
    void setQbias(double Q_bias);
    void setRmeasure(double R_measure);

    double getQangle();
    double getQbias();
    double getRmeasure();

private:
    // Kfilter vars
    double Q_angle;
    double Q_bias;
    double R_measure;

    double angle;
    double bias;
    double rate;

    double P[2][2];
};

#endif