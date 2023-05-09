#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2020/2021
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image_1 test_geometrie2d_2 test_contour_robot_3-1 test_contour_txt_3-2 test_contour_eps_4 test_contours_5-1 test_contours_eps_5-2 test_point_segment_6-1 test_segment_6-2 test_geometrie_bezier_7-0 test_approx_bezier2_7-1 test_bezier2_7-1 test_approx_bezier3_7-2 test_bezier3_7-2 extraction_contour_8 test_segment_8 test_bezier2_8 test_bezier3_8



#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

contour.o : contour.c contour.h image.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

liste_chainee.o : liste_chainee.c liste_chainee.h image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module liste_chainee"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

geometrie2d.o : geometrie2d.c geometrie2d.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geometrie2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_image_1.o : test_image_1.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image_1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geometrie2d_2.o : test_geometrie2d_2.c geometrie2d.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geometrie2d_2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contour_robot_3-1.o : test_contour_robot_3-1.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour_robot_3-1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contour_txt_3-2.o : test_contour_txt_3-2.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour_txt_3-2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contour_eps_4.o : test_contour_eps_4.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h	
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour_eps_4"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contours_5-1.o : test_contours_5-1.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contours_5-1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contours_eps_5-2.o : test_contours_eps_5-2.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contours_eps_5-2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_point_segment_6-1.o : test_point_segment_6-1.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_point_segment_6-1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_segment_6-2.o : test_segment_6-2.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_segment_6-2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geometrie_bezier_7-0.o : test_geometrie_bezier_7-0.c geometrie2d.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geometrie_bezier_7-0"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx_bezier_7-1.o : test_approx_bezier_7-1.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_approx_bezier_7-1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier2_7-1.o : test_bezier2_7-1.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier2_7-1"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx_bezier3_7-2.o : test_approx_bezier3_7-2.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_approx_bezier3_7-2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier3_7-2.o : test_bezier3_7-2.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier3_7-2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier2_8.o : test_bezier2_8.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier2_8"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier3_8.o : test_bezier3_8.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier3_8"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_segment_8.o : test_segment_8.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_segment_8"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

extraction_contour_8.o : extraction_contour_8.c image.h contour.h geometrie2d.h types_macros.h liste_chainee.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module extraction_contour_8"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de creation des executables

test_image_1 : test_image_1.o image.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@
	
test_geometrie2d_2 : test_geometrie2d_2.o geometrie2d.o image.o contour.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contour_robot_3-1 : test_contour_robot_3-1.o image.o contour.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contour_txt_3-2 : test_contour_txt_3-2.o image.o contour.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contour_eps_4 : test_contour_eps_4.o image.o contour.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contours_5-1 : test_contours_5-1.o image.o contour.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contours_eps_5-2 : test_contours_eps_5-2.o image.o contour.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_point_segment_6-1 : test_point_segment_6-1.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_segment_6-2 : test_segment_6-2.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_geometrie_bezier_7-0 : test_geometrie_bezier_7-0.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx_bezier2_7-1 : test_approx_bezier2_7-1.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier2_7-1 : test_bezier2_7-1.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier2_8 : test_bezier2_8.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx_bezier3_7-2 : test_approx_bezier3_7-2.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier3_7-2 : test_bezier3_7-2.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier3_8 : test_bezier3_8.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_segment_8 : test_segment_8.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

extraction_contour_8 : extraction_contour_8.o contour.o image.o liste_chainee.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

########################################################

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
