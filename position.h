#ifndef PRG1_LABO_ROBOT_POSITION_H
#define PRG1_LABO_ROBOT_POSITION_H

enum class Direction { HAUT, DROITE, BAS, GAUCHE };

class Position {
public:
   Position(int x = 0, int y = 0);

   int getX() const;
   int getY() const;

   static Position random(int xMax, int yMax);

   bool operator==(const Position& position) const;

   // TODO: Ajouter l'opérateur dans l'autre sense (direction + position)
   Position operator+(Direction direction) const;

private:
   int x;
   int y;
};

#endif //PRG1_LABO_ROBOT_POSITION_H
