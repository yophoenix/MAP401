#ifndef _GEOMETRIE_2D_
#define _GEOMETRIE_2D_

#include "types_macros.h"

typedef struct Vecteur_{
    double x, y; /* coordonnes */
} Vecteur;

typedef struct Point_{
    double x, y; /* coordonnes */
} Point;

typedef struct Bezier2_{
	Point C0, C1, C2;  
} Bezier2;

typedef struct Bezier3_{
	Point C0, C1, C2, C3;
} Bezier3;

/* créer un point à partir de 2 coordonnés*/
Point set_point(double x, double y);

/* addition de 2 points*/
Point add_point(Point P1, Point P2);

/* créer un vecteur bipoint*/
Vecteur vect_bipoint(Point A, Point B);

/* addition de 2 vecteurs*/
Vecteur addition_vect(Vecteur v1, Vecteur v2);

/*multiplication de vecteur par un scalaire*/
Vecteur multiply_vect(Vecteur v1, double a);

/*multiplication d'un point par un scalaire*/
Point multiply_point(Point p1, double a);

/*produit scalaire*/
double scalaire(Vecteur v1, Vecteur v2);

/*norme d'un vecteur*/
double norme(Vecteur v1);

/*distance entre 2 points*/
double distance_point(Point p1, Point p2);

double distance_segment(Point a, Point b, Point p);

/* calcul du point C(t) d'une Bézier de degré 2, pour une valeur de t (entre 0 et 1) */
Point calcul_point_bezier2(Bezier2 B, double t);

/* calcul du point C(t) d'une Bézier de degré 3, pour une valeur de t (entre 0 et 1) */
Point calcul_point_bezier3(Bezier3 B, double t);

/* conversion d'une Bézier de degré 2 en Bézier de degré 3 */
Bezier3 conversion_bezier2_vers_3(Bezier2 B);

/* distance entre une courbe de bezier2 et un point */
double distance_bezier2(Point p, Bezier2 B, double ti);

double distance_bezier3(Point p, Bezier3 B, double ti);

#endif
