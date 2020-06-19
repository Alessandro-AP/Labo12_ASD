/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo12
 Fichier     : Taquin.h
 Auteur(s)   : Alessandro Parrino, Joan Maillard, Victoria Logan
 Date        : 18/06/2020

 But         :

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO12_ASD_TAQUIN_H
#define LABO12_ASD_TAQUIN_H
#include "Piece.h"
#include <array>

enum class Mouvements {HAUT = 0, BAS, GAUCHE, DROITE};
class Taquin{
public:
   Taquin();
   Taquin(const std::array<int,9>& array);
   int distanceManhattan ();
   bool estResolu();
   Piece trouvePiece(int valeur);
   Taquin prochainTaquin(Taquin taquin, Mouvements movement , int x, int y);
private:
   std::array< std::array < Piece,3 > ,3 > puzzle;
   //Taquin* parent = nullptr;
};

bool estValide(const std::array<int,9>& array);


#endif //LABO12_ASD_TAQUIN_H
