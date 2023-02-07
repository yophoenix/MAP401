#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "contour.h"

Point set_point (double x , double y)
{
	Point P = {x , y};
	return P;
}

Contour recupere_contour(Image I, Point pixel_init){
	Liste_Point liste = creer_liste_Point_vide();
	Point pos_init=set_point(pixel_init.x - 1, pixel_init.y - 1);
	Point position=set_point(pos_init.x,pos_init.y);
	Orientation orient=Est;
	bool boucle=true;
	while (boucle){
		memoriser_position(&liste,position);
		position = avancer(position,orient);
		orient = nouvelle_orientation(I,position,orient);
		if (position.x == pos_init.x && position.y == pos_init.y && orient==Est){
			boucle=false;
		}
	}
	memoriser_position(&liste,position);
	return liste;
}

void calcul_contour(Contour liste){
	printf("Ce contour contient %d segments.\n",liste.taille-1);
}

void memoriser_position(Liste_Point *liste, Point p){
	ajouter_element_liste_Point(liste,p);
}

Point avancer(Point p, Orientation orient){
	switch (orient){
		case Nord:
			p.y--;
			break;
		case Est:
			p.x++;
			break;
		case Sud:
			p.y++;
			break;
		case Ouest:
			p.x--;
			break;
	}
	return p;
}

Orientation nouvelle_orientation(Image I,Point position, Orientation orient){
	Pixel pD;
	Pixel pG;
	switch (orient){
		case Nord:
			pD = get_pixel_image(I, position.x + 1, position.y);
			pG = get_pixel_image(I, position.x, position.y);
			break;
		case Est:
			pD = get_pixel_image(I, position.x + 1, position.y + 1);
			pG = get_pixel_image(I, position.x + 1, position.y);
			break;
		case Sud:
			pD = get_pixel_image(I, position.x, position.y + 1);
			pG = get_pixel_image(I, position.x + 1, position.y + 1);
			break;
		case Ouest:
			pD = get_pixel_image(I, position.x, position.y);
			pG = get_pixel_image(I, position.x, position.y + 1);
			break;
	}
	if (pG){
		orient = (orient - 1) % 4;
	}
	else if (!pD){
		orient = (orient + 1) % 4;
	}
	return orient;
}

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
/* créer une liste vide */
Liste_Point creer_liste_Point_vide()
{
	Liste_Point L = {0, NULL, NULL};
	return L;
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

/* écrire le contour L dans un fichier */ 
void ecrire_contour_fichier(Liste_Point L,char* nom_fichier)
{
	FILE *f=fopen(nom_fichier,"w");
	Tableau_Point TP = sequence_points_liste_vers_tableau(L);
	int k;
	int nP = TP.taille;
	
	fprintf(f,"1\n\n%d\n",nP);
	for (k = 0; k < nP; k++)
	{	
		Point P = TP.tab[k]; /* récupérer le point d'indice k */
		fprintf(f," %5.1f %5.1f\n", P.x, P.y);
	} 
	
	free(TP.tab); /* supprimer le tableau de point TP */
	fclose(f);
}
