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
    UINT h = hauteur_image(I);
    UINT l = largeur_image(I);
    printf("Hauteur image: %u\n", h);
    printf("Largeur image: %u\n", l);

    Liste_Contour L = extraire_les_contours(I);
	affiche_liste_contour(L);
}
