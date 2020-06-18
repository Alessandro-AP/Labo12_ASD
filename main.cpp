/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo12
 Fichier     : main.cpp
 Auteur(s)   : Alessandro Parrino, Joan Maillard, Victoria Logan
 Date        : 18/06/2020

 But         :

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include "Taquin.h"
using namespace std;
int main() {

   std::array<int,9> array;
   int size = array.size();
   //Creation taquin (test)
   cout<<"entrez l'etat du taquin :";
   for(int i = 0; i < size; ++i){
      cin >> array[i];
   }
   Taquin taquin(array);

   return 0;
}
