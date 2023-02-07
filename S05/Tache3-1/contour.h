#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "types_macros.h"
#include "image.h"

/*---- le type Point et la fonction set_point ----*/
/* ou inclure le module de la tache 2             */
typedef struct Point_ { double x,y; } Point;

Point set_point(double x, double y);

typedef struct Cellule_Liste_Point_
{
	Point data;    /* donn�e de l'�l�ment de liste */
	struct Cellule_Liste_Point_* suiv; /* pointeur sur l'�l�ment suivant */
} Cellule_Liste_Point;

/*---- le type liste de point ----*/
typedef struct Liste_Point_
{
	unsigned int taille;        /* nombre d'�l�ments dans la liste */
	Cellule_Liste_Point *first; /* pointeur sur le premier �l�ment de la liste */
	Cellule_Liste_Point *last;  /* pointeur sur le dernier �l�ment de la liste */
	                       /* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Point;

typedef Liste_Point Contour; /* type Contour = type Liste_Point */

/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int taille; /* nombre d'�l�ments dans le tableau */
	Point *tab;          /* (pointeur vers) le tableau des �l�ments */
} Tableau_Point;

typedef enum {
	Nord,
	Est,
	Sud,
	Ouest
} Orientation;

Point trouve_pixel_init(Image I);

void calcul_contour(Image I, Point pixel_init);

void memoriser_position(Point position);

Point avancer(Point position, Orientation orientation);

Orientation nouvelle_orientation(Image I,Point position, Orientation orientation);

#endif