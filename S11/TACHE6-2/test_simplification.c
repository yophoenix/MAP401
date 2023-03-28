#include <stdio.h>
#include "contour.h"
#include "image.h"


int main(int argc, char** argv){
	if (argc < 3){
		printf("ERREUR. Usage : <nom fichier image> <distance seuil>\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	UINT dist;
	sscanf(argv[2], "%d", &dist);
	//printf("Recuperation du contour de l'image test :\n");
	printf("nom du fichier: %s\n", argv[1]);
	printf("hauteur image: %u\n", hauteur_image(I));
	printf("largeur image: %u\n", largeur_image(I));
	Liste_Contour L = extraire_les_contours(I);
	Cellule_Liste_Contour* celcontour = L.first;
	printf("La");
	while (celcontour!=NULL){
		Contour c = simplification_contour(celcontour->data, 0, celcontour->data.taille, dist);
		celcontour->data = c;
		celcontour = celcontour->suiv;
	}
	char *nom_fichier=modifier_extension(argv[1],"eps");
	ecrire_image_eps(L, nom_fichier, I);
	//printf("Ecriture du contour dans le fichier texte : %s\n",nom_fichier);
	//ecrire_liste_contours(L,nom_fichier);
	return 0;
}
