// -----------------------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-11-22
// But            : Ce programme demande à l'utilisateur de saisir la largeur et hauteur d'un
//                  terrain, ainsi qu'un nombre de robots. Ces robots vont ensuite se déplacer sur
//                  le terrain et se battre. Le programme s'arrête lorsqu'il n'y a plus qu'un seul
//                  robot en vie.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib>
#include <limits>
#include <iostream>
#include <vector>
#include <thread>  // this_thread::sleep_for()

#include "saisie.h"
#include "terrain.h"

using namespace std;

int main() {
   /**
    * Le message d'erreur qui s'affichera lorsque la saisie est hors de l'interval spécifié
    */
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";
   /**
    * La largeur de terrain minimum qui pourra être choisi par l'utilisateur
    */
   const int LARGEUR_TERRAIN_MIN = 10;
   /**
    * La largeur de terrain maximum qui pourra être choisi par l'utilisateur
    */
   const int LARGEUR_TERRAIN_MAX = 1000;
   /**
    * La hauteur de terrain minimum qui pourra être choisi par l'utilisateur
    */
   const int HAUTEUR_TERRAIN_MIN = 10;
   /**
    * La hauteur de terrain maximum qui pourra être choisi par l'utilisateur
    */
   const int HAUTEUR_TERRAIN_MAX = 1000;
   /**
    * Le nombre de robots minimum qui pourra être choisi par l'utilisateur
    */
   const int NOMBRE_ROBOTS_MIN = 0;
   /**
    * Le nombre de robots maximum qui pourra être choisi par l'utilisateur
    */
   const int NOMBRE_ROBOTS_MAX = 9;

   /**
    * La largeur du terrain saisie par l'utilisateur
    */
   int largeurTerrain;
   /**
    * La hauteur du terrain saisie par l'utilisateur
    */
   int hauteurTerrain;
   /**
    * Le nombre de robots saisi par l'utilisateur
    */
   int nombreRobots;

   // TODO: Description du programme
   cout << "ce programme ..." << endl;

   // Saisie de la largeur du terrain
   largeurTerrain = saisie("largeur", MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);

   // Saisie de la hauteur du terrain
   hauteurTerrain = saisie("hauteur", MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);

   // Saisie du nombre de robots
   nombreRobots = saisie("nbre object", MSG_ERREUR, NOMBRE_ROBOTS_MIN, NOMBRE_ROBOTS_MAX);

   // TODO: Positions de départ
   vector<Position> positionsDepart = vector<Position>();

   vector<Robot> robots = vector<Robot>();
   for (int i = 1; i <= nombreRobots; ++i) {
      robots.push_back(Robot(i, Position::random(largeurTerrain, hauteurTerrain)));
   }

   Terrain terrain(largeurTerrain, hauteurTerrain, robots);

   while(robots.size() > 1) {
      terrain.afficher();

      // Pause l'exécution pendant 500 millisecondes
      this_thread::sleep_for(500ms);

      #ifdef _WIN32
         system("cls");
      #else
         system("clear");
      #endif

      terrain.prochainTour();
   }

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}



