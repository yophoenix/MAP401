#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"
#include "liste_chainee.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

/* cree le point de coordonnees ( x , y ) */
Point set_point ( double x , double y ) ;

Contour recupere_contour(Image I, Image *M, Point pixel_init);

void calcul_contour(Contour liste);

void affiche_liste_contour(Liste_Contour liste){

Point trouve_pixel_init(Image I);

void memoriser_position(Liste_Point *liste, Point p);

Point avancer(Point p, Orientation orient);

Orientation nouvelle_orientation (Image I, Point position, Orientation orient);

Orientation tourner_a_gauche(Orientation orient);

Orientation tourner_a_droite(Orientation orient);

void ecrire_contour_fichier(Contour L,FILE * f);

void ecrire_liste_contours(Liste_Contour L, char *nom_fichier);

void ecrire_contour_eps(Contour L, char *nom_fichier, Image I, int fill);

char *modifier_extension(char *nom,char *extension);

char *stroke_ou_fill(char* nom,int fill);

Image init_masque(Image M);

Liste_Contour extraire_les_contours(Image I);

#endif
