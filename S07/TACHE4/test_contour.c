#include <stdio.h>
#include "contour.h"

int main(int argc, char** argv){
	if (argc < 3){
		printf("ERREUR. Usage : <nom fichier image> <nom fichier contour>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	Point pixel_init = trouve_pixel_init(I);
	printf("Recuperation du contour de l'image test :\n");
	Contour c=recupere_contour(I,pixel_init);
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	printf("Nombre de segments composant le contour :\n");
	calcul_contour(c);
	printf("Ecriture du contour dans le fichier texte : %s\n",argv[2]);
	ecrire_contour_fichier(c,argv[2]);
	return 0;
}
