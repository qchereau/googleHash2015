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
    long ic, il;
    char *nom_fic_result, nom_fichier_result[80];
    
    nL=0;
    nC=0;
    memset(tab,'\0',sizeof(tab));

    yylex();
    
    printf ("lignes %ld, col %ld \n",nL, nC);

    for ( il=0; il < nL ; il++ ) {
        for ( ic=0; ic < nC ; ic++) {
            printf ("\t%5ld",tab[il][ic]);
        }
        printf ("\n");
    }


    exit(0);
}
