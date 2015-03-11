%{ 
#include "tab.h"

long iC=0;
%}

%%

[+-][0-9]*	|
[0-9]*		{
	tab[nL][iC]=atol(yytext);
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
