#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"

typedef struct Point_ {
	double x , y ; /* coordonnees */
} Point ;

typedef enum {Nord, Est, Sud, Ouest} Orientation;

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

Liste_Point creer_liste_Point_vide();

void ajouter_element_liste_Point(Liste_Point *L, Point e);

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

void ecrire_contour_fichier(Liste_Point L,char *nom_fichier);

/* cree le point de coordonnees ( x , y ) */
Point set_point ( double x , double y ) ;

Contour recupere_contour(Image I, Point pixel_init);

void calcul_contour(Contour liste);

//Point trouver_pixel_depart(Image I);

void memoriser_position(Liste_Point *liste, Point p);

Point avancer(Point p, Orientation orient);

Orientation nouvelle_orientation (Image I, Point position, Orientation orient);

Orientation tourner_a_gauche(Orientation orient);

Orientation tourner_a_droite(Orientation orient);

#endif
