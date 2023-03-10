#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "geometrie2d.h"


Point set_point(double x, double y){
    Point P = {x, y};
    return P;
}

Point add_point(Point P1, Point P2){
    return set_point(P1.x + P2.x, P1.y + P2.y);
}

Vecteur vect_bipoint(Point A, Point B){
    Vecteur V = {B.x - A.x, B.y - A.y};
    return V;
}

Vecteur addition_vect(Vecteur v1, Vecteur v2){
    Vecteur v = {v1.x + v2.x, v1.y + v2.y};
    return v;
}

Vecteur multiply_vect(Vecteur v1, double a){
    Vecteur v = {v1.x * a, v1.y * a};
    return v;
}

Point multiply_point(Point p1, double a){
    Point p = {p1.x * a, p1.y * a};
    return p;
}

double scalaire(Vecteur v1, Vecteur v2){
    return v1.x * v2.x + v1.y * v2.y;
}

double norme(Vecteur v){
    return sqrt(pow(v.x,2) +pow(v.y,2));
}

double distance(Point p1,Point p2){
    return sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
}