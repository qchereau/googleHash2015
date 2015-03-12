%START SERV 

%{ 
#include "tab.h"

long rang=-1;
long emp=-1;
long iserv=0;
long iC=0;
%}

%%

<SERV>[0-9]+		{
	serv[iserv][iC]=atol(yytext);
	iC++;
	if ( iC > SERV_COL ) {
		fprintf (stderr, "ERREUR, trop de colonnes\n");
		exit(0);
	}
	if ( iC == 2 ) { 
		serv[iserv][2] = (10*serv[iserv][1])/serv[iserv][0];
		iC++;
	}
}
<SERV>\n      { 
	iC=0;
	iserv++;
}

[+-][0-9]+	|
[0-9]+		{
	if ( rang == -1 ) {
		rang=atol(yytext);
	} else {
		emp=atol(yytext);
	}
}
\n	{
	if ( rang != -1 && emp != -1 ) {
		center[rang][emp] = 1 ;
	}
	rang = -1 ;
	emp = -1 ;
}

SERV.*\n	{
	BEGIN SERV;
}


.	;
