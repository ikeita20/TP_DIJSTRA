#include <iostream>
#include <stdlib.h>
#include "grille.h"
#include <fstream>


using namespace std ;

int main()
{
        grille g ;


       //cout << g.RetourneSommet(0,0) ;

    g.Dijstra(1);

        g.affichage() ;

       cout<<g.VoisinOuest(0,5) <<endl;

     //  cout << g.ValeurArrete(0,0,1,1) <<endl ;

    /*   cout << g.distanceE(0,0)<<endl;
        cout << g.distanceO(0,0)<<endl;
         cout << g.distanceS(0,0)<<endl;
          cout << g.distanceN(0,0)<<endl;

*/




    return 0;
}

