/*
*
* Fichier          : lch.c
* Description      : Gestion des listes chainees en memoire du processus
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "lch.h"


extern int lch_enfiler(liste_chainee ** racine, char * donnee, long unsigned int taille)
/* liste_chainee     **racine;		point d'entree de la liste */
/* char           *donnee;		nom a ajouter en fin de liste */
/* sizeof           taille;		taille de la chaine a enfiler */
{
  /* ajoute l'element donnee en fin de file */
  liste_chainee      *ptr_noeud;
  liste_chainee      *ptr_nouveau;

  /* allouer la place requise pour le chainage */
  ptr_nouveau = (liste_chainee *) malloc(sizeof(liste_chainee));
  if (ptr_nouveau == NULL) {
    fprintf( stderr, 
	    "impossibilite d'allouer la place memoire suivante : %ld\n",
	    sizeof(liste_chainee));
    return (ERR);
  }
  ptr_nouveau->ptsuivant = NULL;
  /* allouer la place requise pour le nouvel element */
  ptr_nouveau->chaine = malloc(taille);
  if (ptr_nouveau->chaine == NULL) {
    free(ptr_nouveau);
    fprintf( stderr,
	    "impossibilite d'allouer la place memoire suivante : %ld\n",
	     taille);
    return (ERR);
  }
  /* Stocker l'element */
  memcpy(ptr_nouveau->chaine, donnee, taille);

  /* etablir le chainage */
  if (*racine == NULL)
    *racine = ptr_nouveau;
  else {
    ptr_noeud = *racine;
    while (ptr_noeud->ptsuivant != NULL)
      ptr_noeud = ptr_noeud->ptsuivant;
    ptr_noeud->ptsuivant = ptr_nouveau;
  }

  return (OK);
}

/*---------------------------------------------------------------------*/

extern void  lch_depiler(liste_chainee ** racine)
/* liste_chainee     **racine;		point d'entree de la liste */
{
  liste_chainee      *ptr_noeud;

  /* Recuperer le pointeur de debut de liste */
  ptr_noeud = *racine;
  if (ptr_noeud == NULL)
    return;
  /* Desallouer la place requise pour l'element a depiler */
  free(ptr_noeud->chaine);
  *racine = ptr_noeud->ptsuivant;
  /* Desallouer la place requise pour le chainage */
  free(ptr_noeud);
  return;
}

/*---------------------------------------------------------------------*/

extern void lch_detruire_file(liste_chainee ** racine)
/* liste_chainee     **racine;		point d'entree de la liste */
{
  liste_chainee      *ptr_noeud;

  /* Recuperer le pointeur de debut de liste */
  ptr_noeud = *racine;

  /* boucler tantque la fin de liste n'est pas atteinte */
  while (ptr_noeud != NULL) {
    /* Desallouer la place requise pour l'element a depiler */
    free(ptr_noeud->chaine);
    *racine = ptr_noeud->ptsuivant;
    /* Desallouer la place requise pour le chainage */
    free(ptr_noeud);
    ptr_noeud = *racine;
  }
  return;
}

/*---------------------------------------------------------------------*/

extern int lch_traiter_file(liste_chainee ** racine, int  fct() )
/* liste_chainee  **racine;	point d'entree de la liste */
/* int        fct();	fonction a appliquer a chaque element de la liste */
{
  liste_chainee      *ptr_noeud;
  int             Li_ret;

  /* Recuperer le pointeur de debut de liste */
  ptr_noeud = *racine;

  /* boucler tantque la fin de liste n'est pas atteinte */
  while (ptr_noeud != NULL) {
    /* Appliquer le traitement sur l'element de la liste */
    Li_ret = (int) fct (ptr_noeud->chaine);
    if (Li_ret != OK)
      return (LISTE_ARRET);
    ptr_noeud = ptr_noeud->ptsuivant;
  }
  return (OK);
}

/*---------------------------------------------------------------------*/

extern int lch_controler_file(liste_chainee ** racine, int fct() )
/* liste_chainee  **racine;	point d'entree de la liste */
/* int        fct();	fonction a appliquer a chaque element de la liste */
{
  liste_chainee      *ptr_noeud;
  liste_chainee      *ptr_chainage = NULL;
  int             Li_ret;

  /* Recuperer le pointeur de debut de liste */
  ptr_noeud = *racine;

  /* Boucler tantque la fin de liste n'est pas atteinte */
  while (ptr_noeud != NULL) {
    /* Appliquer le traitement sur l'element de la liste */
    Li_ret = (int) fct (ptr_noeud->chaine);
    switch (Li_ret) {
      case LISTE_ARRDETR:
	/* Detruire l'element de la liste et sortir de la boucle */

	/* Desallouer la place requise pour l'element a depiler */
	free(ptr_noeud->chaine);
	/* Reaffecter la racine si le premier element est detruit */
	if (ptr_chainage == NULL) {
	  *racine = ptr_noeud->ptsuivant;
	  /* Desallouer la place requise pour le chainage */
	  free(ptr_noeud);
	} else {
	  /* reconstruire le chainage */
	  ptr_chainage->ptsuivant = ptr_noeud->ptsuivant;
	  /* Desallouer la place requise pour le chainage */
	  free(ptr_noeud);
	}
	return (LISTE_ARRDETR);

      case LISTE_DETRUIT:
	/* Detruire l'element de la liste et continuer la boucle */

	/* Desallouer la place requise pour l'element a depiler */
	free(ptr_noeud->chaine);
	/* Reaffecter la racine si le premier element est detruit */
	if (ptr_chainage == NULL) {
	  *racine = ptr_noeud->ptsuivant;
	  /* Desallouer la place requise pour le chainage */
	  free(ptr_noeud);
	  /* pointer sur l'element suivant */
	  ptr_noeud = *racine;
	} else {
	  /* reconstruire le chainage */
	  ptr_chainage->ptsuivant = ptr_noeud->ptsuivant;
	  /* Desallouer la place requise pour le chainage */
	  free(ptr_noeud);
	  /* pointer sur l'element suivant */
	  ptr_noeud = ptr_chainage->ptsuivant;
	}
	break;

      case LISTE_ARRET:
	/* arrete le traitement sans desallouer */
	return (LISTE_ARRET);

      case OK:
	/* Continuer a balayer la liste */
	/* sauvegarde du pointeur precedent pour le nouveau chainage en */
	/* cas de destruction d'un element */
	ptr_chainage = ptr_noeud;
	/* pointer sur l'element suivant */
	ptr_noeud = ptr_noeud->ptsuivant;
	break;

      default:
	fprintf( stderr, "code d'erreur fonction inconnu : %d\n", Li_ret);
    }
  }
  return (Li_ret);
}

