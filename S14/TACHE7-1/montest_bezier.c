#include <stdio.h>
#include <stdlib.h>
#include "geometrie2d.h"

int main(int argc, char** argv){
	int arg;
	sscanf(argv[1],"%d",&arg);
	double x1,x2,x3,y1,y2,y3,t;
	sscanf(argv[2],"%lf",&x1);
	sscanf(argv[3],"%lf",&y1);
	sscanf(argv[4],"%lf",&x2);
	sscanf(argv[5],"%lf",&y2);
	sscanf(argv[6],"%lf",&x3);
	sscanf(argv[7],"%lf",&y3);
	Point C0 = {x1,y1},
		  C1 = {x2,y2},
		  C2 = {x3,y3},
		  C;
	if (arg==2){
		sscanf(argv[8],"%lf",&t);
		Bezier2 B = {C0,C1,C2};
		printf("Point de la courbe de Bézier en %.1lf :\n",t);
		C = calcul_point_bezier2(B,t);
		printf("Le point C est de coord {%.1lf,%.1lf}\n",C.x,C.y);
		Bezier3 Bc = conversion_bezier2_vers_3(B);
		printf("La courbe de Bézier élevée au rang 3 est :\nC0 = {%.1lf,%.1lf}\nC1 = {%.1lf,%.1lf}\nC2 = {%.1lf,%.1lf}\nC3 = {%.1lf,%.1lf}\n",Bc.C0.x,Bc.C0.y,Bc.C1.x,Bc.C1.y,Bc.C2.x,Bc.C2.y,Bc.C3.x,Bc.C3.y);
	}
	else if (arg==3){
		double x4,y4;
		sscanf(argv[8],"%lf",&x4);
		sscanf(argv[9],"%lf",&y4);
		Point C3 = {x4,y4};
		sscanf(argv[10],"%lf",&t);
		Bezier3 B = {C0,C1,C2,C3};
		printf("Point de la courbe de Bézier en %.1lf :\n",t);
		C = calcul_point_bezier3(B,t);
		printf("Le point C est de coord {%.1lf,%.1lf}\n",C.x,C.y);
	}

	return 0;
}
