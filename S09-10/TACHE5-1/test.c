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

    Image M = init_masque(I);
    ecrire_image(M);
    return 0;
}
