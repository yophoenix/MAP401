#include <stdio.h>
#include "image.h"
#include "geometrie2d.h"

int main(int argc, char** argv){
	if (argc < 7){
		printf("ERREUR. Usage : <xA> <yA> <xB> <yB> <xP> <yP>\n");
		return 1;
	}
	Point A = {(double) *argv[1],(double) *argv[2]},
		  B = {(double) *argv[3],(double) *argv[4]},
		  P = {(double) *argv[5],(double) *argv[6]};
	double d = distance_segment(A,B,P);
	printf("La distance entre le point P = {%s,%s} et le segment [A,B] est de %5.1lf.\n",argv[5],argv[6],d);
	return 0;
}
