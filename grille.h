//
// Created by keita on 28/11/18.
//

#ifndef TP9_GRILLE_H
#define TP9_GRILLE_H
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

 struct DistancePrecedant
 {
    int distance ;
    int predecesseur;
 };

class grille
{

    private:
        int L;
        int C ;
        int  * Tableaux ;
        char * TabCouleur;
        DistancePrecedant * PCD ;

    public:
        grille() ;

        int RetourneSommet(int i, int j) ;
        char CouleurSommet(int i, int j);
        int ValeurArrete(int i, int j , int k, int l) ;
        int VoisinEst(int i , int j ) ;
        int VoisinOuest(int i , int j ) ;
        int VoisinSud(int i , int j ) ;
        int VoisinNord(int i , int j ) ;
        int GetCout(int i, int j) ;
        int GetPredecesseur(int i, int j) ;
        int distanceE(int i, int j);
        int distanceO(int i, int j);
        int distanceS(int i, int j);
        int distanceN(int i, int j);
        void CalculCout(int i, int j);
        void affichage() ;
        void Dijstra() ;
        void initialiser() ;


};



#endif //TP9_GRILLE_H
