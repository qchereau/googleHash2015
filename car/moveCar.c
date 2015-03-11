/******************************************************************************
* deplacement d'une voiture                                               *
*                                                                             *
*******************************************************************************/

/*-------------+
|Include Files |
+-------------*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/

#include "tab.h"


long deplacement_suivant( long Its)
{
    int line;
    int bestRatio, nextPosition;
    /*on peut pas avoir de ratio negatif*/
    bestRatio=-1;
    line= founf_first_connexion(Its);
    while(tab[line][0]==Its){
        if(tab[line][5]>bestRatio){
            bestRatio=tab[line][5];
            nextPosition=tab[line][1];
        }
        line++;
    }
    
    return nextPosition;
}

/*récupere le numéro de la première ligne de la node considérée*/
int found_first_connexion (long node)
{
    	/* Place dans tab */
	long i;
	i = Its*MoyRues;
        
        /*cas element trop petit, il faut monté*/
	if ( tab[i][0] < Its ) {
            while(tab[i][0] < Its){
                i++;
            }
            return i;
	}else{
            while(tab[i][0] >= Its){
                i--;
            }
            return i+1;
        }
}
}

