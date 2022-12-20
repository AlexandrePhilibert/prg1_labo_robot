// -----------------------------------------------------------------------------------------------
// Fichier        : robot.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-20
// But            : Représentation d'un robot possédant un identifiant ainsi qu'une position
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_ROBOT_ROBOT_H
#define PRG1_LABO_ROBOT_ROBOT_H

#include "position.h"

class Robot {
public:
   explicit Robot(const Position& position = Position(0, 0));

   int getId() const;
   const Position& getPosition() const;

   /**
    *  Déplace le robot dans une direction donnée
    *
    * @param direction Direction dans laquelle le robot va réaliser son déplacement.
    * @throws NIL
    * @return void
    */
   void deplacer(Direction direction);

   /**
    * Prochain identifiant qui sera assigné à un robot.
    */
   static int prochainId;

   bool operator==(const Robot& robot) const;
   bool operator!=(const Robot& robot) const;

private:
   int id;
   Position position;
};

#endif //PRG1_LABO_ROBOT_ROBOT_H
