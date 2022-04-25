#include <iostream>
#include <opencv2/highgui.hpp>
#include "Pendulum.h"
#include<chrono>
#include<thread>
#define FPS 60
#define WIDTH 1080
#define HEIGHT 1920



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
    int backgroundColor[3] = {60, 51, 54};
    int linkColor[3] = {256, 256, 256};
    int middleColor[3] = {2, 159, 254};
    int pathColor[3] = {55, 102, 219};

    Frame frame
    {WIDTH,
     HEIGHT,
     backgroundColor,
     middleColor,
     linkColor,
     pathColor,
     pend
    };

    cv::VideoWriter video("pendulum_test.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
                          FPS, cv::Size(WIDTH, HEIGHT));
    int frameAmount = FPS * 4;
    for (auto i = 0; i < frameAmount; i++)
    {
        frame.update();
        video << frame.draw();
        cv::imshow("Pendulum", frame.draw());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));

    }
    video.release();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
