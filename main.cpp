#include <iostream>
//#include <opencv2/core.hpp>
#include "Pendulum.h"



int main() {
    Pendulum pend
    {
        PI / 2,
        PI / 5,
        1.0,
        1.0,
        0.5,
        0.5,
        0.0

    };
    for (int i = 0; i < 1000; i++)
    {
        std::cout << "theta1: " << pend.getTheta1() << "\n";
        std::cout << "theta2: " << pend.getTheta2() << "\n";
        std::cout << "p1: " << pend.getP1() << "\n";
        std::cout << "p2: " << pend.getP2() << "\n\n";
        pend.iterate();

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
