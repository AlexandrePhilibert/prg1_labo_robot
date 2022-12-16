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

#include "robot.h"

// TODO: Ajouter constante pour largeur et hauteur
class Terrain {
public:
   Terrain(int largeur = 10, int hauteur = 10, const std::vector<Robot>& robots = std::vector<Robot>());

   void afficher() const;
   bool contient(const Position& position) const;
   void prochainTour();


private:
   int largeur;
   int hauteur;

   void afficherCase(const Position& position) const;
   void combatsRobots();
   void deplacerRobots();


   std::vector<Robot> robots;
};


#endif //PRG1_LABO_ROBOT_TERRAIN_H
