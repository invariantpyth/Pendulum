//
// Created by maxim on 22.04.22.
//

#ifndef PENDULUM_PENDULUM_H
#define PENDULUM_PENDULUM_H
#define PATH_LENGTH 100
#define dTIME 1.0 / 60
#define g 9.81
#define PI 3.141592653589793238462643383279502884197169399375105820974944


class Pendulum{

private:

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

    Pendulum(double theta1, double theta2, double p1, double p2, double mass, double length, double time);

    double f1();
    double f2();
    void getCartesian1(double *coord1);
    void getCartesian2(double *coord2);
    Pendulum corrector1();
    Pendulum corrector2();
    void iterate();

    double getTheta1() const;
    double getTheta2() const;
    double getP1() const;
    double getP2() const;


};
class Frame{
private:
    int width;
    int height;
    int backgroundColor[3];
    int middleColor[3];
    int linkColor[3];
    int pathColor[3];
    Pendulum pend = Pendulum(0, 0, 0, 0, 1, 1, 0);

public:

    Frame(int _width, int _height, const int *_backgroundColor, const int *_middleColor, const int *_linkColor, const int *_pathColor, Pendulum _pend);
    void update();
    void transformCoordinates(double *coord);
    cv::Mat draw();
};
#endif //PENDULUM_PENDULUM_H
