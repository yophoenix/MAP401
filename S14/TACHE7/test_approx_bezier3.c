#include <stdio.h>
#include <stdlib.h>
#include "geometrie2d.h"
#include "contour.h"

int main (int argc, char* argv[]){
    if (argc < 2){
        printf("ERREUR. Usage : <n><x1><y1><x2><y2>\n");
        return 1;
    }
    int n;
    sscanf(argv[1], "%d", &n);
    if (argc<6 && n==1){
        printf("ERREUR. Usage : <n><x1><y1><x2><y2>\n");
        return 1;
    }
    
    double x1, x2, y1, y2;
    sscanf(argv[2], "%lf", &x1);
    sscanf(argv[3], "%lf", &y1);
    sscanf(argv[4], "%lf", &x2);
    sscanf(argv[5], "%lf", &y2);
    if (n == 1)
    {
        Point P0 = {x1, y1};
        Point P1 = {x2, y2};

        Contour c = creer_liste_Point_vide();
        ajouter_element_liste_Point(&c, P0);
        ajouter_element_liste_Point(&c, P1);

        printf("P0= %.1lf,%.1lf\n", P0.x, P0.y);
        printf("P1= %.1lf,%.1lf\n\n", P1.x, P1.y);
        Tableau_Point tab_c = sequence_points_liste_vers_tableau(c);
        Bezier3 B = approx_bezier3(tab_c, 0, 1);
        printf("C0= %.1lf,%.1lf\n", B.C0.x, B.C0.y);
        printf("C1= %.1lf,%.1lf\n", B.C1.x, B.C1.y);
        printf("C2= %.1lf,%.1lf\n", B.C2.x, B.C2.y);
        printf("C3= %.1lf,%.1lf\n", B.C3.x, B.C3.y);
        return 0;
    }
    if (argc < 8 && n >= 2)
    {
        printf("ERREUR. Usage : <n><x1><y1><x2><y2><x3><y3>\n");
        return 1;
    }
    double x3, y3;
    sscanf(argv[6], "%lf", &x3);
    sscanf(argv[7], "%lf", &y3);
    if (n == 2)
    {
        Point P0 = {x1, y1};
        Point P1 = {x2, y2};
        Point P2 = {x3, y3};
        Contour c = creer_liste_Point_vide();
        ajouter_element_liste_Point(&c, P0);
        ajouter_element_liste_Point(&c, P1);
        ajouter_element_liste_Point(&c, P2);

        printf("P0= %.1lf,%.1lf\n", P0.x, P0.y);
        printf("P1= %.1lf,%.1lf\n", P1.x, P1.y);
        printf("P2= %.1lf,%.1lf\n\n", P2.x, P2.y);

        Tableau_Point tab_c = sequence_points_liste_vers_tableau(c);
        Bezier3 B = approx_bezier3(tab_c, 0, 2);
        printf("C0= %.1lf,%.1lf\n", B.C0.x, B.C0.y);
        printf("C1= %.1lf,%.1lf\n", B.C1.x, B.C1.y);
        printf("C2= %.1lf,%.1lf\n", B.C2.x, B.C2.y);
        printf("C3= %.1lf,%.1lf\n", B.C3.x, B.C3.y);
        return 0;
    }

    if (argc < 10 && n > 2)
    {
        printf("ERREUR. Usage : <n><x1><y1><x2><y2><x3><y3><x4><y4>\n");
        return 1;
    }

    if(n>2){
        double x4, y4;
        sscanf(argv[8], "%lf", &x4);
        sscanf(argv[9], "%lf", &y4);
        Point Q0 = {x1, y1};
        Point Q1 = {x2, y2};
        Point Q2 = {x3, y3};
        Point Q3 = {x4, y4};
        printf("Q0= %.1lf,%.1lf\n", Q0.x, Q0.y);
        printf("Q1= %.1lf,%.1lf\n", Q1.x, Q1.y);
        printf("Q2= %.1lf,%.1lf\n", Q2.x, Q2.y);
        printf("Q3= %.1lf,%.1lf\n", Q3.x, Q3.y);
        Bezier3 B;
        B.C0 = Q0;
        B.C1 = Q1;
        B.C2 = Q2;
        B.C3 = Q3;
        Contour c = creer_liste_Point_vide();
        for (int i = 0; i <= n; i++)
        {
            Point Pi = calcul_point_bezier3(B, (float)i / (float)n);
            ajouter_element_liste_Point(&c, Pi);
        }
        Tableau_Point tab_c = sequence_points_liste_vers_tableau(c);
        Bezier3 B3 = approx_bezier3(tab_c, 0, n);
        printf("C0= %.1lf,%.1lf\n", B3.C0.x, B3.C0.y);
        printf("C1= %.1lf,%.1lf\n", B3.C1.x, B3.C1.y);
        printf("C2= %.1lf,%.1lf\n", B3.C2.x, B3.C2.y);
        printf("C3= %.1lf,%.1lf\n", B3.C3.x, B3.C3.y);
    }
}