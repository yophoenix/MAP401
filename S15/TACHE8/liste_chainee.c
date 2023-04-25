#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "contour.h"

/* créer une cellule de liste avec l'élément v 
   renvoie le pointeur sur la cellule de liste créée
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule_Liste_Point *creer_element_liste_Point(Point v)
{
	Cellule_Liste_Point *el;
	el = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point));
	if (el==NULL)
	{
		fprintf(stderr, "creer_element_liste_Point : allocation impossible\n");
		exit(-1);
	}
	el->data = v;
	el->suiv = NULL;
	return el;
}

Contour supp_first_element_liste_Point(Contour c)
{
	if (c.first==NULL){
		printf("impossible de supprimer l'element, le contour est vide");
		return c;
	}
	Cellule_Liste_Point *first = c.first;
	Cellule_Liste_Point *second = first->suiv;
	c.first = second;
	c.taille -= 1;
	free(first);
	return c;
}

Cellule_Liste_Contour *creer_element_liste_Contour(Contour c)
{
	Cellule_Liste_Contour *co;
	co = (Cellule_Liste_Contour *)malloc(sizeof(Cellule_Liste_Contour));
	if (co==NULL)
	{
		fprintf(stderr, "creer_element_liste_Contour : allocation impossible\n");
		exit(-1);
	}
	co->data = c;
	co->suiv = NULL;
	return co;
}


/* créer une liste vide */
Liste_Point creer_liste_Point_vide()
{
	Liste_Point L = {0, NULL, NULL};
	return L;
}

Liste_Contour creer_liste_Contour_vide()
{
	Liste_Contour C = {0, NULL, NULL};
	return C;
}

/* ajouter l'élément e en fin de la liste L, renvoie la liste L modifiée */
void ajouter_element_liste_Point(Liste_Point *L, Point e)
{
	Cellule_Liste_Point *el;
	
	el = creer_element_liste_Point(e);
	if (L->taille == 0)
	{
		/* premier élément de la liste */
		L->first = L->last = el;
	}
	else
	{
		L->last->suiv = el;
		L->last = el;
	}
	L->taille++;
}

void ajouter_element_liste_Contour(Liste_Contour *C, Contour e)
{
	Cellule_Liste_Contour *co;
	
	co = creer_element_liste_Contour(e);
	if (C->taille == 0)
	{
		/* premier élément de la liste */
		C->first = C->last = co;
	}
	else
	{
		C->last->suiv = co;
		C->last = co;
	}
	C->taille++;
}

/* suppression de tous les éléments de la liste, renvoie la liste L vide */
Liste_Point supprimer_liste_Point(Liste_Point L)
{
	Cellule_Liste_Point *el=L.first;
	
	while (el) 
	{		
		Cellule_Liste_Point *suiv=el->suiv;
		free(el);
		el = suiv;
	}
	L.first = L.last = NULL; L.taille = 0;
	return L;
}

Liste_Contour supprimer_liste_Contour(Liste_Contour C)
{
	Cellule_Liste_Contour *co=C.first;
	
	while (co) 
	{		
		Cellule_Liste_Contour *suiv=co->suiv;
		free(co);
		co = suiv;
	}
	C.first = C.last = NULL; C.taille = 0;
	return C;
}

/* concatène L2 à la suite de L1, renvoie la liste L1 modifiée */
Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2)
{
	/* cas où l'une des deux listes est vide */
	if (L1.taille == 0) return L2; 
	if (L2.taille == 0) return L1;
	
	/* les deux listes sont non vides */
	L1.last->suiv = L2.first; /* lien entre L1.last et L2.first */
	L1.last = L2.last;        /* le dernier élément de L1 est celui de L2 */
	L1.taille += L2.taille;   /* nouvelle taille pour L1 */
	return L1;
}

Liste_Contour concatener_liste_Contour(Liste_Contour C1, Liste_Contour C2)
{
	/* cas où l'une des deux listes est vide */
	if (C1.taille == 0) return C2; 
	if (C2.taille == 0) return C1;
	
	/* les deux listes sont non vides */
	C1.last->suiv = C2.first; /* lien entre C1.last et C2.first */
	C1.last = C2.last;        /* le dernier élément de C1 est celui de C2 */
	C1.taille += C2.taille;   /* nouvelle taille pour C1 */
	return C1;
}

/* créer une séquence de points sous forme d'un tableau de points 
   à partir de la liste de points L */
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L)
{
	Tableau_Point T;
	
	/* taille de T = taille de L */
	T.taille = L.taille;
	
	/* allocation dynamique du tableau de Point */
	T.tab = malloc(sizeof(Point) * T.taille);
	if (T.tab == NULL)
	{
		/* allocation impossible : arret du programme avec un message */
		fprintf(stderr, "sequence_points_liste_vers_tableau : ");
		fprintf(stderr, " allocation impossible\n");
		exit(-1);
	}
	
	/* remplir le tableau de points T en parcourant la liste L */
	int k = 0; /* indice de l'élément dans T.tab */
	Cellule_Liste_Point *el = L.first; /* pointeur sur l'élément dans L */
	while (el) 
	{
		T.tab[k] = el->data;
		k++; /* incrémenter k */
		el = el->suiv; /* passer à l'élement suivant dans la liste chainee */
	}
	
	return T;
}
