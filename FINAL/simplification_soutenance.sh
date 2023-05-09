#!/bin/sh 

vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'

img="Asterix3"
echo "Image traitée : ${rougefonce}$img${neutre}"
./extraction_contour_8 ../IMAGES_TESTS/$img.pbm
echo ""
for fich in "segment" "bezier2" "bezier3"; do
	echo "Execution de ${vertclair}test_${fich}_8${neutre}\n"
	for d in 2 8 20; do
		read -p "Appuyez sur une touche pour continuer..." attendre
		echo "\ndistance-seuil : ${jaune}$d${neutre}"
		./test_${fich}_8 ../IMAGES_TESTS/$img.pbm $d
		echo "[${vertclair}OK${neutre}]"
		echo ""
		read -p "Appuyez sur une touche pour continuer..." attendre
		echo "\nAffichage de $img.eps\n"
		gv ../IMAGES_TESTS/${img}_${fich}_$d.eps &
		sleep 1
		echo ""
	done
	read -p "Voulez-vous fermer les 3 fenêtres GhostView ? (Y/y/N/n)" attendre
	if [ $attendre = "Y" ] || [ $attendre = "y" ]
	then
		echo ""
		pkill gv
		echo ""
	fi
done
