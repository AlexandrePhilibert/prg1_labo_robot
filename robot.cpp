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

#include "robot.h"
#include "terrain.h"
#include "position.h"

using namespace std;

int Robot::prochainId = 0;

Robot::Robot(const Position& position) : position(position) {
   id = Robot::prochainId;
   prochainId++;
}

int Robot::getId() const {
   return id;
}

const Position& Robot::getPosition() const {
   return this->position;
}

void Robot::deplacer(Direction direction) {
   // TODO: Utiliser +=
   this->position = position + direction;
}

bool Robot::operator==(const Robot &robot) const {
   return this->id == robot.id;
}


bool Robot::operator!=(const Robot &robot) const {
   return !(*this == robot);
}