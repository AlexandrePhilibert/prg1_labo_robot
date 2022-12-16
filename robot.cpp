// -----------------------------------------------------------------------------------------------
// Fichier        : robot.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-11-22
// But            :
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <vector>

#include "robot.h"

using namespace std;

Robot::Robot(int numero, const Position& position) : numero(numero), position(position) {}

int Robot::getNumero() const {
   return numero;
}

Position Robot::getPosition() const {
   return this->position;
}

void Robot::setPosition(const Position& position) {
   this->position = position;
}
