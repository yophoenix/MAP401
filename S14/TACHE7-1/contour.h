#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"
#include "liste_chainee.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

Contour recupere_contour(Image I, Image M, Point pixel_init);

void calcul_contour(Contour liste);

void affiche_liste_contour(Liste_Contour liste);

Point trouve_pixel_init(Image I, Point pixel);

void memoriser_position(Liste_Point *liste, Point p);

Point avancer(Point p, Orientation orient);

Orientation nouvelle_orientation (Image I, Point position, Orientation orient);

Orientation tourner_a_gauche(Orientation orient);

Orientation tourner_a_droite(Orientation orient);

void ecrire_contour_fichier(Contour L,FILE * f);

void ecrire_liste_contours(Liste_Contour L, char *nom_fichier);

void ecrire_contour_eps(Contour L, char *nom_fichier, Image I, int fill);

void ecrire_image_eps(Liste_Contour L, char *nom_fichier, UINT h, UINT l);

char *modifier_extension(char *nom,char *extension);

char *stroke_ou_fill(char* nom,int fill);

Image init_masque(Image M);

Liste_Contour extraire_les_contours(Image I);

Contour simplification_contour(Tableau_Point tabcontour, UINT j1, UINT j2, UINT dist);

Liste_Contour simplification_contours(Liste_Contour L, UINT dist);

Bezier2 approx_bezier2(Tableau_Point tab_contour, UINT j1, UINT j2);

#endif
