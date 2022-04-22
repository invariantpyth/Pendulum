//
// Created by maxim on 22.04.22.
//
#include <math.h>
#include "Pendulum.h"


Pendulum::Pendulum(double theta1, double theta2, double p1, double p2, double mass, double length) {

}

double Pendulum::f1() {
    double f = ((6 / (mass * length * length)) *
                (2 * p1 - 3 * cos(theta1 - theta2) * p2) /
                (16 - 9 * cos(theta1 - theta2) * cos(theta1 - theta2)));
    return f;
}

double Pendulum::f2() {
    double f = ((6 / (mass * length * length)) *
                (8 * p2 - 3 * cos(theta1 - theta2) * p1) /
                (16 - 9 * cos(theta1 - theta2) * cos(theta1 - theta2)));
    return f;
}

void Pendulum::get_cartesian1(double *coord1) {
    coord1[0] = length * sin(theta1) / (2 * length);
    coord1[1] = length * cos(theta1) / (2 * length);
}

void Pendulum::get_cartesian2(double *coord2) {
    coord2[0] = length * (sin(theta1) + sin(theta2)) / (2.0 * length);
    coord2[1] = length * (cos(theta1) + cos(theta2)) / (2.0 * length);
}

void Pendulum::corrector1() {

}

