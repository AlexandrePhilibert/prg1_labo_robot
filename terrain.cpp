// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-11-22
// But            : Fonction permettant de générer un nombre aléatoire entre un min et un max.
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>

#include "terrain.h"

using namespace std;

Terrain::Terrain(int largeur, int hauteur, const vector<Robot>& robots) : largeur(largeur), hauteur(hauteur), robots(robots) {}

void Terrain::afficher() const {
   // Affiche le bord supérieur du terrain
   cout << string((size_t) this->largeur + 2, '-') << endl;

   for (size_t y = 0; y < (size_t) hauteur; ++y) {
      cout << "|";
      for (size_t x = 0; x < (size_t) largeur; ++x) {
         afficherCase(Position((int) x, (int) y));
      }
      cout << "|" << endl;
   }

   // Affiche le bord inférieur du terrain
   cout << string((size_t) this->largeur + 2, '-') << endl;
}

void Terrain::afficherCase(const Position& position) const {
   // TODO: Ne pas utiliser ça, car pas vu en classe...
   vector<Robot>::const_iterator it = find_if(robots.begin(), robots.end(), [position](Robot robot) {
      return robot.getPosition() == position;
   });

   if (it != robots.end()) {
      cout << it->getNumero();
   } else {
      cout << " ";
   }
}

void Terrain::prochainTour() {
   for (vector<Robot>::iterator robot = robots.begin(); robot != robots.end(); ++robot) {
      // Tirer une des directions possible
      // Déplacer le robot à cette position

      // Effectuer les combatsRobots de robots
      this->combatsRobots();
   }
}

void Terrain::deplacerRobots() {

}

void Terrain::combatsRobots() {
   // Aucun combatsRobots n'est possible s'il y a moins de 2 robots
   if (robots.size() < 2) {
      return;
   }

   // Mélange l'ordre des robots pour une égalité des chances de victoire de chaque robot lors d'un combatsRobots
   shuffle(robots.begin(), robots.end(), random_device());

   for (vector<Robot>::const_iterator robot1 = robots.begin(); robot1 != robots.end(); ++robot1) {
      for (vector<Robot>::const_iterator robot2 = robot1 + 1; robot2 != robots.end(); ++robot2) {
         if (robot1->getPosition() == robot2->getPosition()) {
            robots.erase(robot1, robot1 + 1);
         }
      }
   }
}

bool Terrain::contient(const Position &position) const {
   return position.getX() >= 0 && position.getX() < largeur
          && position.getY() >= 0 && position.getY() < hauteur;
}
