#ifndef PRG1_LABO_ROBOT_TERRAIN_H
#define PRG1_LABO_ROBOT_TERRAIN_H

#include <vector>

#include "robot.h"

// TODO: Ajouter constante pour largeur et hauteur
class Terrain {
public:
   Terrain(int largeur = 10, int hauteur = 10);

   void afficher() const;

private:
   int largeur;
   int hauteur;

   std::vector<Robot> robots;
};


#endif //PRG1_LABO_ROBOT_TERRAIN_H
