#!/bin/bash

vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'

for img in "Asterix3" "lettre-L-cursive" "ColombesDeLaPaix"; do
	echo "Image traitée : ${rougefonce}$img${neutre}"
	./extraction_contour ../IMAGES_TESTS/$img.pbm
	echo ""
	for fich in "simplification" "bezier2" "bezier3"; do
		echo "Execution de ${vertclair}test_${fich}_8${neutre}"
		for d in 0 2 8; do
			echo "distance-seuil : ${jaune}$d${neutre}"
			./test_${fich}_8 ../IMAGES_TESTS/$img.pbm $d
			echo "[${vertclair}OK${neutre}]"
			read -p "Appuyez sur une touche pour continuer..."
			echo "Affichage de $img.eps"
			gv ../IMAGES_TESTS/${img}_${fich}_$d.eps &
			read -p "Appuyez sur une touche pour continuer..."
		done
	done
done
