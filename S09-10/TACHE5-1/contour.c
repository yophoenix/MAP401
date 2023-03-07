#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
			if (get_pixel_image(I, l, h) && !get_pixel_image(I, l, h - 1))
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
		printf("Plus de pixel initial trouvé\n");
	}
	return pixel_init;
}

Contour recupere_contour(Image I, Image M, Point pixel_init){
	Liste_Point liste = creer_liste_Point_vide();
	Point pos_init=set_point(pixel_init.x - 1, pixel_init.y - 1);
	Point position=set_point(pos_init.x,pos_init.y);
	set_pixel_image(M, position.x + 1, position.y + 1, BLANC);
	Orientation orient=Est;
	bool boucle=true;
	while (boucle){
		set_pixel_image(M, position.x + 1, position.y + 1, BLANC);
		memoriser_position(&liste,position);
		position = avancer(position,orient);
		orient = nouvelle_orientation(I,position,orient);
		if (position.x == pos_init.x && position.y == pos_init.y && orient==Est){
			boucle=false;
		}
	}
	set_pixel_image(M, position.x + 1, position.y + 1, BLANC);
	memoriser_position(&liste,position);
	return liste;
}

void calcul_contour(Contour liste){
	printf("Ce contour contient %d segments.\n",liste.taille-1);
}

void affiche_liste_contour(Liste_Contour liste){
	UINT l=0;
	Cellule_Liste_Contour *cel = liste.first;
	while (cel!=NULL){
		l+=cel->data.taille;
		cel = cel->suiv;
	}
	printf("Il y a %d contours\n"
			"Il y a %d points\n"
			"Il y a %d segments\n", liste.taille,l,l-liste.taille);
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
void ecrire_contour_fichier(Contour L,FILE * f)
{
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
}

void ecrire_liste_contours(Liste_Contour L, char *nom_fichier){
	FILE *f = fopen(nom_fichier, "w");
	Cellule_Liste_Contour *liste = L.first;
	UINT t = L.taille;
	fprintf(f, "%d", t);
	while (liste!=NULL){
		ecrire_contour_fichier(liste->data, f);
		liste = liste->suiv;
	}
}

void ecrire_contour_eps(Contour L,char* nom_fichier, Image I,int fill)
{
	FILE *f=fopen(nom_fichier,"w");

	UINT l=largeur_image(I);
	UINT h=hauteur_image(I);
	fprintf(f,"%%!PS-Adobe-3.0 EPSF-3.0\n%%%%BoundingBox: 1 1 %d %d\n\n",l,h);

	Cellule_Liste_Point* cel = L.first;
	if (cel!=NULL){
		fprintf(f,"%.0f %.0f moveto ",cel->data.x,I.la_hauteur_de_l_image - cel->data.y);
		cel=cel->suiv;
		while (cel!=NULL){
			fprintf(f,"%.0f %.0f lineto \n",cel->data.x,I.la_hauteur_de_l_image - cel->data.y);
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

char *modifier_extension(char* nom,char *extension){
	char *nom_fichier = nom;
	int x=0;
	while (nom_fichier[x]!='.'){
		x++;
	}
	x++;
	nom_fichier[x]=extension[0];
	x++;
	nom_fichier[x]=extension[1];
	x++;
	nom_fichier[x]=extension[2];
	return nom_fichier;
}

char *stroke_ou_fill(char* nom,int fill){
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
}

Image init_masque(Image I){
	UINT L = largeur_image(I);
	UINT H = hauteur_image(I);
	Image M = creer_image(L, H);
	UINT nb_pixel_init = 0;
	for (UINT h = 1; h <= H; h++){
			for(UINT l=1; l<=L; l++)
			{
				if (get_pixel_image(I,l,h)&&!get_pixel_image(I, l, h-1))
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

Liste_Contour extraire_les_contours(Image I){
	Liste_Contour liste = creer_liste_Contour_vide();
	Image M = init_masque(I);
	Point pixel_init = trouve_pixel_init(M);
	while(pixel_init.x!=0){
		Contour c = recupere_contour(I, M, pixel_init);
		ajouter_element_liste_Contour(&liste,c);
		pixel_init = trouve_pixel_init(M);
	}
	return liste;
}
