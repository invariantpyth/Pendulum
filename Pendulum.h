//
// Created by maxim on 22.04.22.
//

#ifndef PENDULUM_PENDULUM_H
#define PENDULUM_PENDULUM_H
#define PATH_LENGTH 100
#define dTIME 0.0000001
#define g 9.81

class Pendulum{
private:
    Pendulum(double theta1, double theta2, double p1, double p2, double mass, double length, double time);

    double theta1,
           theta2,
           p1,
           p2,
           time,
           mass,
           length;
    double path[PATH_LENGTH][2];
    int counter;
public:
    Pendulum(double theta1, double theta2, double p1, double p2, double mass, double length);

    Pendulum();

    double f1();
    double f2();
    void get_cartesian1(double *coord1);
    void get_cartesian2(double *coord2);
    Pendulum corrector1();
    Pendulum corrector2();
    void iterate();



};
class Frame;
#endif //PENDULUM_PENDULUM_H
