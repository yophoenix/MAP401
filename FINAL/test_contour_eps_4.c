#include <stdio.h>
#include "contour.h"
#include "image.h"


int main(int argc, char** argv){
	if (argc < 3){
		printf("ERREUR. Usage : <nom fichier image> <fill = 1 , stroke = 0>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	Point pixel_init = trouve_pixel_init(I);
	printf("Recuperation du contour de l'image test :\n");
	// Le masque n'est pas encore utile à ce stade mais il le sera plus tard
	Image M = creer_image(largeur_image(I), hauteur_image(I));
	Contour c=recupere_contour(I,M,pixel_init);
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	printf("Nombre de segments composant le contour :\n");
	affiche_contour(c);
	char* nom_fichier=modifier_extension(argv[1],"txt");
	printf("Ecriture du contour dans le fichier texte : %s\n",nom_fichier);
	ecrire_contour_fichier(c,nom_fichier);
	int fill;
	sscanf(argv[2],"%d",&fill);
	nom_fichier=stroke_ou_fill(nom_fichier,fill);
	nom_fichier=modifier_extension(nom_fichier,"eps");
	printf("Ecriture du contour dans le fichier eps : %s\n",nom_fichier);
	ecrire_contour_eps(c,nom_fichier,I,fill);
	return 0;
}
