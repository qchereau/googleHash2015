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

int rangeeFilling[NB_RANGEE];

void localiser_serveur(){
	int i,j;
	int serverTraite;
	int groupeRange[NB_RANGEE][NB_GROUP];	
	int dernierTraite;
	int line;
	int localisation;
	int rangee;
	int bestRangee;
	int hasAddedAnElement;

	memset(groupeRange,'\0',sizeof(groupeRange));
	hasAddedAnElement=1;
	serverTraite=1;
	for(i=0; i<NB_RANGEE; i++){
		rangeeFilling[i] = remplissage_rangee(i);
	}
	
	while(hasAddedAnElement){
		hasAddedAnElement=0;
		for(i=0; i<NB_GROUP; i++){
			dernierTraite=0;
			line=0;
			while(dernierTraite!=serverTraite && server[serverSortedU[line][1]][3]==i){
				if(server[serverSortedU[line][1]][3]==i){
					dernierTraite++;
				}
				line++;
				if(line>NB_SERVER){
					break;
				}
			}

			if(line>NB_SERVER){
				continue;
			}

			hasAddedAnElement=1;
			rangee=-1;
			bestRange=1000000;
			for(j=1; j<NB_RANGEE; j++){
				if(rangeeFilling[j]<bestRange && groupeRange[j][i]){
					bestRange=rangeeFilling[j];
					rangee=j;
				}
			}			
			
			if(rangee!=-1){
				groupeRange[rangee][i]=1;
				server[serverSortedU[line][1]][4]=rangee;
				server[serverSortedU[line][1]][5]=prochain_emplacement_libre(rangee,server[serverSortedU[line][1]][5]);
			}else{
				server[serverSortedU[line][1]][4]=rangee;
				server[serverSortedU[line][1]][5]=-1;				
			}
		}
		serverTraite++;
	}
}


