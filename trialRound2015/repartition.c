/******************************************************************************
* repartition serveurs par groupes                                            *
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

void repartir_serveur(){
	int i,j;
	int treatedGroup,minValue;
	int group[NB_GROUP];
	
	memset(group,'\0',sizeof(group));
	/*iteration sur tout les serveur*/
	for(i=0; i<NB_SERV; i++){
		/*determination du groupe le moins rempli*/
		treatedGroup=0;
		minValue=group[0];
		for(j=1;j<NB_GROUP; j++){
			if(group[j]<minValue){
				treatedGroup=j;
				minValue=group[j];
			}
		}

		serv[servSorted[i][1]][3]=treatedGroup;
		group[treatedGroup] += servSorted[i][0];
	}
}


