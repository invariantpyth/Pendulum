//
// Created by maxim on 22.04.22.
//
#include <cmath>
#include "Pendulum.h"


Pendulum::Pendulum(double theta1, double theta2, double p1, double p2, double mass, double length, double time=0)
{
    Pendulum::theta1 = theta1;
    Pendulum::theta2 = theta2;
    Pendulum::p1 = p1;
    Pendulum::p2 = p2;
    Pendulum::mass = mass;
    Pendulum::length = length;
    Pendulum::time = time;
    Pendulum::counter = 0;
    for (auto & index : Pendulum::path)
    {
        index[0] = 0;
        index[1] = 0;
    }

}

double Pendulum::f1() {
    double diff_equation = ((6 / (mass * length * length)) *
                (2 * p1 - 3 * cos(theta1 - theta2) * p2) /
                (16 - 9 * cos(theta1 - theta2) * cos(theta1 - theta2)));
    return diff_equation;
}

double Pendulum::f2() {
    double diff_equation = ((6 / (mass * length * length)) *
                (8 * p2 - 3 * cos(theta1 - theta2) * p1) /
                (16 - 9 * cos(theta1 - theta2) * cos(theta1 - theta2)));
    return diff_equation;
}

void Pendulum::getCartesian1(double *coord1)
{
    coord1[0] = length * sin(theta1) / (2 * length);
    coord1[1] = length * cos(theta1) / (2 * length);
}

void Pendulum::getCartesian2(double *coord2)
{
    coord2[0] = length * (sin(theta1) + sin(theta2)) / (2.0 * length);
    coord2[1] = length * (cos(theta1) + cos(theta2)) / (2.0 * length);
}

Pendulum Pendulum::corrector1()
{
    double dTheta = this->f1();
     Pendulum p{(theta1 + dTIME * dTheta),
               theta2,
               p1,
               p2,
               mass,
               length,
               time};
    return p;
}

Pendulum Pendulum::corrector2()
{
    double dTheta = this->f2();
    Pendulum p{theta1,
            (theta2 + dTIME * dTheta),
               p1,
               p2,
               mass,
               length,
               time
              };
    return p;
}

void Pendulum::iterate() {
    Pendulum::theta1 = (theta1 +  dTIME * (this->f1() + (*this).corrector1().f1()) / 2.0);
    Pendulum::theta2 = (theta2 +  dTIME * (this->f2() + (*this).corrector2().f2()) / 2.0);
    double dp1 = (-(mass * length * length / 2.0) *
                 (this->f1() * this->f2() * sin(theta1 - theta2) +
                  3.0 * g * sin(theta1) / length)) * dTIME;
    double dp2 = (-(mass * length * length/ 2.0) *
                  (-this->f1() * this->f2() * sin(theta1 - theta2) +
                   g * sin(theta2) / length)) * dTIME;


    Pendulum::p1 += dp1;
    Pendulum::p2 += dp2;

    Pendulum::time += dTIME;
    Pendulum::counter = (counter + 1) % PATH_LENGTH;
    double coord[2];
    getCartesian2(coord);
    Pendulum::path[counter][0] = coord[0];
    Pendulum::path[counter][1] = coord[1];
}

double Pendulum::getTheta1() const {
    return theta1;
}

double Pendulum::getTheta2() const {
    return theta2;
}

double Pendulum::getP1() const {
    return p1;
}

double Pendulum::getP2() const {
    return p2;
}



