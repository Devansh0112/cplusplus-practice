cmake_minimum_required(VERSION 3.10)
project(MyBoostProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "g++")

# Include Boost headers
include_directories("C:/Program Files/Boost/boost_1_82_0/boost_1_82_0")

add_executable(boost-prac boost-prac.cpp)
