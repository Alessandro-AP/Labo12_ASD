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
#include <string>
#include <array>
#include <vector>

class Taquin{
public:
	Taquin();
	Taquin(const std::array<int,9>& array);
	int distanceManhattan ();
	bool estResolu();
	Piece trouvePiece(int valeur);
	std::vector<int> getPossibleMoves() const;
	void swapPiece(Piece& lhs, int empl2);
	
private:
	std::array< std::array < Piece,3 > ,3 > puzzle;
	//Taquin* parent = nullptr;
	std::vector<int> _possibleMoves; // calculé pour permettre à l'algo d'exploration de savoir quels sont les enfants
								// à explorer plus loin dans l'arbre
	void evaluatePossibleMoves(std::vector<int>& movesTable);

	
};

bool inputValide(const std::array<int,9>& array);


#endif //LABO12_ASD_TAQUIN_H
