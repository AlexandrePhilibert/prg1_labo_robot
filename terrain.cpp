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

const char Terrain::CELLULE_VIDE = ' ';
const char Terrain::BORD_HORIZONTAL = '-';
const char Terrain::BORD_VERTICAL   = '|';

// -----------------------------------------------------------------------------------------------
// region Foncteurs
// -----------------------------------------------------------------------------------------------

class RobotMemePosition {
public:
   RobotMemePosition(const Robot& robot) : robot(robot) {};

   bool operator()(const Robot& robot) const {
      return this->robot != robot && this->robot.getPosition() == robot.getPosition();
   }
private:
   const Robot& robot;
};

class RobotEnPosition {
public:
   RobotEnPosition(const Position& position): position(position) {};
   bool operator() (const Robot& robot) {
      return robot.getPosition() == position;
   }
private:
   const Position& position;
};

// -----------------------------------------------------------------------------------------------
// endregion Foncteurs
// -----------------------------------------------------------------------------------------------

Terrain::Terrain(vector<Robot>& robots, int largeur, int hauteur) : largeur(largeur),
                                                                    hauteur(hauteur),
                                                                    robots(robots) {
   evenements = stringstream();
}

void Terrain::afficherEvenements() const {
   cout << evenements.str() << endl;
}

void Terrain::afficherCase(const Position& position) const {
   vector<Robot>::const_iterator robot = find_if(robots.begin(), robots.end(), RobotEnPosition(position));

   if (robot != robots.end()) {
      cout << robot->getId();
   } else {
      cout << Terrain::CELLULE_VIDE;
   }
}

void Terrain::deplacer(Robot& robot) {
   // Créer une liste des directions possible pour le robot
   vector<Direction> directionsPossibles = vector<Direction>();
   for (Direction direction = Direction::HAUT; direction <= Direction::GAUCHE; ++direction) {
      Position positionConsideree = robot.getPosition() + direction;

      if (positionConsideree.getX() >= 0 && positionConsideree.getX() < largeur &&
          positionConsideree.getY() >= 0 && positionConsideree.getY() < hauteur) {
         directionsPossibles.push_back(direction);
      }
   }

   int indexAleatoire = random(0, (int) directionsPossibles.size() - 1);
   // Déplace le robot dans une des directions possibles
   Direction directionChoisie = directionsPossibles[(size_t) indexAleatoire];
   robot.deplacer(directionChoisie);
}

void Terrain::prochainTour() {
   // Mélange l'ordre des robots pour une égalité des chances de victoire de chaque robot lors d'un combatsRobots
   shuffle(robots.begin(), robots.end(), random_device());

   for (Robot& robot : robots) {
      this->deplacer(robot);

      vector<Robot>::iterator robotATue = find_if(robots.begin(), robots.end(), RobotMemePosition(robot));
      if (robotATue != robots.end()) {
         // Ajout du combat de robot aux événements
         evenements << robot.getId() << " killed " << robotATue->getId() << endl;

         // Suppression du robot tué de la liste des robots
         robots.erase(robotATue);
      }
   }
}

// -----------------------------------------------------------------------------------------------
// region Opérateurs
// -----------------------------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------------------------
// endregion Opérateurs
// -----------------------------------------------------------------------------------------------
