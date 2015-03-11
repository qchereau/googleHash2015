#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/
#include "tab.h"
#include "lch.h"

extern liste_chainee *racine;

void identifier_champ() { 
    int count_cells_white;
    int peindre;
    int i,j,k,g;
    long cell_l_c[3];
    
    for(i = 0; i< nL-3 /* 97 */  ; i++){
        for (j = 0; j<nC-3 /*47*/ ; j++){
            peindre = 0;
            count_cells_white = 0;
                    
            for(k=i; k<i+3; k++){
                for(g=j; g<j+3; g++){
                    if(tab[k][g] /* %2 moins bon */  == 1){
                        peindre = peindre + 1;
                   /* } else if ( tab[k][g]%2 == 0 ){
                        count_cells_white = count_cells_white + 1;
                        if ( count_cells_white >2 ) {
                            /* passer au carre 3x3 suivant et verifier pour 6 * /
                            k=i+4;
                            g=j+4;
                        } */
                    }
                }
            }
            if(peindre >= 5){
                // store cell in chained list
                cell_l_c[0]=i;
                cell_l_c[1]=j;
                cell_l_c[2]=peindre;
                lch_enfiler(&racine, (char *) &cell_l_c, sizeof(cell_l_c) );
            }	
        }
    }
    return;
    
}

