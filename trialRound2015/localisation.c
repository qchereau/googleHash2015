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
	while(1){
		while(center[rangee][emplacementLibre]==1){
			if(emplacementLibre==SERV_COL){
				return -1;
			}
			emplacementLibre++;
		}
	
		for(i=1; i<tailleServeur; i++){
			if(center[rangee][emplacementLibre+i]==1){
				emplacementLibre=emplacementLibre+i+1;
				if(emplacementLibre>=SERV_COL){
					return -1;
				}
				continue;
			}
		}

		return emplacementLibre;
	}
}

/*renvoi le nombre de cases pleines*/
int remplissage_rangee(int rangee){
	int result;
	int i;
	result=0;
	for(i=0; i<SERV_COL; i++){
		if(center[rangee][i]==1){
			result++;
		}
	}
	return result;
}
