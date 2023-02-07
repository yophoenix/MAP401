#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "types_macros.h"

int main(int argc, char** argv){
	if (argc < 2){
		printf("ERREUR : il faut spécifier un nom de fichier.\n");
		return 1;
	}
	Image I = lire_fichier_image(argv[1]);
	ecrire_image (I);
	Image neg = negatif_image(I);
	ecrire_image(neg);
	supprimer_image(&I);
	supprimer_image(&neg);
	return 0;
}
