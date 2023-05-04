#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include "image.h"
#include "types_macros.h"
#include "liste_chainee.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

/*modification du nom et de l'extension du fichier d'entrée 
afin de créer le nom du fichier de sortie en fonction des parametres d'entrée */
void modifier_extension(char *nom_fichier, char *nom, char *extension, char *type, char *d);

/*
    ________________________________________________________________
       Extraction de contours
    _______________________________________________________________
*/

/*Cherche un pixel initial pour commencer l'extraction d'un contour*/
Point trouve_pixel_init(Image I, Point pixel);

/*mouvement de la position du "robot" d'extration de contour 
en fonction de son orientation actuelle*/
Point avancer(Point p, Orientation orient);

/*rotation du "robot" d'extration de contour en fonction de son orientation actuelle*/
Orientation nouvelle_orientation(Image I, Point position, Orientation orient);

/*ajoute la position actuelle du robot en tant que point dans la liste de point correspondant au contour*/
void memoriser_position(Liste_Point *liste, Point p);

/*calcule le contour commencant au pixel fourni en entrée d'une image*/
void calcul_contour(Image I, Point pixel_init);

/*initialisation du masque de l'image*/
Image init_masque(Image M);

/*recupere un contour avec la mise a jour du masque*/
Contour recupere_contour(Image I, Image M, Point pixel_init);

/*extraction des différents contours d'une image*/
Liste_Contour extraire_les_contours(Image I);

/*
    ________________________________________________________________
       Simplification des contours
    _______________________________________________________________
*/

/*simplification par segment d'un contour*/
Contour simplification_contour(Tableau_Point tabcontour, UINT j1, UINT j2, double dist);

/*simplification par segment des contours*/
Liste_Contour simplification_contours(Liste_Contour L, double dist);

/*approximation d'une sequence de points par une courbe de bezier2*/
Bezier2 approx_bezier2(Tableau_Point tab_contour, UINT j1, UINT j2);

/*simplification par bezier2 d'un contour*/
Liste_Bezier2 simplification_contour_bezier2(Tableau_Point tabcontour, UINT j1, UINT j2, double dist);

/*simplification par bezier2 des contours*/
Liste_Contour_Bezier2 simplification_contours_bezier2(Liste_Contour L, double dist);

/*fonction interne au calcul dans approx bezier3*/
double y_approx(int i, float n);

/*approximation d'une sequence de points par une courbe de bezier3*/
Bezier3 approx_bezier3(Tableau_Point tab_contour, UINT j1, UINT j2);

/*simplification par bezier3 d'un contour*/
Liste_Bezier3 simplification_contour_bezier3(Tableau_Point tabcontour, UINT j1, UINT j2, double dist);

/*simplification par bezier3 des contours*/
Liste_Contour_Bezier3 simplification_contours_bezier3(Liste_Contour L, double dist);

/*
    ________________________________________________________________
       Affichage des informations
    _______________________________________________________________
*/

/*affichage dans le terminal des informations relatives a la positon*/
void afficher_position(Point position);

/*affichage dans le terminal des informations relatives au contour*/
void affiche_contour(Contour liste);

/*affichage dans le terminal des informations relatives a la liste de contours*/
void affiche_liste_contour(Liste_Contour liste);

/*affichage dans le terminal des informations relatives a la liste de bezier2*/
void affiche_liste_Bezier2(Liste_Contour_Bezier2 liste);

/*affichage dans le terminal des informations relative a la liste de bezier3*/
void affiche_liste_Bezier3(Liste_Contour_Bezier3 liste);

/*
    ________________________________________________________________
       Ecriture de contour dans un fichier de sortie
    _______________________________________________________________
*/

/*ecriture d'un contour sous forme de fichier texte*/
void ecrire_contour_fichier(Contour L,FILE * f);

/*ecriture d'une liste de contour sous forme de fichier texte*/
void ecrire_liste_contours(Liste_Contour L, char *nom_fichier);

/*ecriture d'un contour sous forme de fichier eps*/
void ecrire_contour_eps(Contour L, char *nom_fichier, Image I, int fill);

/*ecriture d'une image(liste de contour segment) sous forme de fichier eps*/
void ecrire_image_eps(Liste_Contour L, char *nom_fichier, UINT h, UINT l);

/*ecriture d'une image(liste de contour bezier2) sous forme de fichier eps*/
void ecrire_image_eps_bezier2(Liste_Contour_Bezier2 L, char *nom_fichier, UINT h, UINT l);

/*ecriture d'une image(liste de contour bezier3) sous forme de fichier eps*/
void ecrire_image_eps_bezier3(Liste_Contour_Bezier3 L, char *nom_fichier, UINT h, UINT l);

#endif
