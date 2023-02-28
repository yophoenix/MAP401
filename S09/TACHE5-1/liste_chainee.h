#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_

#include "image.h"
#include "types_macros.h"

typedef struct Point_ {
	double x , y ; /* coordonnees */
} Point ;

/*---- le type cellule de liste de point ----*/
typedef struct Cellule_Liste_Point_
{
	Point data;    /* donnée de l'élément de liste */
	struct Cellule_Liste_Point_* suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Point;

/*---- le type liste de point ----*/
typedef struct Liste_Point_
{
	unsigned int taille;        /* nombre d'éléments dans la liste */
	Cellule_Liste_Point *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Point *last;  /* pointeur sur le dernier élément de la liste */
	                       /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Point;

typedef Liste_Point Contour; /* type Contour = type Liste_Point */

typedef struct Cellule_liste_contour_{
	Contour data;
	struct Cellule_liste_contour_ *suiv;
} Cellule_Liste_contour;

typedef struct Liste_contour_{
	UINT taille;
	Cellule_Liste_contour * first;
} Liste_contour;

/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int taille; /* nombre d'éléments dans le tableau */
	Point *tab;          /* (pointeur vers) le tableau des éléments */
} Tableau_Point;

typedef struct Cellule_liste_contour_
{
	Contour data;
	struct Cellule_liste_contour_ *suiv;
} Cellule_Liste_contour;

typedef struct Liste_contour_
{
	UINT taille;
	Cellule_liste_contour_ *first;
} Liste_contour;

/* créer une cellule de liste avec l'élément v 
   renvoie le pointeur sur la cellule de liste créée
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule_Liste_Point *creer_element_liste_Point(Point v);

Liste_Point creer_liste_Point_vide();

void ajouter_element_liste_Point(Liste_Point *L, Point e);

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

/* cree le point de coordonnees ( x , y ) */
Point set_point ( double x , double y ) ;

#endif
