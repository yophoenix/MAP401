#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "contour.h"

Point trouve_pixel_init(Image I)
{
	UINT h = 1;
	UINT l = 1;
	UINT L = largeur_image(I);
	UINT H = hauteur_image(I);
	Point pixel_init = {0, 0};
	while ((h <= H) && (pixel_init.x == 0))
	{
		while ((l <= L) && (pixel_init.x == 0))
		{
			if (get_pixel_image(I, l, h))
			{
				pixel_init.x = l;
				pixel_init.y = h;
			}
			l++;
		}
		l = 1;
		h++;
	}
	if (pixel_init.x == 0)
	{
		printf("Pas de pixel initial de contour trouvé\n");
	}
	return pixel_init;
}

Contour recupere_contour(Image I, Point pixel_init){
	Liste_Point liste = creer_liste_Point_vide();
	Point pos_init=set_point(pixel_init.x - 1, pixel_init.y - 1);
	Point position=set_point(pos_init.x,pos_init.y);
	Orientation orient=Est;
	bool boucle=true;
	while (boucle){
		memoriser_position(&liste,position);
		position = avancer(position,orient);
		orient = nouvelle_orientation(I,position,orient);
		if (position.x == pos_init.x && position.y == pos_init.y && orient==Est){
			boucle=false;
		}
	}
	memoriser_position(&liste,position);
	return liste;
}

void calcul_contour(Contour liste){
	printf("Ce contour contient %d segments.\n",liste.taille-1);
}

void memoriser_position(Liste_Point *liste, Point p){
	ajouter_element_liste_Point(liste,p);
}

Point avancer(Point p, Orientation orient){
	switch (orient){
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

Orientation nouvelle_orientation(Image I,Point position, Orientation orient){
	Pixel pD;
	Pixel pG;
	switch (orient){
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
	if (pG){
		orient = (orient - 1) % 4;
	}
	else if (!pD){
		orient = (orient + 1) % 4;
	}
	return orient;
}

/* écrire le contour L dans un fichier */ 
void ecrire_contour_fichier(Contour L,char* nom_fichier)
{
	FILE *f=fopen(nom_fichier,"w");
	Tableau_Point TP = sequence_points_liste_vers_tableau(L);
	int k;
	int nP = TP.taille;
	
	fprintf(f,"1\n\n%d\n",nP);
	for (k = 0; k < nP; k++)
	{	
		Point P = TP.tab[k]; /* récupérer le point d'indice k */
		fprintf(f," %5.1f %5.1f\n", P.x, P.y);
	} 
	
	free(TP.tab); /* supprimer le tableau de point TP */
	fclose(f);
}

void ecrire_contour_eps(Contour L,char* nom_fichier, Image I,int fill)
{
	FILE *f=fopen(nom_fichier,"w");

	UINT l=largeur_image(I);
	UINT h=hauteur_image(I);
	fprintf(f,"%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: 1 1 %d %d\n\n",l,h);

	Cellule_Liste_Point* cel = L.first;
	if (cel!=NULL){
		fprintf(f,"%lf %lf moveto ",cel->data.x,cel->data.y);
		cel=cel->suiv;
		while (cel!=NULL){
			fprintf(f,"%lf %lf lineto \n",cel->data.x,cel->data.y);
			cel=cel->suiv;
		}
	}
	if(!fill){
		fprintf(f, "stroke\n");
	}
	else{
		fprintf(f, "fill\n");
	}
	fprintf(f,"\n showpage");
	fclose(f);
}
