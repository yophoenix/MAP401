#include <stdio.h>
#include "contour.h"
#include "image.h"


int main(int argc, char** argv){
	if (argc < 2){
		printf("ERREUR. Usage : <nom fichier image>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	printf("Recuperation du contour de l'image test :\n");
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	char* nom_fichier=modifier_extension(argv[1],"txt");
	Liste_Contour L = extraire_les_contours(I);
	affiche_liste_contour(L);
	printf("Ecriture du contour dans le fichier texte : %s\n",nom_fichier);
	ecrire_liste_contours(L,nom_fichier);
	return 0;
}
