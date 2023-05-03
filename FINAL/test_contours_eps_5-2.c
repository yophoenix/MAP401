#include <stdio.h>
#include "contour.h"
#include "image.h"


int main(int argc, char** argv){
	if (argc < 2){
		printf("ERREUR. Usage : <nom fichier image>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	UINT h = hauteur_image(I);
	UINT l = largeur_image(I);
	//printf("Recuperation du contour de l'image test :\n");
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", h);
	printf("largeur image: %u\n", l);
	Liste_Contour L = extraire_les_contours(I);
	affiche_liste_contour(L);
	char *nom_fichier=modifier_extension(argv[1],"eps");
	printf("Ecriture du contour dans le fichier eps : %s\n",nom_fichier);
	ecrire_image_eps(L,nom_fichier,h,l);
	return 0;
}
