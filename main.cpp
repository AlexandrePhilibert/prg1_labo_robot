#include <cstdlib>
#include <limits>
#include <iostream>

#include "saisie.h"
#include "terrain.h"

using namespace std;

int main() {
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";
   const int LARGEUR_TERRAIN_MIN = 10;
   const int LARGEUR_TERRAIN_MAX = 1000;
   const int HAUTEUR_TERRAIN_MIN = 10;
   const int HAUTEUR_TERRAIN_MAX = 1000;
   const int NOMBRE_ROBOTS_MIN = 0;
   const int NOMBRE_ROBOTS_MAX = 9;

   int largeurTerrain;
   int hauteurTerrain;

   // TODO: Description du programme
   cout << "ce programme ..." << endl;

   // Saisie de la largeur du terrain
   largeurTerrain = saisie("largeur", MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);

   // Saisie de la hauteur du terrain
   hauteurTerrain = saisie("hauteur", MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);

   // Saisie du nombre de robots
   saisie("nbre object", MSG_ERREUR, NOMBRE_ROBOTS_MIN, NOMBRE_ROBOTS_MAX);

   const Terrain terrain(largeurTerrain, hauteurTerrain);
   terrain.afficher();
   cout << endl;

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}



