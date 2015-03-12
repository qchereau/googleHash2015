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

    /* serv et center sont initialises */

 


    exit(0);
}
