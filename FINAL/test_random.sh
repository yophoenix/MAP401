#!/bin/sh

vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'
gras='\e[0;m'

echo "${gras}Série de tests sur plusieurs images${neutre}\n"
echo "Execution de ${vertclair}test_segment_8${neutre}\n"
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\ndistance-seuil : ${jaune}5${neutre}"
./test_segment_8 ../IMAGES_TESTS/garfield.pbm 5
echo "[${vertclair}OK${neutre}]"
echo ""
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\nAffichage de garfield.eps\n"
gv --presentation ../IMAGES_TESTS/garfield_segment_5.eps &
sleep 1
echo ""
echo "Execution de ${vertclair}test_bezier2_8${neutre}\n"
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\ndistance-seuil : ${jaune}10${neutre}"
./test_bezier2_8 ../IMAGES_TESTS/JoaquimHock-LesArbres.pbm 10
echo "[${vertclair}OK${neutre}]"
echo ""
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\nAffichage de JoaquimHock-LesArbres.eps\n"
gv --presentation ../IMAGES_TESTS/JoaquimHock-LesArbres_bezier2_10.eps &
sleep 1
echo ""
echo "Execution de ${vertclair}test_bezier3_8${neutre}\n"
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\ndistance-seuil : ${jaune}20${neutre}"
./test_bezier3_8 ../IMAGES_TESTS/Manara.pbm 20
echo "[${vertclair}OK${neutre}]"
echo ""
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\nAffichage de Manara.eps\n"
gv --presentation ../IMAGES_TESTS/Manara_bezier3_20.eps &
sleep 1
echo ""
echo "Execution de ${vertclair}test_bezier3_8${neutre}\n"
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\ndistance-seuil : ${jaune}8${neutre}"
./test_bezier3_8 ../IMAGES_TESTS/Manara.pbm 8
echo "[${vertclair}OK${neutre}]"
echo ""
read -p "Appuyez sur une touche pour continuer..." attendre
echo "\nAffichage de Manara.eps\n"
gv --presentation ../IMAGES_TESTS/Manara_bezier3_8.eps &
sleep 1
echo ""
read -p "Voulez-vous fermer toutes les fenêtres GhostView ? (Y/y/N/n)" attendre
if [ $attendre = "Y" ] || [ $attendre = "y" ]
then
	echo ""
	pkill gv	
	sleep 1
	echo ""
fi
