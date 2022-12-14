// -----------------------------------------------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-20
// But            : Ce programme demande à l'utilisateur de saisir la largeur et hauteur d'un
//                  terrain, ainsi qu'un nombre de robots. Ces robots vont ensuite se déplacer sur
//                  le terrain et se battre. Le programme s'arrête lorsqu'il n'y a plus qu'un seul
//                  robot en vie.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <cstdlib>  // EXIT_SUCCESS
#include <limits>   // cin.ignore
#include <iostream> // cin & cout
#include <vector>   // vecteurs de robot
#include <thread>   // this_thread::sleep_for()

#include "saisie.h"
#include "terrain.h"

using namespace std;

int main() {
   // Le message de saisie de la largeur du terrain
   const string MSG_SAISIE_LARGEUR = "largeur";
   // Le message de saisie de la hauteur du terrain
   const string MSG_SAISIE_HAUTEUR = "hauteur";
   // Le message de saisie du nombre de robots
   const string MSG_SAISIE_NOMBRE_ROBOTS = "nbre object";
   // Le message d'erreur qui s'affichera lorsque la saisie est hors de l'interval spécifié
   const string MSG_ERREUR = "/!\\ erreur de saisie ...";
   // La largeur de terrain minimum qui pourra être choisi par l'utilisateur
   const int LARGEUR_TERRAIN_MIN = 10;
   // La largeur de terrain maximum qui pourra être choisi par l'utilisateur
   const int LARGEUR_TERRAIN_MAX = 1000;
   // La hauteur de terrain minimum qui pourra être choisi par l'utilisateur
   const int HAUTEUR_TERRAIN_MIN = 10;
   // La hauteur de terrain maximum qui pourra être choisi par l'utilisateur
   const int HAUTEUR_TERRAIN_MAX = 1000;
   // Le nombre de robots minimum qui pourra être choisi par l'utilisateur
   const int NOMBRE_ROBOTS_MIN = 1;
   // Le nombre de robots maximum qui pourra être choisi par l'utilisateur
   const int NOMBRE_ROBOTS_MAX = 10;
   // Temps d'attente entre chaque tour
   const chrono::duration TEMPS_ENTRE_TOUR = 500ms;

   // La largeur du terrain saisie par l'utilisateur
   int largeurTerrain;
   // La hauteur du terrain saisie par l'utilisateur
   int hauteurTerrain;
   // Le nombre de robots saisi par l'utilisateur
   int nombreRobots;

   cout << "ce programme vous permet de créer un terrain sur lequel des robots vont s'affronter" << endl << endl;

   // Saisie de la largeur du terrain
   largeurTerrain = saisie(MSG_SAISIE_LARGEUR, MSG_ERREUR, LARGEUR_TERRAIN_MIN, LARGEUR_TERRAIN_MAX);
   // Saisie de la hauteur du terrain
   hauteurTerrain = saisie(MSG_SAISIE_HAUTEUR, MSG_ERREUR, HAUTEUR_TERRAIN_MIN, HAUTEUR_TERRAIN_MAX);
   // Saisie du nombre de robots
   nombreRobots = saisie(MSG_SAISIE_NOMBRE_ROBOTS, MSG_ERREUR, NOMBRE_ROBOTS_MIN, NOMBRE_ROBOTS_MAX);

   // Création des positions de départ des robots
   vector<Position> positionsDeDepart = vector<Position>((size_t) nombreRobots);
   Position::unique(positionsDeDepart.begin(), positionsDeDepart.end(), largeurTerrain - 1, hauteurTerrain - 1);

   // Création des robots et attribution des positions de départ uniques
   vector<Robot> robots = vector<Robot>();
   robots.reserve((size_t) nombreRobots);
   for (size_t i = 0; i < (size_t) nombreRobots; ++i) {
      robots.push_back(Robot(positionsDeDepart[i]));
   }

   Terrain terrain(robots, largeurTerrain, hauteurTerrain);

   // Le programme se termine lorsqu'un seul robot est en vie
   while(robots.size() > 1) {
      // Repris du corrigé présenté en classe du labo tondeuse.
      #ifdef _WIN32
            system("cls");
      #else
            system("clear");
      #endif

      // Déplace les robots et effectue les combats
      terrain.prochainTour();

      // Affichage du terrain et des événements
      cout << terrain << endl;
      terrain.afficherEvenements();

      // Pause l'exécution pendant 500 millisecondes
      this_thread::sleep_for(TEMPS_ENTRE_TOUR);
   }

   // TODO: Indiquer quel robot et le gagnant ?

   cout << "Pressez ENTER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}



