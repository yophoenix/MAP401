#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "contour.h"

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
