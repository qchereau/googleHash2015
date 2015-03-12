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

extern void repartir_serveur();
extern int prochain_emplacement_libre( int , int );
extern void localiser_serveur();

/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/

void genere_result()
{
    int il;
    for ( il=0; il < NB_SERV ; il++ ) {
        if ( serv[il][4] == -1 ) {
            printf ("x\n");
        } else {
            printf ("%d %d %d\n", serv[il][4] , serv[il][5], serv[il][3] );
	}
    }
}

/*------------------------------------------------------*/
/*              Programme principal                     */
/*------------------------------------------------------*/

main(int argc, char **argv)
{
    int ic, il, i;
    
    memset(serv,'\0',sizeof(serv));
    memset(center,'\0',sizeof(center));

    yylex();

    /* serv et center sont initialises */

    repartir_serveur();
    localiser_serveur();

    genere_result();

    exit(0);
}
