#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/

#define EXT 
#include "tab.h"

#define LG_SZ 50 


int main(int argc, char *argv[])

{
    long x;
    long y;
    long n;
    long c;
    char ligne[LG_SZ];
    long margin;
    int xDiff, yDiff, il, ic;
   
    //tableau utilise pour le calcul
    nL=100;
    nC=50;
    
    memset(tab,'\0',sizeof(tab));
    
    

    while ( fgets(ligne, LG_SZ, stdin) != NULL ) {    
        
        sscanf (ligne, "%ld %ld %ld %ld", &x, &y, &n, &c );
		
		
        if(n%2==0){
                //ajouter des d�tails sur la ligne d'erreur?
                printf("Crash: unable to treat a command with a square with par size %s\n", ligne );
                return -1;
        }

        margin = (n-1)/2;
        if(x-margin<0 || x+margin>=nC || y-margin<0 || y+margin>=nL){
                //ajouter des d�tails sur la ligne d'erreur?
                printf("Crash: unable to treat a command that goes beyond borders: %s\n", ligne );
                return -1;			
        }

        for( xDiff=0; xDiff<n; xDiff++){
                for( yDiff=0; yDiff<n; yDiff++){
                        tab[y-margin+yDiff][x-margin+xDiff]=c;
                }
        }
		
    }

    for ( il=0; il < nL ; il++ ) {
            for ( ic=0; ic < nC ; ic++) {
                    printf ("%ld ",tab[il][ic]);
            }
            printf ("\n");
    }

    return 0;

}