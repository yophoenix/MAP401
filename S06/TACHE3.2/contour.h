#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"
#include "liste_chainee.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

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
