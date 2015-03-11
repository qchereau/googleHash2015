%{ 

/*-------------+
|Include Files |
+-------------*/
#include <stdio.h>
#include <errno.h>
#include <stropts.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


#define EXT 
#include "tab.h"


/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/
long iC=0;


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
/*
    for ( il=0; il < nL ; il++ ) {
        for ( ic=0; ic < nC ; ic++) {
            printf ("\t%5ld",tab[il][ic]);
        }
        printf ("\n");
    }
*/


    exit(0);
}


%}

%%

[+-][0-9]*	|
[0-9]*		{
	tab[nL][iC]=atol(yytext);
	if ( tab[nL][iC]==1 ) {
		printf("%ld %ld 1 1\n", iC, nL );
	}
	iC++;
	if ( iC > nC ) { nC = iC;
	    if ( nC > NB_COL ) {
		fprintf (stderr, "ERREUR, trop de colonnes\n");
		exit(0);
	    }
	}
}
\n	{
	nL++;
	iC=0;
	if ( nL > NB_LIG ) {
		fprintf (stderr, "ERREUR, trop de lignes\n");
		exit(0);
	}
}

.	;
