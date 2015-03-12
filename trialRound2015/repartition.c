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

int servers_capacity[M];
int servers_size[M];

int utility[M];
int group_utility[P];


int servers_order_by_utility_desc[M];
Array groups[P]

p = 0
for(m=0; m<M; m++){
    groups[p].push(m)
    p = p + 1 mod P
}
for(p=0; p<P; p++){
    group_utility[p] = 0;
    for(m=0; m< groups[p].length; m++) {
        group_utility[p] += group_utility[p] + utility[groups[p][m]];
    }
}

# TODO: remplir le tableau
int groups_order_by_group_utility_desc[P]

group_id_max = groups_order_by_group_utility_desc[0]
group_id_min = groups_order_by_group_utility_desc[-1]






#######################################################################

Soit M les serveurs à allouer sous forme m = (c, s, u) avec u utilité = c / s
Soit P les groupes
Soit Up l'utilité du groupe p
M = sorted(M, key = u desc)
p = P[0]
for m in M:
    ajouter m à p
    p = suivant dans P
for p in P:
    Up = sum(u for m in p)
soit pmax tq Upmax = (max Up for p in P)
soit pmin tq Upmin = (min Up for p in P)

soit m tq (u - (Upmax - Upmin)) minimal:
    retirer m de pmax
    ajouter m à pmin

REPETER TANT QUE Upmax - Upmin est stable sur X itérations avec X le nombre de groupes

soit pmax tq Spmax = (max sum(s for m in p) for p in P)

for p in P par S croissante:
    trouver les m à capacité égale entre p et pmax
    echanger si la taille de celui de pmax est plus grande que celui de p et si la nouvelle taille de p reste plus petite que la nouvelle de pmax

REPETER TANT QUE Spmax - Spmin est stable sur X itérations avec X le nombre de groupes

A refaire avec des sommes de serveurs

