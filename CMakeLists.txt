cmake_minimum_required(VERSION 3.22)
project(pendulum)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 14)

add_executable(pendulum main.cpp)
target_link_libraries( pendulum ${OpenCV_LIBS} )
