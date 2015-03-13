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
    int i,j,iserv;
    int serverTraite;
    int groupeRange[NB_RANGEE][NB_GROUP];	
    int dernierTraite;
    int line, group;
    int localisation;
    int rangee;
    int emplacement;
    int bestRange;
    int hasAddedAnElement;

    memset(groupeRange,'\0',sizeof(groupeRange));
    hasAddedAnElement=1;
    serverTraite=1;
    for(i=0; i<NB_RANGEE; i++){
            rangeeFilling[i] = remplissage_rangee(i);
    }

    for(iserv=0; iserv<NB_SERV; iserv++){
        line=servSortedU[iserv][1];
        group=serv[line][3];

        rangee=-1;
        bestRange=1000000;
        for(j=0; j<NB_RANGEE; j++) {
            if(rangeeFilling[j]<bestRange && groupeRange[j][group]==0){
                bestRange=rangeeFilling[j];
                rangee=j;
            }
        }

        if(rangee!=-1){
            serv[line][4]=rangee;
            serv[line][5]=prochain_emplacement_libre(rangee,serv[line][0]);

            if(serv[line][5] != -1 ) {
                groupeRange[rangee][group]=1;
                emplacement=serv[line][5];
                for ( j=0; j< serv[line][0]; j++ ){
                    center[rangee][emplacement+j]=1;
                }
                rangeeFilling[rangee] += serv[line][0];
                /* 
                 * fprintf (stderr,"%d %d ,%d  group %d, serv %d  taille %d \n", rangee, serv[line][5],emplacement+j-1, group, line ,  serv[line][0] ); 
                 */
            }

        }else{
                serv[line][4]=rangee;
                serv[line][5]=-1;                
        }
    }
}
