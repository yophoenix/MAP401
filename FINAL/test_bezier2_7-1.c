#include <stdio.h>
#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("ERREUR. Usage : <nom fichier image> <distance seuil>\n");
        return 1;
    }
    Image I = lire_fichier_image(argv[1]);
    double dist;
    sscanf(argv[2], "%lf", &dist);

    printf("nom du fichier: %s\n", argv[1]);
    UINT h = hauteur_image(I);
    UINT l = largeur_image(I);
    printf("hauteur image: %u\n", h);
    printf("largeur image: %u\n", l);

    Liste_Contour L = extraire_les_contours(I);
    affiche_liste_contour(L);

    Liste_Contour_Bezier2 LC = simplification_contours_bezier2(L, dist);
    printf("image simplifiée:\n");
    affiche_liste_Bezier2(LC);

    char *nom_fichier = modifier_extension(argv[1], "eps");
    ecrire_image_eps_bezier2(LC, nom_fichier, h, l);
    return 0;
}