cmake_minimum_required(VERSION 3.23)
project(prg1_labo_robot)

set(CMAKE_CXX_STANDARD 20)

add_executable(prg1_labo_robot main.cpp robot.h robot.cpp terrain.cpp terrain.h saisie.h saisie.cpp annexe.h annexe.cpp position.h position.cpp)
