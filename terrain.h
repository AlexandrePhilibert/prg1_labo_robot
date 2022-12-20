// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-11-22
// But            : Classe représentant un terrain contenant des robots effectuant des combats
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_ROBOT_TERRAIN_H
#define PRG1_LABO_ROBOT_TERRAIN_H

#include <vector>
#include <sstream>
#include <ostream>

#include "robot.h"

class Terrain {
   friend std::ostream& operator<<(std::ostream& os, const Terrain& terrain);
public:
   Terrain(std::vector<Robot>& robots, int largeur = 10, int hauteur = 10);

   void afficherEvenements() const;
   void prochainTour();

private:
   const int largeur;
   const int hauteur;

   /**
    * Les événements sont des actions qui ont été réalisées sur le terrain, par. ex un robot tuant un autre robot
    */
   std::stringstream evenements;

   void afficherCase(const Position& position) const;

   /**
    * @param position La position à laquelle un robot est cherchés
    * @return Un itérateur constant contenant un robot si un robot a été trouvé à la position donnée,
    * sinon retourne l'itérateur de fin du vecteur de robots
    * @throws NIL
    */
   std::vector<Robot>::const_iterator robotEnPositon(const Position& position) const;

   std::vector<Robot>& robots;

   static const char BORD_HORIZONTAL;
   static const char BORD_VERTICAL;
};

std::ostream& operator<<(std::ostream& os, const Terrain& terrain);

#endif //PRG1_LABO_ROBOT_TERRAIN_H
