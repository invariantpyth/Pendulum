//
// Created by maxim on 22.04.22.
//

#ifndef PENDULUM_PENDULUM_H
#define PENDULUM_PENDULUM_H
#define PATH_LENGTH 100
#include <vector>
class Pendulum{
private:
    double theta1,
           theta2,
           p1,
           p2,
           time = 0,
           m,
           l;
    int path[PATH_LENGTH];
public:
    Pendulum(double theta1, double theta2, double p1, double p2, double m, double l);
    double f1();
    double f2();
    std::vector<double> get_cartesian1();
    std::vector<double> get_cartesian2();


};
class Frame;
#endif //PENDULUM_PENDULUM_H
