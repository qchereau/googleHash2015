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

void genere_result()
{
    int il,ig,sumg,maxg,nS,nR,i, minGlob;
    int rangee[NB_RANGEE];
    
    for ( il=0; il < NB_SERV ; il++ ) {
        if ( serv[il][5] == -1 ) {
            printf ("x\n");
        } else {
            printf ("%d %d %d\n", serv[il][4] , serv[il][5], serv[il][3] );
	}
    }
    
    
    minGlob=5000;
    for  ( ig=0; ig < NB_GROUP ; ig++ ) {
        maxg=0;
        sumg=0;
        nS=0;
        nR=0;
        memset(rangee,'\0',sizeof(rangee));
        for ( il=0; il < NB_SERV ; il++ ) {
            if ( serv[il][3] == ig && serv[il][5] != -1 ) {
                sumg+=serv[il][1];
                if ( maxg < serv[il][1] ) {
                    maxg = serv[il][1];
                }
                rangee[serv[il][4]]++;
                nS++;
            }
        }
        for ( i=0; i < NB_RANGEE ; i++ ) {
            if ( rangee[i] == 1 ) nR++;
            if ( rangee[i] > 1 ) {
                nR++;
                fprintf (stderr,"ERR groupe %d, rangee %d nb serv %d  \n", ig, i, rangee[i] );
               
            }
        }
        fprintf (stderr,"groupe %d, capacite garantie %d sumg %d %d, nb servers %d\n", 
                ig, sumg-maxg , sumg, maxg, nS);
        if ( sumg-maxg < minGlob) minGlob=sumg-maxg;
    }
    fprintf (stderr,"Min Glob %d \n", minGlob );
   
}


int cap_garanti_group(int groupe)
{
    int il,sumg,maxg;
      
    maxg=0;
    sumg=0;
    for ( il=0; il < NB_SERV ; il++ ) {
        if ( serv[il][3] == groupe && serv[il][5] != -1 ) {
            sumg+=serv[il][1];
            if ( maxg < serv[il][1] ) {
                maxg = serv[il][1];
            }
        }
    }
    return(sumg-maxg);
}

/*-
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

    //optimizer_serveur();

    genere_result();

    exit(0);
}
