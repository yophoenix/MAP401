#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "contour.h"
#include "liste_chainee.h"
#include "types_macros.h"


Point trouve_pixel_init(Image I, Point pixel)
{
	UINT h = pixel.y;
	UINT l = pixel.x;
	UINT L = largeur_image(I);
	UINT H = hauteur_image(I);
	Point pixel_init = {0, 0};
	while (h <= H)
	{
		while (l <= L)
		{
			if (get_pixel_image(I, l, h) && !get_pixel_image(I, l, h - 1))
			{
				pixel_init.x = l;
				pixel_init.y = h;
				return pixel_init;
			}
			l++;
		}
		l = 1;
		h++;
	}
	if (pixel_init.x == 0)
	{
		printf("Plus de pixel initial trouvé\n");
	}
	return pixel_init;
}

Contour recupere_contour(Image I, Image M, Point pixel_init)
{
	Liste_Point liste = creer_liste_Point_vide();
	Point pos_init = set_point(pixel_init.x - 1, pixel_init.y - 1);
	Point position = set_point(pos_init.x, pos_init.y);
	set_pixel_image(M, position.x + 1, position.y + 1, BLANC);
	Orientation orient = Est;
	bool boucle = true;
	while (boucle)
	{
		if (orient == Est)
		{
			set_pixel_image(M, position.x + 1, position.y + 1, BLANC);
		}
		memoriser_position(&liste, position);
		position = avancer(position, orient);
		orient = nouvelle_orientation(I, position, orient);
		if (position.x == pos_init.x && position.y == pos_init.y && orient == Est)
		{
			boucle = false;
		}
	}
	memoriser_position(&liste, position);
	return liste;
}

void calcul_contour(Contour liste)
{
	printf("Ce contour contient %d segments.\n", liste.taille - 1);
}

void affiche_liste_contour(Liste_Contour liste)
{
	UINT l = 0;
	Cellule_Liste_Contour *cel = liste.first;
	while (cel != NULL)
	{
		l += cel->data.taille;
		cel = cel->suiv;
	}
	printf("Il y a %d contours\n"
		   "Il y a %d points\n"
		   "Il y a %d segments\n",
		   liste.taille, l, l - liste.taille);
}

void affiche_liste_Bezier2(Liste_Bezier2 liste){
	printf("Il y'a %d courbes\n"
		   "Il y a %d points",
		   liste.taille, liste.taille);
}

void memoriser_position(Liste_Point *liste, Point p)
{
	ajouter_element_liste_Point(liste, p);
}

Point avancer(Point p, Orientation orient)
{
	switch (orient)
	{
	case Nord:
		p.y--;
		break;
	case Est:
		p.x++;
		break;
	case Sud:
		p.y++;
		break;
	case Ouest:
		p.x--;
		break;
	}
	return p;
}

Orientation nouvelle_orientation(Image I, Point position, Orientation orient)
{
	Pixel pD;
	Pixel pG;
	switch (orient)
	{
	case Nord:
		pD = get_pixel_image(I, position.x + 1, position.y);
		pG = get_pixel_image(I, position.x, position.y);
		break;
	case Est:
		pD = get_pixel_image(I, position.x + 1, position.y + 1);
		pG = get_pixel_image(I, position.x + 1, position.y);
		break;
	case Sud:
		pD = get_pixel_image(I, position.x, position.y + 1);
		pG = get_pixel_image(I, position.x + 1, position.y + 1);
		break;
	case Ouest:
		pD = get_pixel_image(I, position.x, position.y);
		pG = get_pixel_image(I, position.x, position.y + 1);
		break;
	}
	if (pG)
	{
		orient = (orient - 1) % 4;
	}
	else if (!pD)
	{
		orient = (orient + 1) % 4;
	}
	return orient;
}

/* écrire le contour L dans un fichier */
void ecrire_contour_fichier(Contour L, FILE *f)
{
	Tableau_Point TP = sequence_points_liste_vers_tableau(L);
	int k;
	int nP = TP.taille;

	fprintf(f, "\n%d\n", nP);
	for (k = 0; k < nP; k++)
	{
		Point P = TP.tab[k]; /* récupérer le point d'indice k */
		fprintf(f, " %5.1f %5.1f\n", P.x, P.y);
	}

	free(TP.tab); /* supprimer le tableau de point TP */
}

void ecrire_liste_contours(Liste_Contour L, char *nom_fichier)
{
	FILE *f = fopen(nom_fichier, "w");
	Cellule_Liste_Contour *liste = L.first;
	UINT t = L.taille;
	fprintf(f, "%d\n", t);
	while (liste != NULL)
	{
		ecrire_contour_fichier(liste->data, f);
		liste = liste->suiv;
	}
}

