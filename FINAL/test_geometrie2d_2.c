#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "geometrie2d.h"

int main(int argc, char* argv[]){
    if (argc < 7){
        printf("Erreur d'arguements, usage:\ntest_geometrie2d <cord p1 x><cord p1 y><cord p2 x><cord p2 y><scalaire1><scalaire2>\n");
        return 1;
    }
    char *temp;
    double x1 = strtod(argv[1], &temp), y1 = strtod(argv[2], &temp);
    double x2 = strtod(argv[3],&temp), y2 = strtod(argv[4],&temp);
    double a = strtod(argv[5],&temp), b = strtod(argv[6],&temp);

    Point p1 = set_point(x1, y1);
    if(p1.x==x1&&p1.y==y1){
        printf("point 1 créé avec succès: x1=%lf y1=%lf\n",p1.x,p1.y);
    }

    Point p2 = set_point(x2, y2);
    if (p2.x == x2 && p2.y == y2){
        printf("point 2 créé avec succès: x2=%lf y2=%lf\n",p2.x,p2.y);
    }
    Point p3 = add_point(p1, p2);
    if (p3.x == p1.x+p2.x && p3.y == p1.y+p2.y){
        printf("point 3 créé avec succès en additionnant p1 et p2: x3=%lf y3=%lf\n",p3.x,p3.y);
    }
    Point p4 = multiply_point(p2,a);
    if (p4.x == x2*a && p4.y == y2*a){
        printf("point 4 créé avec succès en multipliant p2 par %lf: x4=%lf y4=%lf\n\n",a,p4.x,p4.y);
    }

    Vecteur v1 = vect_bipoint(p1, p2);
    printf("le vecteur 1 est (%lf,%lf) \n", v1.x,v1.y);
    Vecteur v2 = vect_bipoint(p3, p4);
    printf("le vecteur 2 est (%lf,%lf) \n", v2.x, v2.y);
    Vecteur v3 = addition_vect(v1, v2);
    printf("le vecteur 3 est (%lf,%lf) créé par addition de v1 et v2 \n", v3.x, v3.y);
    Vecteur v4 = multiply_vect(v1, b);
    printf("le vecteur 4 est (%lf,%lf) créé par multiplication de v1 par %lf \n\n", b, v4.x, v4.y);

    double scal = scalaire(v1, v2);
    printf("le produit scalaire du vecteur 1 et 2 est %lf\n", scal);
    double nor = norme(v1);
    printf("la norme du vecteur 1 est %lf\n", nor);
    double dist = distance_point(p2, p4);
        printf("la distance entre p2 et p4 est %lf\n",dist);
}