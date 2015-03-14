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

void repartir_serveur_gros(){
    int i,j;
    int treatedGroup,minValue;
    int group[NB_GROUP];
    int cible;

    memset(group,'\0',sizeof(group));
    cible=410;
    /*iteration sur tout les serveurs par capacite decroisante */
    /* ranger d'abord les gros avec utilite > 80 */
    i=0; 
    treatedGroup=0;
    while ( treatedGroup<NB_GROUP && i<NB_SERV && serv[servSorted[i][1]][1] > CapRangeImpose ) {
        if( serv[servSorted[i][1]][2] > 80 ) {
            serv[servSorted[i][1]][3]=treatedGroup;
            group[treatedGroup] += servSorted[i][0];
            if ( group[treatedGroup] > cible ) treatedGroup++;
        }
        i++;
    }
        
    while ( i<NB_SERV ){
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
        i++;
    }
}

