// -----------------------------------------------------------------------------------------------
// Fichier        : position.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-20
// But            : Représentation d'une position sur un plan x et y.
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
   return x;
}

int Position::getY() const {
   return y;
}

void Position::unique(vector<Position>::iterator debut, vector<Position>::iterator fin, int xMax, int yMax) {
   for (vector<Position>::iterator& it = debut; debut != fin; ++it) {
      Position position = Position::random(xMax, yMax);

      if (find(debut, fin, position) == fin) {
         *it = position;
      }
   }
}

Position Position::random(int xMax, int yMax) {
   return Position(::random(0, xMax), ::random(0, yMax));
}

// -----------------------------------------------------------------------------------------------
// region Opérateurs
// -----------------------------------------------------------------------------------------------

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

Position operator+(Direction direction, const Position& position) {
   return position + direction;
}


bool Position::operator==(const Position &position) const {
   return position.x == x && position.y == y;
}

Direction& operator++(Direction& direction) {
   direction = (Direction) ((int) direction + 1);
   return direction;
}

// -----------------------------------------------------------------------------------------------
// endregion Opérateurs
// -----------------------------------------------------------------------------------------------