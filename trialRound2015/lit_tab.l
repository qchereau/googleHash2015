%START SERV  CAP  UTIL

%{ 
#include "tab.h"

long rang=-1;
long emp=-1;
long iserv=0;
long iC=0;
%}

%%

<SERV>[0-9]+            {
        serv[iserv][iC]=atol(yytext);
        iC++;
        if ( iC > SERV_COL ) {
                fprintf (stderr, "ERREUR, trop de colonnes\n");
                exit(0);
        }
}
<SERV>\n      {
        if ( iC == 2 ) {
                serv[iserv][2] = (10*serv[iserv][1])/serv[iserv][0];
		// if ( serv[iserv][0] >= 5 ) serv[iserv][2] = 0;
        }
        iC=0;
        iserv++;
}

<CAP>[0-9]+	{
	servSorted[iserv][iC]=atol(yytext);
	iC++;
}
<CAP>\n      { 
	iC=0;
	iserv++;
}

<UTIL>[0-9]+     {
        servSortedU[iserv][iC]=atol(yytext);
        iC++;
}
<UTIL>\n      { 
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
	iserv=0;
	iC=0;
	BEGIN SERV;
}

CAP.*\n        {
	iserv=0;
	iC=0;
        BEGIN CAP;
}

UTIL.*\n        {
	iserv=0;
	iC=0;
        BEGIN UTIL;
}

.	;
