#!/bin/sh

vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'

echo ""
echo "Tests sur l'extraction de contour(s) à partir de 3 images PBM"
read -p "Appuyez sur une touche pour continuer..." attendre
echo ""
for img in "Asterix3.pbm" "lettre-L-cursive.pbm" "image_poly_tache6.pbm"; do
	echo "Image traitée : ${rougefonce}$img${neutre}"
	echo "./extraction_contour ../IMAGES_TESTS/$img"
	./extraction_contour ../IMAGES_TESTS/$img
	echo "[${vertclair}OK${neutre}]"
	read -p "Appuyez sur une touche pour continuer..." attendre
	echo ""
done
