#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_

#include "geometrie2d.h"
#include "image.h"
#include "types_macros.h"

/*---- le type cellule de liste de point ----*/
typedef struct Cellule_Liste_Point_
{
	Point data;    /* donnée de l'élément de liste */
	struct Cellule_Liste_Point_* suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Point;

typedef struct Cellule_Liste_Bezier2_
{
	Bezier2 data;						   /* donnée de l'élément de liste */
	struct Cellule_Liste_Bezier2_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Bezier2;

typedef struct Cellule_Liste_Bezier3_
{
	Bezier3 data;						 /* donnée de l'élément de liste */
	struct Cellule_Liste_Bezier3_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Bezier3;

/*---- le type liste de point ----*/
typedef struct Liste_Point_
{
	unsigned int taille;        /* nombre d'éléments dans la liste */
	Cellule_Liste_Point *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Point *last;  /* pointeur sur le dernier élément de la liste */
	                       /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Point;

typedef struct Liste_Bezier2_
{
	unsigned int taille;		/* nombre d'éléments dans la liste */
	Cellule_Liste_Bezier2 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Bezier2 *last;	/* pointeur sur le dernier élément de la liste */
								/* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Bezier2;

typedef struct Liste_Bezier3_
{
	unsigned int taille;		  /* nombre d'éléments dans la liste */
	Cellule_Liste_Bezier3 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Bezier3 *last;  /* pointeur sur le dernier élément de la liste */
								  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Bezier3;

typedef struct Cellule_Liste_Contour_Bezier2_
{
	Liste_Bezier2 data;						   /* donnée de l'élément de liste */
	struct Cellule_Liste_Contour_Bezier2_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Contour_Bezier2;

typedef struct Cellule_Liste_Contour_Bezier3_
{
	Liste_Bezier3 data;							 /* donnée de l'élément de liste */
	struct Cellule_Liste_Contour_Bezier3_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Contour_Bezier3;

typedef struct Liste_Contour_Bezier2_
{
	unsigned int taille;		/* nombre d'éléments dans la liste */
	Cellule_Liste_Contour_Bezier2 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Contour_Bezier2 *last;	/* pointeur sur le dernier élément de la liste */
								/* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Contour_Bezier2;

typedef struct Liste_Contour_Bezier3_
{
	unsigned int taille;				  /* nombre d'éléments dans la liste */
	Cellule_Liste_Contour_Bezier3 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Contour_Bezier3 *last;  /* pointeur sur le dernier élément de la liste */
										  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Contour_Bezier3;

typedef Liste_Point Contour; /* type Contour = type Liste_Point */

typedef struct Cellule_liste_contour_{
	Contour data;
	struct Cellule_liste_contour_ *suiv;
} Cellule_Liste_Contour;

typedef struct Liste_contour_{
	UINT taille;
	Cellule_Liste_Contour * first;
	Cellule_Liste_Contour * last;
} Liste_Contour;

/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int taille; /* nombre d'éléments dans le tableau */
	Point *tab;          /* (pointeur vers) le tableau des éléments */
} Tableau_Point;

/* créer une cellule de liste avec l'élément v 
   renvoie le pointeur sur la cellule de liste créée
   la fonction s'arrete si la création n'a pas pu se faire */
Cellule_Liste_Point *creer_element_liste_Point(Point v);

Contour supp_first_element_liste_Point(Contour c);

Cellule_Liste_Contour *creer_element_liste_Contour(Contour c);

Cellule_Liste_Bezier2 *creer_element_liste_Bezier2(Bezier2 b);

Cellule_Liste_Contour_Bezier2 *creer_element_liste_Contour_Bezier2(Liste_Bezier2 b);

Cellule_Liste_Bezier3 *creer_element_liste_Bezier3(Bezier3 b);

Cellule_Liste_Contour_Bezier3 *creer_element_liste_Contour_Bezier3(Liste_Bezier3 b);

Liste_Point creer_liste_Point_vide();

Liste_Contour creer_liste_Contour_vide();

Liste_Bezier2 creer_liste_Bezier2_vide();

Liste_Contour_Bezier2 creer_liste_Contour_Bezier2_vide();

Liste_Bezier3 creer_liste_Bezier3_vide();

Liste_Contour_Bezier3 creer_liste_Contour_Bezier3_vide();

void ajouter_element_liste_Point(Liste_Point *L, Point e);

void ajouter_element_liste_Contour(Liste_Contour *L, Contour e);

void ajouter_element_liste_Bezier2(Liste_Bezier2 *L, Bezier2 e);

void ajouter_element_liste_Contour_Bezier2(Liste_Contour_Bezier2 *L, Liste_Bezier2 e);

void ajouter_element_liste_Bezier3(Liste_Bezier3 *L, Bezier3 e);

void ajouter_element_liste_Contour_Bezier3(Liste_Contour_Bezier3 *L, Liste_Bezier3 e);

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Contour supprimer_liste_Contour(Liste_Contour L);

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2);

Liste_Bezier2 concatener_liste_Bezier2(Liste_Bezier2 L1, Liste_Bezier2 L2);

Liste_Bezier3 concatener_liste_Bezier3(Liste_Bezier3 L1, Liste_Bezier3 L2);

Liste_Contour_Bezier2 concatener_liste_Contour_Bezier2(Liste_Contour_Bezier2 L1, Liste_Contour_Bezier2 L2);

Liste_Contour_Bezier3 concatener_liste_Contour_Bezier3(Liste_Contour_Bezier3 L1, Liste_Contour_Bezier3 L2);

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

#endif
