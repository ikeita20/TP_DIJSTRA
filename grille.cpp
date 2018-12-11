#include <iostream>
#include "grille.h"
#include <fstream>
#include <math.h>
#include <stack>
#include<queue>


using namespace std;




grille::grille() {

    ifstream monFichier ("fichier.txt");

    if (monFichier.is_open()) {
       monFichier >> L;
       monFichier >> C ;

        Tableaux = new int [L*C] ;
        TabCouleur = new char [L*C] ;
        PCD = new DistancePrecedant[L*C] ;

           for (int i = 0 ; i<= L*C ; i++ )
           {
                monFichier>>Tableaux[i] ;
                TabCouleur[i] = 'b' ;

           }


        monFichier.close();
    }
    else {
        cout << "Erreur d’ouverture du fichier: " << "fichier.txt" ;
    }


}


int grille::RetourneSommet(int i, int j)
{
    return Tableaux[(i*C)+j] ;
}
char grille::CouleurSommet(int i, int j)
{
    return TabCouleur[(i*C)+j] ;
}


int grille::VoisinEst(int i, int j )
{
    if(j >= C-1 || i >= L)
    {
        return -1 ;
    }
    else
    {
         return  RetourneSommet(i,j+1 ) ;
    }


}
int grille::VoisinOuest(int i, int j)
{
    if(j<=0 || i >= L || j>=C )
    {
        return -1;
    }
    else
    {
        return  RetourneSommet(i,j-1) ;
    }

}
int grille::VoisinSud(int i, int j)
{
    if( i>=L-1 || j >= C-1)
    {
        return -1 ;
    }
    else
    {
        return  RetourneSommet(i+1,j) ;
    }

}

int grille::VoisinNord(int i, int j)
{
    if(i<= 0 ||  j>=L )
    {
        return -1 ;
    }
    else
    {
         return  RetourneSommet(i-1,j) ;
    }

}
/*
int grille::ValeurArrete(int i, int j, int k, int l)
{
    int s1 = RetourneSommet(i,j) ;
    int s2 = RetourneSommet(k,l) ;
    int *tabVoisin = new int [4] ;
    int valeur ;
     tabVoisin[0]= VoisinEst(i,j);
      tabVoisin[1]= VoisinOuest(i,j);
       tabVoisin[2]= VoisinSud(i,j);
        tabVoisin[3]= VoisinNord(i,j);

        for(int i=0; i<=3; i++)
        {
            if(tabVoisin[i] == s2 )
            {
               // cout<<"voisin "<<endl;
                valeur = sqrt( 1 + pow( s1 - s2, 2 ) ) ;
                return valeur ;

            }

        }


    return -1 ;
}

*/

void grille::affichage()
{
    for(int i = 0 ; i< L ; i++ )
    {
        for(int j = 0; j< C; j++ )
        {
            CalculCout(i,j);
            cout<< RetourneSommet(i,j) <<"-"<<CouleurSommet(i,j) <<" "<< PCD[i].distance << " " ;

        }
        cout<<endl;

    }
        cout<<endl;
}

int grille::GetCout(int i, int j)
{
    return PCD[(i*C)+j].distance;
}

int grille::GetPredecesseur(int i, int j)
{
    return PCD[(i*C)+j].predecesseur;
}

int grille::distanceN(int i, int j){

   if (i>0)
   {

      int s1 = RetourneSommet(i,j);
      int s2 = VoisinNord(i,j);

      return sqrt(1+pow(s1-s2,2));
   }
   return -1 ;
}
int grille::distanceS(int i, int j){

    int s1 = RetourneSommet(i,j);
    int s3=VoisinSud(i,j);

    return sqrt(1+pow(s1-s3,2));
}
int grille::distanceE(int i, int j){

    int s1 = RetourneSommet(i,j);
    int s5=VoisinEst(i,j);

    return sqrt(1+pow(s1-s5,2));
}
int grille::distanceO(int i, int j){

  if (j>0)
  {
     int s1 = RetourneSommet(i,j);
     int s4=VoisinOuest(i,j);

     return sqrt(1+pow(s1-s4,2));
    }
     return -1 ;
}


