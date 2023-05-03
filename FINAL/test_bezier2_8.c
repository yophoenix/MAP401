#include <stdio.h>
#include "contour.h"
#include "image.h"
#include "string.h"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("ERREUR. Usage : <nom fichier image> <distance seuil>\n");
        return 1;
    }
    Image I = lire_fichier_image(argv[1]);
    UINT dist;
    sscanf(argv[2], "%d", &dist);

    UINT h = hauteur_image(I);
    UINT l = largeur_image(I);

    Liste_Contour L = extraire_les_contours(I);

    Liste_Contour_Bezier2 LC = simplification_contours_bezier2(L, dist);
    printf("Image simplifiée:\n");
    affiche_liste_Bezier2(LC);
	char nom_fichier[strlen(argv[1])+30];

	modifier_extension(nom_fichier,argv[1], "eps","bezier2",argv[2]);
	printf("\e[0;33m%s\e[0;m\n",nom_fichier);
    ecrire_image_eps_bezier2(LC, nom_fichier, h, l);
    return 0;
}
