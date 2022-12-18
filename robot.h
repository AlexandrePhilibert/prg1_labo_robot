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

class Robot {
public :
   Robot(const Position& position = Position(0, 0));

   /**
    * @throws NIL
    * @return l'id du robot
    */
   int getId() const;
   const Position& getPosition() const;

   void deplacer(Direction direction);

   static int prochainId;

private:
   int id;
   Position position;
};

#endif //PRG1_LABO_ROBOT_ROBOT_H