void grille::CalculCout(int i, int j )
{
    int VE,VO,VS,VN ;
    int temp, temp1 , minimum  ;

            VE = distanceE(i,j) ;
            VO = distanceO(i,j) ;
            VS = distanceS(i,j) ;
            VN = distanceN(i,j) ;


            if(VO == -1 && VN == -1 )
            {
                minimum = min(VE,VS) ;
                PCD[i*C+j].distance = minimum ;


            }
            else if( VN == -1 )
            {
                 temp = min(VE,VO) ;
                minimum = min(temp,VS) ;
                PCD[i*C+j].distance = minimum ;


            }
            else if( VE == -1 && VN == -1 )
            {
                 minimum = min(VO,VS) ;
                  PCD[i*C+j].distance = minimum ;

            }
            else if( VE == -1)
            {
                temp = min(VS,VN) ;
                minimum = min(temp,VO) ;
                PCD[i*C+j].distance = minimum ;
            }
            else if(VE == -1 && VS == -1 )
            {
                minimum = min(VO,VN) ;
                 PCD[i*C+j].distance = minimum ;
            }
            else if(VS== - 1 )
            {
                temp = min(VE,VO) ;
                minimum = min(temp,VN) ;
                 PCD[i*C+j].distance = minimum ;

            }

            else if(VO == - 1 )
            {
                temp = min(VS,VN) ;
                minimum = min(temp,VE) ;
                 PCD[i*C+j].distance = minimum ;

            }
            else if (VO == -1 && VS == -1 )
            {
                minimum = min(VE,VN) ;
                 PCD[i*C+j].distance = minimum ;

            }
            else
            {

                 temp = min(VE,VO) ;
                temp1 = min(VS,VN) ;
                 minimum = min(temp,temp1) ;
                  PCD[i*C+j].distance = minimum ;

            }


}

void initialiser()
{

}

void grille::Dijstra()
{
    queue<int>file ;
    int tabVoisin[4] ;
    int sommet ;
    bool trouver =false ;
    int coord_iS;
    int coord_jS;

    sommet = Tableaux[0] ;
    file.push(0) ;

            while( !file.empty() &&  TabCouleur[coord_iS*C+coord_jS] !='n' )
            {


                for(int i= 0; i<L;i++)
                {
                    for(int j = 0 ; j<C ; j++ )
                    {

                        if( sommet == Tableaux[i*C+j] )
                         {
                             trouver = true ;
                             coord_iS = i;
                             coord_jS = j ;

                        }

                    }


                }



                if(trouver)
                {
                     file.push(sommet) ;

                    TabCouleur[coord_iS*C+coord_jS] = 'g' ;

                    int ve,vo,vs,vn ;



                    ve = VoisinEst(coord_iS,coord_jS) ;
                    vo = VoisinOuest(coord_iS, coord_jS) ;
                    vs = VoisinSud(coord_iS, coord_jS) ;
                    vn = VoisinNord(coord_iS, coord_jS) ;

                    tabVoisin[0] = ve ;
                     tabVoisin[1] = vo ;
                      tabVoisin[2] = vs ;
                       tabVoisin[3] = vn ;

                       for(int i=0 ; i<=3; i++ )
                       {
                            if( tabVoisin[i] != -1 )
                            {

                                if( tabVoisin[i] == Tableaux[coord_iS*C+(coord_jS+1)] )
                                {
                                    file.push(tabVoisin[i]) ;
                                    TabCouleur[coord_iS*C+(coord_jS+1)] = 'g' ;

                                }
                                else if ( tabVoisin[i] == Tableaux[coord_iS*C+(coord_jS-1)] )
                                {
                                    file.push(tabVoisin[i]) ;
                                    TabCouleur[coord_iS*C+(coord_jS-1)] = 'g' ;

                                }
                                else if ( tabVoisin[i] == Tableaux[ (coord_iS+1)*C + coord_jS ] )
                                {
                                    file.push(tabVoisin[i]) ;
                                    TabCouleur[ (coord_iS+1)*C+ coord_jS ] = 'g' ;

                                }
                                else
                                {
                                    file.push(tabVoisin[i]) ;
                                    TabCouleur[ (coord_iS-1)*C+ coord_jS ] = 'g' ;


                                }

                            }
                       }


                }

                else
                {
                    cout<<"ce sommet n'existe pas dans le graphe ! "<<endl; trouver = false ;
                }

                      //  CalculCout(coord_iS,coord_jS) ;
                        TabCouleur[coord_iS*C+coord_jS] = 'n' ;

                         file.pop() ;

                         sommet = (int)file.front() ;






        }


}








