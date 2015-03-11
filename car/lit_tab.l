%START NB

%{ 
#include "tab.h"

long iC=0;
long iCd=0;
%}

%%

<NB>[+-][0-9]*		|
<NB>[0-9]*		{
	tab[NB_LIG-1][iC]=atol(yytext);
	iC++;
	if ( iC > nC ) { 
	    if ( nC > NB_COL ) {
		fprintf (stderr, "ERREUR, trop de colonnes\n");
		exit(0);
	    }
	}
}
<NB>\n      { 
    BEGIN 0;
}

[+-]*[0-9]+\.[0-9]* { 
	tabd[nLd][iCd]=atof(yytext);
	iCd++;
        if ( iCd > nCd ) { nCd = iCd;
            if ( nCd > NB_COL ) {
                fprintf (stderr, "ERREUR, trop de colonnes Float\n");
                exit(0);
            }
        }
}


[+-][0-9]+	|
[0-9]+		{
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
	if ( iC == 5 && tab[nL][3] !=0 ) tab[nL][5]=(10*tab[nL][4])/tab[nL][3];
	if ( iC > 0 ) nL++;
	if ( iCd > 0 ) nLd++;
	iC=0;
	iCd=0;
	if ( nL > NB_LIG ) {
		fprintf (stderr, "ERREUR, trop de lignes\n");
		exit(0);
	}
	if ( nLd > NB_LIG ) {
		fprintf (stderr, "ERREUR, trop de lignes float\n");
		exit(0);
	}
}

NB	{
	BEGIN NB;
}





.	;
