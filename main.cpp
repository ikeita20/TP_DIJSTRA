#include <iostream>
#include <stdlib.h>
#include "grille.h"
#include <fstream>


using namespace std ;

int main()
{
        grille g ;

        g.Dijstra();

        g.affichage() ;

    return 0;
}

