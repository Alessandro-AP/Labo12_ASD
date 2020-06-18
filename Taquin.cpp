/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo12
 Fichier     : Taquin.cpp
 Auteur(s)   : Alessandro Parrino, Joan Maillard, Victoria Logan
 Date        : 18/06/2020

 But         :

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

/* A FAIRE ALGORITHME DE RESOLUTION A* */

#include "Taquin.h"
#include <exception>

//Taquin resolu/objectif
Taquin objectif;

//Le constructeur par défaut crée un taquin résolu
Taquin::Taquin(){
   const size_t puzzleSize = puzzle.size();
   for(std::size_t x = 0; x < puzzleSize; ++x){
      for(std::size_t y= 0; y < puzzleSize; ++y){
         size_t valeur = x *puzzleSize  + y;
         puzzle[x][y] = initPiece(valeur, x, y);
      }
   }
}

//Constructeur avec un tableaux d'elements
Taquin::Taquin(const std::array<int,9>& array){
    if(estValide(array)) {
       const size_t puzzleSize = puzzle.size();
       for (std::size_t x = 0; x < puzzleSize; ++x) {
          for (std::size_t y = 0; y < puzzleSize; ++y) {
             size_t valeur = array[x * puzzleSize + y];
             puzzle[x][y] = initPiece(valeur, x, y);
          }
       }
    }
    else{
       throw std::invalid_argument("Taquin pas valide");
    }
}

bool Taquin::estResolu(){
   const size_t puzzleSize = puzzle.size();
   for(std::size_t x = 0; x < puzzleSize; ++x){
      for(std::size_t y= 0; y < puzzleSize; ++y){
         if(puzzle[x][y].valeur != objectif.puzzle[x][y].valeur)
            return false;
      }
   }
   return true;
}

bool estValide(const std::array<int,9>& array){
   int inversions = 0;

   for ( int i = 0; i < 9; i++ )
      for ( int j = i + 1; j < 9; j++ )
         if ( array[j] > array[i] && array[i] != 0 && array[j] != 0 )
            inversions++;

   // Si le nombre d'inversion est paire le puzzle est valide
   return inversions % 2 == 0;

}

int distancePiece(const Piece& piece, const Piece& pieceObjectif){
   int distanceX = abs(piece.x - pieceObjectif.x);
   int distanceY = abs(piece.y - pieceObjectif.y);
   return distanceX + distanceY;
}

int Taquin::distanceManhattan(){
int distance = 0;
const size_t puzzleSize = puzzle.size();

for (size_t x = 0; x < puzzleSize; ++x) {
   for (size_t y = 0; y < puzzleSize; ++y) {
      Piece piece = puzzle[x][y];
      Piece pieceObjectif = objectif.puzzle[x][y];
      distance = distancePiece(piece, pieceObjectif);
   }
}

return distance;
}