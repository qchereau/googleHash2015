/*
pour tester 
*/

#ifndef EXT
#define EXT extern
#endif

#define NB_EMPLACEMENT 100
#define NB_RANGEE 16

EXT int nR;
EXT int nE;

EXT int center[NB_RANGEE][NB_EMPLACEMENT];

#define NB_SERV 625
#define NB_GROUP 45
#define SERV_COL 6
/* colonnes : taille , capacite , utilite: rapport, groupe, rangee classement, empplacment rangee */

EXT int serv[NB_SERV][SERV_COL];

/* Capacite, ligne_dans_serv  triee decroissant sur capacite */
EXT int servSorted[NB_SERV][2];



