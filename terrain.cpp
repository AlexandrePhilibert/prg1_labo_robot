// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.cpp
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-11-22
// But            : Représentation d'un terrain sur lequel des robots combattent.
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

Terrain::Terrain(int largeur, int hauteur, const vector<Robot>& robots) : largeur(largeur), hauteur(hauteur), robots(robots) {
   evenements = stringstream();
}

void Terrain::afficher() const {
   // Affiche le bord supérieur du terrain
   cout << string((size_t) this->largeur + 2, '-') << endl;

   // Affichage des lignes du terrain
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

void Terrain::afficherEvenements() const {
   cout << endl << evenements.str() << endl;
}

vector<Robot>::const_iterator Terrain::robotEnPositon(const Position &position) const {
   for (vector<Robot>::const_iterator robot = robots.begin(); robot != robots.end(); ++robot) {
      if (robot->getPosition() == position) {
         return robot;
      }
   }

   return robots.end();
}

void Terrain::afficherCase(const Position& position) const {
   vector<Robot>::const_iterator robot = robotEnPositon(position);

   if (robot != robots.end()) {
      cout << robot->getId();
   } else {
      cout << " ";
   }
}

void Terrain::prochainTour() {
   // Un tour est constitué de deux étapes :
   // - Le déplacement des robots.
   // - Les combats de robots se situant sur la même position.
   this->deplacerRobots();
   this->combatsRobots();
}

void Terrain::deplacerRobots() {
   for (Robot& robot : robots) {
      // TODO: Tirer une direction aléatoire
      robot.deplacer((Direction) 1);
   }
}

void Terrain::combatsRobots() {
   // Aucun combatsRobots n'est possible s'il y a moins de 2 robots
   if (robots.size() < 2) {
      return;
   }

   // Mélange l'ordre des robots pour une égalité des chances de victoire de chaque robot lors d'un combatsRobots
   shuffle(robots.begin(), robots.end(), random_device());

   // Compare si les positions de 2 robots sont identiques, dans ce cas, le deuxième robot du vecteur
   // ayant la même position est supprimé (il a perdu le combat).
   // TODO: Gérer le cas ou plus de deux robots sont à la même position ?
   for (vector<Robot>::const_iterator robot1 = robots.begin(); robot1 != robots.end(); ++robot1) {
      for (vector<Robot>::const_iterator robot2 = robot1 + 1; robot2 != robots.end(); ++robot2) {
         if (robot1->getPosition() == robot2->getPosition()) {
            // Ajout du résultat du combat au flux d'événements
            evenements << robot1->getId() << " killed " << robot2->getId() << endl;

            robots.erase(robot2, robot2 + 1);
            // Le vecteur de robots ne fait que de décroitre lors de l'exécution, il n'est pas nécessaire de garder de
            // l'espace dans ce vecteur.
            robots.shrink_to_fit();
         }
      }
   }
}