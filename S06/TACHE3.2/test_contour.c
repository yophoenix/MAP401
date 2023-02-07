#include <stdio.h>
#include "contour.h"
#include "image.h"

int main(int argc, char** argv){
	if (argc < 5){
		printf("ERREUR. Usage : <nom fichier image> <nom fichier contour> <Pixel en x> <Pixel en y>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	double x,y;
	sscanf(argv[3],"%lf",&x);
	sscanf(argv[4],"%lf",&y);
	Point pixel_init = set_point(x,y);
	printf("Recuperation du contour de l'image test :\n");
	Contour c=recupere_contour(I,pixel_init);
	printf("Nombre de segments composant le contour :\n");
	calcul_contour(c);
	printf("Ecriture du contour dans le fichier texte : %s\n",argv[2]);
	ecrire_contour_fichier(c,argv[2]);
	return 0;
}
