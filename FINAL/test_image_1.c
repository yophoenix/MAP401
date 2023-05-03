#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types_macros.h"
#include "image.h"

int main(int argc, char* argv[]){
    if(argc<2){
        printf("Erreur d'arguements, usage: test_image <nom du fichier image>\n");
        return 1;
    }
    Image I=lire_fichier_image(argv[1]);
    printf("Voici I:\n");
    ecrire_image(I);
    Image Ineg = negatif_image(I);
    printf("Voici Ineg:\n");
    ecrire_image(Ineg);
    supprimer_image(&Ineg);
    supprimer_image(&I);
    return 0;
}