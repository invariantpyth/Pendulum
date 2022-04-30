#include <iostream>
#include <opencv2/highgui.hpp>
#include "Pendulum.h"
//#include<chrono>
//#include<thread>
#define FPS 60
#define WIDTH 1080
#define HEIGHT 1920



int main() {
    Pendulum pend
    {
        PI / 2,
        PI / 5,
        0,
        0,
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

    cv::VideoWriter video("pendulum_test.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'),
                          FPS, cv::Size(WIDTH, HEIGHT));
    int frameAmount = FPS * 1 * 60;
    cv::Mat videoFrame = cv::Mat::zeros(HEIGHT, WIDTH, CV_8UC3);
    for (int i = 0; i < frameAmount; i++)
    {
        videoFrame = frame.draw();
        video << videoFrame;
        if ((i * 100 / frameAmount) > ((i - 1) * 100 / frameAmount)){
            std::cout << i * 100 / frameAmount << "% of the video is processed\n";
        }
//        cv::imwrite("test.png", videoFrame);
//        cv::imshow("Pendulum", videoFrame);
//        cv::moveWindow("Pendulum" , 0, 200 );
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));

    }
    std::cout << "100% of the video is processed\n";
    video.release();
    return 0;
}
