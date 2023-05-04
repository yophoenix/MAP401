#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_

#include "geometrie2d.h"
#include "image.h"
#include "types_macros.h"

/*Dans ce fichier, les structures de liste et cellule de liste 
varie uniquement en fonction du type,
par conséquent, toute le fonctions similaires ont la même utilité à la différence du type près
*/

/*---- le type cellule de liste de point ----*/
typedef struct Cellule_Liste_Point_
{
	Point data;    /* donnée de l'élément de liste */
	struct Cellule_Liste_Point_* suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Point;

/*---- le type liste de point ----*/
typedef struct Liste_Point_
{
	unsigned int taille;		/* nombre d'éléments dans la liste */
	Cellule_Liste_Point *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Point *last;	/* pointeur sur le dernier élément de la liste */
								/* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Point;

typedef Liste_Point Contour; /* type Contour = type Liste_Point */

/*---- le type cellule de liste de contour ----*/
typedef struct Cellule_liste_contour_
{
	Contour data;
	struct Cellule_liste_contour_ *suiv;
} Cellule_Liste_Contour;

/*---- le type liste de point ----*/
typedef struct Liste_contour_
{
	UINT taille;
	Cellule_Liste_Contour *first;
	Cellule_Liste_Contour *last;
} Liste_Contour;

/*---- le type cellule de liste de bezier2 ----*/
typedef struct Cellule_Liste_Bezier2_
{
	Bezier2 data;						   /* donnée de l'élément de liste */
	struct Cellule_Liste_Bezier2_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Bezier2;

/*---- le type liste de bezier2 ----*/
typedef struct Liste_Bezier2_
{
	unsigned int taille;		  /* nombre d'éléments dans la liste */
	Cellule_Liste_Bezier2 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Bezier2 *last;  /* pointeur sur le dernier élément de la liste */
								  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Bezier2;

/*---- le type cellule de liste de contour bezier2 ----*/
typedef struct Cellule_Liste_Contour_Bezier2_
{
	Liste_Bezier2 data;							 /* donnée de l'élément de liste */
	struct Cellule_Liste_Contour_Bezier2_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Contour_Bezier2;

/*---- le type liste de contour de bezier2 ----*/
typedef struct Liste_Contour_Bezier2_
{
	unsigned int taille;				  /* nombre d'éléments dans la liste */
	Cellule_Liste_Contour_Bezier2 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Contour_Bezier2 *last;  /* pointeur sur le dernier élément de la liste */
										  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Contour_Bezier2;

/*---- le type cellule de liste de bezier3 ----*/
typedef struct Cellule_Liste_Bezier3_
{
	Bezier3 data;						 /* donnée de l'élément de liste */
	struct Cellule_Liste_Bezier3_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Bezier3;

/*---- le type liste de bezier3 ----*/
typedef struct Liste_Bezier3_
{
	unsigned int taille;		  /* nombre d'éléments dans la liste */
	Cellule_Liste_Bezier3 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Bezier3 *last;  /* pointeur sur le dernier élément de la liste */
								  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Bezier3;

/*---- le type cellule de liste de contour de bezier3 ----*/
typedef struct Cellule_Liste_Contour_Bezier3_
{
	Liste_Bezier3 data;							 /* donnée de l'élément de liste */
	struct Cellule_Liste_Contour_Bezier3_ *suiv; /* pointeur sur l'élément suivant */
} Cellule_Liste_Contour_Bezier3;

/*---- le type liste de contour de bezier3 ----*/
typedef struct Liste_Contour_Bezier3_
{
	unsigned int taille;				  /* nombre d'éléments dans la liste */
	Cellule_Liste_Contour_Bezier3 *first; /* pointeur sur le premier élément de la liste */
	Cellule_Liste_Contour_Bezier3 *last;  /* pointeur sur le dernier élément de la liste */
										  /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Contour_Bezier3;


/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int taille; /* nombre d'éléments dans le tableau */
	Point *tab;          /* (pointeur vers) le tableau des éléments */
} Tableau_Point;

/* __________________________________________________________
	créer une cellule de liste avec l'élément v 
   renvoie le pointeur sur la cellule de liste créée
   la fonction s'arrete si la création n'a pas pu se faire 
   __________________________________________________________*/

Cellule_Liste_Point *creer_element_liste_Point(Point v);

Contour supp_first_element_liste_Point(Contour c);

Cellule_Liste_Contour *creer_element_liste_Contour(Contour c);

Cellule_Liste_Bezier2 *creer_element_liste_Bezier2(Bezier2 b);

Cellule_Liste_Contour_Bezier2 *creer_element_liste_Contour_Bezier2(Liste_Bezier2 b);

Cellule_Liste_Bezier3 *creer_element_liste_Bezier3(Bezier3 b);

Cellule_Liste_Contour_Bezier3 *creer_element_liste_Contour_Bezier3(Liste_Bezier3 b);

/* __________________________________________________________
	initialisation de liste vide
   renvoie le pointeur sur la liste créée
   la fonction s'arrete si la création n'a pas pu se faire
   __________________________________________________________*/

Liste_Point creer_liste_Point_vide();

Liste_Contour creer_liste_Contour_vide();

Liste_Bezier2 creer_liste_Bezier2_vide();

Liste_Contour_Bezier2 creer_liste_Contour_Bezier2_vide();

Liste_Bezier3 creer_liste_Bezier3_vide();

Liste_Contour_Bezier3 creer_liste_Contour_Bezier3_vide();

/* __________________________________________________________
	ajout d'un élément dans la liste
   la fonction s'arrete si la création n'a pas pu se faire
   __________________________________________________________*/

void ajouter_element_liste_Point(Liste_Point *L, Point e);

void ajouter_element_liste_Contour(Liste_Contour *L, Contour e);

void ajouter_element_liste_Bezier2(Liste_Bezier2 *L, Bezier2 e);

void ajouter_element_liste_Contour_Bezier2(Liste_Contour_Bezier2 *L, Liste_Bezier2 e);

void ajouter_element_liste_Bezier3(Liste_Bezier3 *L, Bezier3 e);

void ajouter_element_liste_Contour_Bezier3(Liste_Contour_Bezier3 *L, Liste_Bezier3 e);

/* __________________________________________________________
	suppression de la liste
   __________________________________________________________*/

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Contour supprimer_liste_Contour(Liste_Contour L);

/* __________________________________________________________
	concatenation de deux listes
   __________________________________________________________*/

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2);

Liste_Bezier2 concatener_liste_Bezier2(Liste_Bezier2 L1, Liste_Bezier2 L2);

Liste_Bezier3 concatener_liste_Bezier3(Liste_Bezier3 L1, Liste_Bezier3 L2);

Liste_Contour_Bezier2 concatener_liste_Contour_Bezier2(Liste_Contour_Bezier2 L1, Liste_Contour_Bezier2 L2);

Liste_Contour_Bezier3 concatener_liste_Contour_Bezier3(Liste_Contour_Bezier3 L1, Liste_Contour_Bezier3 L2);

/* __________________________________________________________
	conversion d'un contour sous forme de liste chainée 
	vers un contour sous forme de tableau de point
   __________________________________________________________*/
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

#endif
