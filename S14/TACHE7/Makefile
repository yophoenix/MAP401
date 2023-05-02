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
EXECUTABLES = test_simplification test_geobezier test_approx_bezier2 test_bezier2 test_approx_bezier3 test_bezier3


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

test_simplification.o : test_simplification.c image.h contour.h liste_chainee.h types_macros.h geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_simplification"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geobezier.o : test_geobezier.c geometrie2d.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geobezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx_bezier2.o : test_approx_bezier2.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_aprox_bezier2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier2.o : test_bezier2.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx_bezier3.o : test_approx_bezier3.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_aprox_bezier3"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier3.o : test_bezier3.c geometrie2d.h image.h contour.h liste_chainee.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier3"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de creation des executables

test_simplification : test_simplification.o liste_chainee.o contour.o image.o  geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_geobezier : test_geobezier.o geometrie2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx_bezier2 : test_approx_bezier2.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier2 : test_bezier2.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx_bezier3 : test_approx_bezier3.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_bezier3 : test_bezier3.o geometrie2d.o contour.o image.o liste_chainee.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
