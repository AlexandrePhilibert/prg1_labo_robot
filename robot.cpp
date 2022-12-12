#include "robot.h"

Robot::Robot(int numero, int x, int y) : numero(numero), x(x), y(y) {}

void Robot::setX(int x) {
   this->x = x;
}

void Robot::setY(int y) {
   this->y = y;
}

int Robot::getX()const {
   return x;
}

int Robot::getY()const {
   return y;
}

int Robot::getNumero() const {
   return numero;
}


