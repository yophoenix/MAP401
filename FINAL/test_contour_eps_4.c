#include <stdio.h>
#include "contour.h"
#include "image.h"
#include "string.h"

int main(int argc, char** argv){
	if (argc < 3){
		printf("ERREUR. Usage : <nom fichier image> <fill = 1 , stroke = 0>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	// le point p en 2eme argument nous servira lorsqu'il s'agira de trouver plusieurs contours
	Point p = {0, 0};
	Point pixel_init = trouve_pixel_init(I,p);
	printf("Recuperation du contour de l'image test :\n");
	// Le masque n'est pas encore utile à ce stade mais il le sera plus tard
	Image M = creer_image(largeur_image(I), hauteur_image(I));
	Contour c=recupere_contour(I,M,pixel_init);
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	printf("Nombre de segments composant le contour :\n");
	affiche_contour(c);
	char nom_fichier[strlen(argv[1]) + 30];
	char nom_fichier2[strlen(argv[1]) + 30];
	int fill;
	sscanf(argv[2], "%d", &fill);
	if(fill==1){
		modifier_extension(nom_fichier, argv[1], ".txt", "fill","");
		modifier_extension(nom_fichier2, argv[1], ".eps", "fill", "");
	}
	if(fill==0){
		modifier_extension(nom_fichier, argv[1], ".txt", "stroke", "");
		modifier_extension(nom_fichier2, argv[1], ".eps", "stroke", "");
	}
	printf("Ecriture du contour dans le fichier texte : %s\n",nom_fichier);
	FILE* f = fopen(nom_fichier, "w");
	ecrire_contour_fichier(c,f);
	fclose(f);


	printf("Ecriture du contour dans le fichier eps : %s\n",nom_fichier2);

	ecrire_contour_eps(c,nom_fichier2,I,fill);
	return 0;
}
