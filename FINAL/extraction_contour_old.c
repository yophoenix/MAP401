#include <stdio.h>
#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERREUR. Usage : <nom fichier image>\n");
        return 1;
    }
    Image I = lire_fichier_image(argv[1]);
    printf("nom du fichier: %s\n", argv[1]);
    UINT h = hauteur_image(I);
    UINT l = largeur_image(I);
    printf("hauteur image: %u\n", h);
    printf("largeur image: %u\n", l);

    Liste_Contour L = extraire_les_contours(I);
	printf("Il y a %d contours\n",L.taille);
	affiche_liste_contour(L);
}
