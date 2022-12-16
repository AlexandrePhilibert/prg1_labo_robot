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

#ifndef PRG1_LABO_ROBOT_ROBOT_H
#define PRG1_LABO_ROBOT_ROBOT_H

#include <vector>

#include "position.h"

class Robot{
public :
   Robot(int numero, const Position& position = Position(0, 0));

   int getNumero() const;
   Position getPosition() const;

   void setPosition(const Position& position);

private:
   int numero;
   Position position;
};

#endif //PRG1_LABO_ROBOT_ROBOT_H
