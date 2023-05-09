#!/bin/sh

vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'

echo ""
echo "Tests sur le parcours du \"robot\" de recuperation d'un contour"
read -p "Appuyez sur une touche pour continuer..." attendre
echo ""
./test_contour_robot_3-1 ../IMAGES_TESTS/im_test1.pbm
#ouvrir im_test1.pbm et explication du fonctionnement de la detection de contour
echo ""
read -p "Appuyez sur une touche pour continuer..." attendre

echo ""
echo "Tests sur l'extraction de contour(s) à partir de 2 images PBM"
read -p "Appuyez sur une touche pour continuer..." attendre
echo ""

for img in "image_poly_tache6" "Asterix3"; do
	echo "Image traitée : ${rougefonce}$img.pbm${neutre}"
	echo "test_contours_eps_5-2 ../IMAGES_TESTS/$img"
	echo ""
	./test_contours_eps_5-2 ../IMAGES_TESTS/$img.pbm
	echo "[${vertclair}OK${neutre}]"
	echo ""
	read -p "Appuyez sur une touche pour afficher..." attendre
	gv ../IMAGES_TESTS/${img}.eps &
	sleep 1
	read -p "Appuyez sur une touche pour continuer..." attendre
	echo ""
done
