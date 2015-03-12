/******************************************************************************
* deplacement d'une voiture                                               *
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
	while(1){
		while(center[rangee][emplacementLibre]==1){
			emplacementLibre++;
		}
	
		for(i=1; i<tailleServeur; i++){
			if(center[rangee][emplacementLibre+i]==1){
				emplacementLibre=emplacementLibre+i+1;
				continue;
			}
		}

		return emplacementLibre;
	}
}

