vertclair='\e[1;32m'
jaune='\e[1;33m'
rougefonce='\e[0;31m'
orange='\e[0;33m'
neutre='\e[0;m'

for img in "Asterix3.pbm" "lettre-L-cursive.pbm" "ColombesDeLaPaix.pbm"; do
	echo "Image traitée : ${rougefonce}$img${neutre}"
	./extraction_contour image_test/$img
	echo ""
	for fich in "test_simplification_8" "test_bezier2_8" "test_bezier3_8"; do
		echo "Execution de ${vertclair}$fich${neutre}"
		for d in 0 0.5 1 2 4 8 16; do
			echo "distance-seuil : ${jaune}$d${neutre}"
			./$fich Images_test/$img $d
			read attendre
		done
	done
done
