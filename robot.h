#ifndef PRG1_LABO_ROBOT_ROBOT_H
#define PRG1_LABO_ROBOT_ROBOT_H

enum class  Direction   {DROITE, GAUCHE, HAUT, BAS};

class Robot{
public :
   Robot(int numero, int x, int y);

   int getNumero() const;
   int getX() const;
   int getY() const ;

   void setX(int x);
   void setY(int y);

   //Deplacement
   void deplacer();

private:
   int numero;
   int x;
   int y;
};

#endif //PRG1_LABO_ROBOT_ROBOT_H
