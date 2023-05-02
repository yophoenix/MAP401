#include <stdio.h>
#include "contour.h"
#include "image.h"

int main(int argc, char **argv)
{
    if (argc < 2){
        printf("ERREUR. Usage : <nom fichier image>\n");
        return 1;
    }
    Image I = lire_fichier_image(argv[1]);
    Point p = {0, 0};
    Point pixel_init = trouve_pixel_init(I, p);
    printf("Calcul du contour de l'image test :\n");
    calcul_contour(I, pixel_init);
    return 0;
}