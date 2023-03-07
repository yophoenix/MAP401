#include <stdio.h>
#include "contour.h"
#include "image.h"


int main(int argc, char** argv){
	if (argc < 3){
		printf("ERREUR. Usage : <nom fichier image> <fill = 1 , stroke = 0>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	//printf("Recuperation du contour de l'image test :\n");
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	Liste_Contour L = extraire_les_contours(I);
	affiche_liste_contour(L);
	int fill;
	sscanf(argv[2],"%d",&fill);
	char *nom_fichier=stroke_ou_fill(argv[1],fill);
	nom_fichier=modifier_extension(nom_fichier,"eps");
	printf("Ecriture du contour dans le fichier eps : %s\n",nom_fichier);
	ecrire_image_eps(L,nom_fichier,I,fill);
	//printf("Ecriture du contour dans le fichier texte : %s\n",nom_fichier);
	//ecrire_liste_contours(L,nom_fichier);
	return 0;
}
