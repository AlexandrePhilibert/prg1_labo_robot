// -----------------------------------------------------------------------------------------------
// Fichier        : position.h
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-20
// But            : Représentation d'une position sur un plan x et y.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_ROBOT_POSITION_H
#define PRG1_LABO_ROBOT_POSITION_H

#include <vector>

enum class Direction { HAUT, DROITE, BAS, GAUCHE };

class Position {
public:
   explicit Position(int x = 0, int y = 0);

   int getX() const;
   int getY() const;

   /**
    * Génère une position aléatoire entre 0 et la position maximum passée en paramètre.
    *
    * @param xMax   La coordonnée x maximum
    * @param yMax   La coordonnée y maximum
    * @throws NIL
    * @return       La position créer aléatoirement
    */
   static Position random(int xMax, int yMax);

   /**
    * Remplis de l'itérateur de début jusqu'à l'itérateur de fin un vecteur avec des positions uniques.
    *
    * @param debut  L'itérateur de début du vecteur
    * @param fin    L'itérateur de fin du vecteur
    * @param xMax   La position x maximum que prendra la position
    * @param yMax   La position y maximum que prendra la position
    * @throws NIL
    * @return void
    */
   static void unique(std::vector<Position>::iterator debut, std::vector<Position>::iterator fin, int xMax, int yMax);

   bool operator==(const Position& position) const;
   Position operator+(Direction direction) const;

private:
   int x;
   int y;
};

Position operator+(Direction direction, const Position& position);
Direction& operator++(Direction& direction);

#endif //PRG1_LABO_ROBOT_POSITION_H
