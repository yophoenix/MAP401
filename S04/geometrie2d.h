#include "types_macros.h"

typedef struct Vecteur_{
    double x, y; /* coordonnes */
} Vecteur;

typedef struct Point_{
    double x, y; /* coordonnes */
} Point;

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
double distance(Point p1, Point p2);
