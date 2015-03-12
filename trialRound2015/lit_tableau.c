/******************************************************************************
* Lire un fichier contenant un tableau de nombres                             *
*-----------------------------------------------------------------------------*
*  COMPONENT NAME   = lit_tableau.c                                               *
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


/*------------------------------------------------------*/
/*              Programme principal                     */
/*------------------------------------------------------*/

main(int argc, char **argv)
{
    int ic, il, i;
    
    memset(serv,'\0',sizeof(serv));
    memset(center,'\0',sizeof(center));

    yylex();

/*
    for ( il=0; il < NB_RANGEE ; il++ ) {
        for ( ic=0; ic < NB_EMPLACEMENT ; ic++) {
            if ( center[il][ic] == 1 ) {
            	printf ("%d %d\n",il, ic);
            }
        }
    }
    fflush(stdout);
 
    printf ("SERVEURS \n");
    fflush(stdout);

    for ( il=0; il < NB_SERV ; il++ ) {
        printf ("%d %d\n", serv[il][0], serv[il][1] );
    }
    fflush(stdout);
*/ 
 //   printf ("TRI CAPACITE\n");
    for ( il=0; il < NB_SERV ; il++ ) {
        printf ("%d %d\n", serv[il][1], il );
    }
    fflush(stdout);


 //   printf ("TRI utilite\n");
    for ( il=0; il < NB_SERV ; il++ ) {
        fprintf (stderr,"%d %d\n", serv[il][2], il );
    }
    fflush(stdout);


    exit(0);
}