void ecrire_contour_eps(Contour L, char *nom_fichier, Image I, int fill)
{
	FILE *f = fopen(nom_fichier, "w");

	UINT l = largeur_image(I);
	UINT h = hauteur_image(I);
	fprintf(f, "%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: 1 1 %d %d\n\n", l, h);

	Cellule_Liste_Point *cel = L.first;
	if (cel != NULL)
	{
		fprintf(f, "%.0f %.0f moveto ", cel->data.x, I.la_hauteur_de_l_image - cel->data.y);
		cel = cel->suiv;
		while (cel != NULL)
		{
			fprintf(f, "%.0f %.0f lineto \n", cel->data.x, I.la_hauteur_de_l_image - cel->data.y);
			cel = cel->suiv;
		}
	}
	if (!fill)
	{
		fprintf(f, "stroke\n");
	}
	else
	{
		fprintf(f, "fill\n");
	}
	fprintf(f, "\n showpage");
	fclose(f);
}

void ecrire_image_eps(Liste_Contour L, char *nom_fichier, UINT h, UINT l)
{
	FILE *f = fopen(nom_fichier, "w");

	fprintf(f, "%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: 0 0 %d %d\n\n", l, h);
	Cellule_Liste_Contour *C = L.first;
	Cellule_Liste_Point *cel = NULL;

	while (C != NULL)
	{
		cel = C->data.first;
		if (cel != NULL)
		{
			fprintf(f, "%.0f %.0f moveto ", cel->data.x, h - cel->data.y);
			cel = cel->suiv;
			while (cel != NULL)
			{
				fprintf(f, "%.0f %.0f lineto \n", cel->data.x, l - cel->data.y);
				cel = cel->suiv;
			}
		}
		C = C->suiv;
	}
	fprintf(f, "\nfill\nshowpage");
	fclose(f);
}

void ecrire_image_eps_bezier2(Liste_Bezier2 L, char *nom_fichier, UINT h, UINT l)
{
	FILE *f = fopen(nom_fichier, "w");

	fprintf(f, "%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: 0 0 %d %d\n\n", l, h);
	Cellule_Liste_Bezier2 *B2 = L.first;
	while (B2 != NULL)
	{
		Bezier3 B3 = conversion_bezier2_vers_3(B2->data);
		fprintf(f, "%.0f %.0f moveto ", B3.C0.x, h - B3.C0.y);

		fprintf(f, "%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f curveto \n", B3.C0.x, l - B3.C0.y, B3.C1.x, l - B3.C1.y, B3.C2.x, l - B3.C2.y, B3.C3.x, l - B3.C3.y);
		B2 = B2->suiv;
	}
	fprintf(f, "\nfill\nshowpage");
	fclose(f);
}

char *modifier_extension(char *nom, char *extension)
{
	char *nom_fichier = nom;
	int x = 0;
	if (nom_fichier[x] == '.' && nom_fichier[x + 1] == '/')
	{
		x += 2;
	}
	while (nom_fichier[x] != '.')
	{
		x++;
	}
	x++;
	nom_fichier[x] = extension[0];
	x++;
	nom_fichier[x] = extension[1];
	x++;
	nom_fichier[x] = extension[2];
	return nom_fichier;
}

/*char *stroke_ou_fill(char* nom,int fill){
  int x=0;
  while (nom[x]!='.'){
  x++;
  }
  char* nom_fichier = calloc(x + 15, sizeof(char));
  for(int i=0;i<x;i++){
  nom_fichier[i]=nom[i];
  }
  if (fill){
  nom_fichier=strcat(nom_fichier,"-fill.");
  }else{
  nom_fichier=strcat(nom_fichier,"-stroke.");
  }
  return nom_fichier;
  }*/

Image init_masque(Image I)
{
	UINT L = largeur_image(I);
	UINT H = hauteur_image(I);
	Image M = creer_image(L, H);
	UINT nb_pixel_init = 0;
	for (UINT h = 1; h <= H; h++)
	{
		for (UINT l = 1; l <= L; l++)
		{
			if (get_pixel_image(I, l, h) && !get_pixel_image(I, l, h - 1))
			{
				set_pixel_image(M, l, h, NOIR);
				nb_pixel_init++;
			}
		}
	}
	if (nb_pixel_init == 0)
	{
		printf("Pas de pixel initial de contour trouvé\n");
	}
	return M;
}

Liste_Contour extraire_les_contours(Image I)
{
	Liste_Contour liste = creer_liste_Contour_vide();
	Image M = init_masque(I);
	Point pixel_init = {0, 0};
	pixel_init = trouve_pixel_init(M, pixel_init);
	while (pixel_init.x != 0)
	{
		Contour c = recupere_contour(I, M, pixel_init);
		ajouter_element_liste_Contour(&liste, c);
		pixel_init = trouve_pixel_init(M, pixel_init);
	}
	return liste;
}

