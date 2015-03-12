/******************************************************************************
* Lire un fichier contenant un tableau de nombres                             *
*-----------------------------------------------------------------------------*
* COMPONENT NAME   = lit_tableau.c                                               *
*                                                                             *
*******************************************************************************/

/*
 * 
syntaxe:  lit_tableau < fichier

*/

/*-------------+
|Include Files |
+-------------*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define EXT 
#include "tab.h"


/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/
FILE *fic_trace;


/*------------------------------------------------------*/
/*              Programme principal                     */
/*------------------------------------------------------*/

main(int argc, char **argv)
{
    long ic, il, i;
    
    nL=0;
    nC=0;
    nLd=0;
    nCd=0;
    memset(tab,'\0',sizeof(tab));

    yylex();

    printf ("lignes coordonnees %ld, col %ld \n",nLd, nCd);
    fflush(stdout);

    for ( il=0; il < nLd ; il++ ) {
        for ( ic=0; ic < nCd ; ic++) {
            printf ("\t%.7f",tabd[il][ic]);
        }
        printf ("\n");
    }
    fflush(stdout);
 
    if ( nC==5 ) nC=6;
    printf ("lignes %ld, col %ld \n",nL, nC);
    fflush(stdout);

    for ( il=0; il < nL ; il++ ) {
        for ( ic=0; ic < nC ; ic++) {
            printf ("\t%5ld",tab[il][ic]);
        }
        printf ("\n");
    }
    fflush(stdout);
 
    nIntersec=tab[NB_LIG-1][0];
    nRoute=tab[NB_LIG-1][1];
    nCar=tab[NB_LIG-1][2];
    DureeMax=tab[NB_LIG-1][3];
    StartIntersec=tab[NB_LIG-1][4];
 
    printf (" Nb intersections %ld\n", nIntersec );
    printf (" Nb routes %ld\n", nRoute );
    printf (" Nb voitures %ld\n", nCar );
    printf (" Duree Maximale %ld\n", DureeMax );
    printf (" Intersection de départ %ld\n", StartIntersec );



    exit(0);
}
