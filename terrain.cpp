#include <iostream>
#include <string>

#include "terrain.h"

using namespace std;

Terrain::Terrain(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {}

void Terrain::afficher() const {
   cout << string((size_t) this->largeur + 2, '-') << endl;

   for (size_t y = 0; y < (size_t) hauteur; ++y) {
      cout << "|";
      for (size_t x = 0; x < (size_t) largeur; ++x) {
         cout << " ";
      }
      cout << "|" << endl;
   }

   cout << string((size_t) this->largeur + 2, '-');
}
