// -----------------------------------------------------------------------------------------------
// Fichier        : position.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-12
// But            : Représentation d'une position sur un plan x y.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include "position.h"
#include "annexe.h"

using namespace std;

Position::Position(int x, int y): x(x), y(y) {}

int Position::getX() const {
   return this->x;
}

int Position::getY() const {
   return this->y;
}

Position Position::random(int xMax, int yMax) {
   return Position(::random(0, xMax), ::random(0, yMax));
}

Position Position::operator+(Direction direction) const {
   int x = this->x;
   int y = this->y;

   switch (direction) {
      case Direction::HAUT:
         y--;
         break;
      case Direction::DROITE:
         x++;
         break;
      case Direction::BAS:
         y++;
         break;
      case Direction::GAUCHE:
         x--;
         break;
   }

   return Position(x, y);
}

bool Position::operator==(const Position &position) const {
   return position.getX() == x && position.getY() == y;
}
