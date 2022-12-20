// -----------------------------------------------------------------------------------------------
// Fichier        : terrain.h
// Auteur(s)      : POLLIEN Lionel & PHILIBERT Alexandre
// Date           : 2022-12-20
// But            : Classe représentant un terrain contenant des robots effectuant des combats
// Modifications  : NIL
// Remarque(s)    :
// Compilateur    : g++ 11.2.0
// Standard C++   : C++ 20
// -----------------------------------------------------------------------------------------------

#ifndef PRG1_LABO_ROBOT_TERRAIN_H
#define PRG1_LABO_ROBOT_TERRAIN_H

#include <vector>  // vecteurs de robots
#include <sstream> // événements
#include <ostream> // cout

#include "robot.h"

class Terrain {
   friend std::ostream& operator<<(std::ostream& os, const Terrain& terrain);
public:
   explicit Terrain(std::vector<Robot>& robots, int largeur = 10, int hauteur = 10);

   /**
    * Affiche les événements qui sont survenus depuis le début de la partie.
    *
    * @throws NIL
    * @return void
    */
   void afficherEvenements() const;

   /**
    * Déplace et réalise les combats de chaque robots. Lorsqu'un robot est tué, un enregistrement est ajouté à la liste
    * des événements.
    *
    * @throws NIL
    * @return void
    */
   void prochainTour();

private:
   /**
    * Les événements sont des actions qui ont été réalisées sur le terrain,
    * par. ex un robot tuant un autre robot.
    */
   std::stringstream evenements;

   /**
    * Affiche la case si c'est un robot ou un espace vide.
    *
    * @param position position de la case que l'on veut afficher
    * @throws NIL
    * @return void
    */
   void afficherCase(const Position& position) const;

   /**
    * Analyse les positions possibles pour le robot et le deplace aleatoirement dans une de ces directions.
    *
    * @param robot Objet de type robot
    * @throws NIL
    * @return void
    */
   void deplacer(Robot& robot);


   const int largeur;
   const int hauteur;

   /**
    * Liste des robots en vie.
    */
   std::vector<Robot>& robots;

   // Représentation d'une cellule vide à l'affichage.
   static const char CELLULE_VIDE;
   // Représentation du bord horizontal (haut et bas) du terrain.
   static const char BORD_HORIZONTAL;
   // Représentation du bord vertical (gauche et droite) du terrain.
   static const char BORD_VERTICAL;
};

std::ostream& operator<<(std::ostream& os, const Terrain& terrain);

#endif //PRG1_LABO_ROBOT_TERRAIN_H
