#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/
#include "tab.h"


/* array_data devenu tab 
   count_rows_white -> count_cells_white */

int detecter_champ() { 
    int array_rows[3];
    int array_columns[3];
    int count_cells_white;
    int peindre;
    int i,j,k,g,l,c,d;

    for(i = 0; i< nL-3 /* 97 */  ; i++){
        for (j = 0; j<nC-3 /*47*/ ; j++){
            peindre = 0;
            count_cells_white = 0;
            array_rows[0]=-1;
            array_rows[1]=-1;
            array_rows[2]=-1;
            
            for(k=i; k<i+3; k++){
                for(g=j; g<j+3; g++){
                    if(tab[k][g] /* %2 moins bon */  == 1){
                        peindre = peindre + 1;
                    } else if ( tab[k][g]%2 == 0 ){
                        array_rows[count_cells_white] = k;
                        array_columns[count_cells_white] = g;
                        count_cells_white = count_cells_white + 1;
                        if ( count_cells_white >2 ) {
                            /* passer au carre 3x3 suivant et array_rows taille 3 */
                            k=i+4;
                            g=j+4;
                        }
                    }
                }
            }
            if(peindre >= 6){
                // Send Instruction to robot
                printf("%d %d %d %d\n",j+1,i+1,3,1);
                for(l=0; l<3; l++){
                    if(array_rows[l] > -1){
                        printf("%d %d %d %d\n",array_columns[l],array_rows[l],1,0);
                    }
                }
                for (c=i; c< i+3; c++ ){
                    for(d=j; d<j+3; d++){
                        tab[c][d] += 2;
                    }
                }
            }	
        }
    }
    return (1);
    
}

