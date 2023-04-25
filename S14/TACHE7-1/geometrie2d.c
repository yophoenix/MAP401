#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "geometrie2d.h"


Point set_point(double x, double y) {
	Point P = {x,y};
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

double distance_point(Point p1,Point p2){
    return sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
}

double distance_segment(Point a, Point b, Point p){
    if(a.x==b.x&&a.y==b.y){
        return distance_point(a, p);
    }
    Vecteur ap = vect_bipoint(a, p);
    Vecteur ab = vect_bipoint(a, b);
    double lambda = scalaire(ap, ab) / scalaire(ab, ab);
    if (lambda<0){
        return distance_point(a, p);
    }
    if(lambda>1){
        return distance_point(b, p);
    }
    Point q = {a.x + lambda * (b.x - a.x), a.y + lambda * (b.y - a.y)};
    return distance_point(q, p);
}

Point calcul_point_bezier2(Bezier2 B, double t){
	Point C;
	C.x = B.C0.x * pow((1 - t),2) + B.C1.x * 2*t * (1 - t) + B.C2.x * pow(t,2);
	C.y = B.C0.y * pow((1 - t),2) + B.C1.y * 2*t * (1 - t) + B.C2.y * pow(t,2);
	return C;
}

Point calcul_point_bezier3(Bezier3 B, double t){
	Point C;
	C.x = B.C0.x * pow((1 - t),3) + B.C1.x * 3*t * pow((1 - t),2) + B.C2.x * 3*pow(t,2) * (1 - t) + B.C3.x * pow(t,3);
	C.y = B.C0.y * pow((1 - t),3) + B.C1.y * 3*t * pow((1 - t),2) + B.C2.y * 3*pow(t,2) * (1 - t) + B.C3.y * pow(t,3);
	return C;
}

Bezier3 conversion_bezier2_vers_3(Bezier2 B){
	Bezier3 Bc;
	Bc.C0 = B.C0;
	Bc.C1.x = (B.C0.x + 2*B.C1.x) / 3;
	Bc.C1.y = (B.C0.y + 2*B.C1.y) / 3;
	Bc.C2.x = (B.C2.x + 2*B.C1.x) / 3;
	Bc.C2.y = (B.C2.y + 2*B.C1.y) / 3;
	Bc.C3 = B.C2;
	return Bc;
}

double distance_bezier2(Point p, Bezier2 B, double ti){
    Point C = calcul_point_bezier2(B, ti);
    double dist = distance_point(p, C);
    return dist;
}

