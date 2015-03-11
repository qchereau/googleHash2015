/*************************************************************************
*
* Fichier          : lch.h
*
*************************************************************************/

#ifndef LCH_H
#define LCH_H

#define OK   0
#define ERR -1

/***********************************************************/
/* conditions d'arret pour le balayage de la liste chainee */
#define LISTE_ARRET   2
#define LISTE_DETRUIT 3
#define LISTE_ARRDETR 4
#define LISTE_INSERE  5
#define LISTE_AJOUTE  6

/* structure des elements chaines */
typedef struct noeud 
{
  char *chaine;
  struct noeud *ptsuivant;
} liste_chainee;

/* prototype des fonctions de gestion des listes chainees */
extern int  lch_enfiler(liste_chainee**  ,char*  ,long unsigned int);
extern void lch_depiler(liste_chainee** );
extern void lch_detruire_file(liste_chainee** );
extern int  lch_traiter_file(liste_chainee**  ,int fct());
extern int  lch_controler_file(liste_chainee**  ,int fct());

#endif	/* LCH_H */

