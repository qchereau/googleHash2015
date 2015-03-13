/******************************************************************************
* localisation                                               *
*                                                                             *
*******************************************************************************/

/*-------------+
|Include Files |
+-------------*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


/*--------------------------------+
| Variables globales au programme |
+--------------------------------*/

#include "tab.h"

int prochain_emplacement_libre( int rangee, int tailleServeur)
{
	int emplacementLibre;
	int i, emplacementValide; 
	emplacementLibre=0;
	i=0;
	while(i<tailleServeur){
		while(center[rangee][emplacementLibre]==1){
			emplacementLibre++;
			if(emplacementLibre==NB_EMPLACEMENT){
				return -1;
			}
		}

		if ( emplacementLibre + tailleServeur -1  >= NB_EMPLACEMENT){
                        return -1;
                }

	
		for(i=0; i<tailleServeur; i++){
			if(center[rangee][emplacementLibre+i]==1){
				emplacementLibre=emplacementLibre+i+1;
				if(emplacementLibre>=NB_EMPLACEMENT){
					return -1;
				}
				i=0;
				break;
			}
		}
	}
	return emplacementLibre;
}

/*renvoi le nombre de cases pleines*/
int remplissage_rangee(int rangee){
	int result;
	int i;
	result=0;
	for(i=0; i<NB_EMPLACEMENT; i++){
		if(center[rangee][i]==1){
			result++;
		}
	}
	return result;
}
