/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo12
 Fichier     : Piece.h
 Auteur(s)   : Alessandro Parrino, Joan Maillard, Victoria Logan
 Date        : 18/06/2020

 But         :

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO12_ASD_PIECE_H
#define LABO12_ASD_PIECE_H

struct Piece {
   int valeur;
   int x;
   int y;
};

Piece initPiece(int valeur, int x, int y );

#endif //LABO12_ASD_PIECE_H
