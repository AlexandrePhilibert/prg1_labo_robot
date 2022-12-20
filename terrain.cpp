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
#include "robot.h"
#include "annexe.h"

using namespace std;

const char Terrain::BORD_HORIZONTAL = '-';
const char Terrain::BORD_VERTICAL   = '|';

Terrain::Terrain(vector<Robot>& robots, int largeur, int hauteur) : largeur(largeur),
                                                                    hauteur(hauteur),
                                                                    robots(robots) {
   evenements = stringstream();
}

void Terrain::afficherEvenements() const {
   cout << evenements.str() << endl;
}

vector<Robot>::const_iterator Terrain::robotEnPositon(const Position &position) const {
   for (vector<Robot>::const_iterator robot = robots.begin(); robot != robots.end(); ++robot) {
      if (robot->getPosition() == position) {
         return robot;
      }
   }

   return robots.cend();
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
   // Aucun combatsRobots n'est possible s'il y a moins de 2 robots
   if (robots.size() < 2) {
      return;
   }

   // Mélange l'ordre des robots pour une égalité des chances de victoire de chaque robot lors d'un combatsRobots
   shuffle(robots.begin(), robots.end(), random_device());

   for (Robot& robot : robots) {
      // Créer une liste des directions possible pour le robot
      vector<Direction> directionsPossibles = vector<Direction>();
      for (Direction direction = Direction::HAUT; direction <= Direction::GAUCHE; ++direction) {
         Position positionConsideree = robot.getPosition() + direction;

         if (positionConsideree.getX() >= 0 && positionConsideree.getX() < largeur &&
             positionConsideree.getY() >= 0 && positionConsideree.getY() < hauteur) {
            directionsPossibles.push_back(direction);
         }
      }

      int valeurRandom = random(0, (int) directionsPossibles.size() - 1);
      // Déplace le robot dans une des directions possibles
      Direction directionChoisie = directionsPossibles[(size_t) valeurRandom];
      robot.deplacer(directionChoisie);

      for (vector<Robot>::iterator it = robots.begin(); it != robots.end(); ) {
         if (robot != *it && robot.getPosition() == (it->getPosition() + directionChoisie)) {
            evenements << robot.getId() << " killed " << it->getId() << endl;

            robots.erase(it);
         } else {
            ++it;
         }
      }
   }
}

ostream& operator<<(ostream& os, const Terrain& terrain) {
   // Affiche le bord supérieur du terrain
   os << string((size_t) terrain.largeur + 2, Terrain::BORD_HORIZONTAL) << endl;

   // Affichage des lignes du terrain
   for (size_t y = 0; y < (size_t) terrain.hauteur; ++y) {
      os << Terrain::BORD_VERTICAL;
      for (size_t x = 0; x < (size_t) terrain.largeur; ++x) {
         terrain.afficherCase(Position((int) x, (int) y));
      }
      os << Terrain::BORD_VERTICAL << endl;
   }

   // Affiche le bord inférieur du terrain
   os << string((size_t) terrain.largeur + 2, Terrain::BORD_HORIZONTAL) << endl;

   return os;
};