Contour simplification_contour(Tableau_Point tabcontour,UINT j1, UINT j2,UINT dist){
	Liste_Point L = creer_liste_Point_vide();
	double dmax = 0;
	UINT k = j1;
	for (int j = j1 + 1; j < j2;j++){
		double dj = distance_segment(tabcontour.tab[j1],tabcontour.tab[j2],tabcontour.tab[j]);
		if(dmax<dj){
			dmax = dj;
			k = j;
		}
	}
	if(dmax<=dist){
		ajouter_element_liste_Point(&L,tabcontour.tab[j1]);
		ajouter_element_liste_Point(&L, tabcontour.tab[j2]);
	}
	else{
		Contour L1 = simplification_contour(tabcontour, j1, k, dist);
		Contour L2 = simplification_contour(tabcontour, k, j2, dist);
		L2 = supp_first_element_liste_Point(L2);
		L = concatener_liste_Point(L1, L2);
	}
	return L;
}

Liste_Contour simplification_contours(Liste_Contour L,UINT dist){
	if (L.first == NULL)
	{
		printf("Il n'y rien dans la liste contour donc pas simplifiable");
		return L;
	}
	Cellule_Liste_Contour *celcontour = L.first;
	Liste_Contour LC = creer_liste_Contour_vide();
	for (int i = 0; i < L.taille; i++){
		Tableau_Point tabcontour = sequence_points_liste_vers_tableau(celcontour->data);
		Contour c = simplification_contour(tabcontour, 0, celcontour->data.taille - 1, dist);
		ajouter_element_liste_Contour(&LC, c);
		celcontour = celcontour->suiv;
	}
	return LC;
}

Bezier2 approx_bezier2 (Tableau_Point tab_contour,UINT j1,UINT j2){
	Bezier2 B;
	B.C0 = tab_contour.tab[j1];
	B.C2 = tab_contour.tab[j2];

	float n = (float)(j2-j1);
	if (n==1){
		B.C1.x = (tab_contour.tab[j1].x + tab_contour.tab[j2].x) / 2;
		B.C1.y = (tab_contour.tab[j1].y + tab_contour.tab[j2].y) / 2;
	}
	else {
		if(n>=2) {
			float a = (float)((3 * n) / (n*n - 1));
			float b = (float)((1 - 2 * n) / (2 * (n + 1)));
			float sommex = 0;
			float sommey = 0;
			for (int i = 1; i <= n - 1; i++)
			{
				sommex = sommex + tab_contour.tab[j1 + i].x;
				sommey = sommey + tab_contour.tab[j1 + i].y;
			}
			B.C1.x = a * sommex + b * (tab_contour.tab[j1].x + tab_contour.tab[j2].x);
			B.C1.y = a * sommey + b * (tab_contour.tab[j1].y + tab_contour.tab[j2].y);
		}
	}
	return B;
}

Liste_Bezier2 simplification_contour_bezier2(Tableau_Point tabcontour, UINT j1, UINT j2, UINT dist)
{
	UINT n = j2 - j1;
	Liste_Bezier2 L = creer_liste_Bezier2_vide();
	double dmax = 0;
	UINT k = j1;
	Bezier2 B = approx_bezier2(tabcontour, j1, j2);
	for (int j = j1 + 1; j < j2; j++)
	{
		UINT i = j - j1;
		double ti = (float)i / (float)n;
		double dj = distance_bezier2(tabcontour.tab[j],B,ti);
		if (dmax < dj)
		{
			dmax = dj;
			k = j;
		}
	}
	if (dmax <= (float)dist)
	{
		ajouter_element_liste_Bezier2(&L, B);
	}
	else
	{
		Liste_Bezier2 L1 = simplification_contour_bezier2(tabcontour, j1, k, dist);
		Liste_Bezier2 L2 = simplification_contour_bezier2(tabcontour, k, j2, dist);
		L = concatener_liste_Bezier2(L1, L2);
	}
	return L;
}

Liste_Bezier2 simplification_contours_bezier2(Liste_Contour L, UINT dist)
{
	Liste_Bezier2 LC = creer_liste_Bezier2_vide();

	if (L.first == NULL)
	{
		printf("Il n'y rien dans la liste contour donc pas simplifiable");
		return LC;
	}
	Cellule_Liste_Contour *celcontour = L.first;
	for (int i = 0; i < L.taille; i++)
	{
		Tableau_Point tabcontour = sequence_points_liste_vers_tableau(celcontour->data);
		Liste_Bezier2 c = simplification_contour_bezier2(tabcontour, 0, celcontour->data.taille - 1, dist);
		concatener_liste_Bezier2(LC, c);
		celcontour = celcontour->suiv;
	}
	return LC;
}