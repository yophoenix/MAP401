#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"
#include "liste_chainee.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

Contour recupere_contour(Image I, Image M, Point pixel_init);

void afficher_position(Point position);

void calcul_contour(Image I, Point pixel_init);

void affiche_contour(Contour liste);

void affiche_liste_contour(Liste_Contour liste);

void affiche_liste_Bezier2(Liste_Contour_Bezier2 liste);

void affiche_liste_Bezier3(Liste_Contour_Bezier3 liste);

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

void ecrire_image_eps_bezier2(Liste_Contour_Bezier2 L, char *nom_fichier, UINT h, UINT l);

void ecrire_image_eps_bezier3(Liste_Contour_Bezier3 L, char *nom_fichier, UINT h, UINT l);

char *modifier_extension(char *nom, char *extension);

char *stroke_ou_fill(char* nom,int fill);

Image init_masque(Image M);

Liste_Contour extraire_les_contours(Image I);

Contour simplification_contour(Tableau_Point tabcontour, UINT j1, UINT j2, UINT dist);

Liste_Contour simplification_contours(Liste_Contour L, UINT dist);

Bezier2 approx_bezier2(Tableau_Point tab_contour, UINT j1, UINT j2);

double y_approx(int i, float n);

Bezier3 approx_bezier3(Tableau_Point tab_contour, UINT j1, UINT j2);

Liste_Bezier2 simplification_contour_bezier2(Tableau_Point tabcontour, UINT j1, UINT j2, UINT dist);

Liste_Contour_Bezier2 simplification_contours_bezier2(Liste_Contour L, UINT dist);

Liste_Bezier3 simplification_contour_bezier3(Tableau_Point tabcontour, UINT j1, UINT j2, UINT dist);

Liste_Contour_Bezier3 simplification_contours_bezier3(Liste_Contour L, UINT dist);

#endif
