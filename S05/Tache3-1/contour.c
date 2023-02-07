#include <stdio.h>  /* utilisation des entr�es-sorties standard de C */
#include <stdlib.h> /* utilisation des fonctions malloc et free */
#include "contour.h"


Point set_point(double x, double y)
{
    Point P = {x, y};
    return P;
}

Point trouve_pixel_init(Image I){
    UINT h = 1;
    UINT l = 1;
    UINT L = largeur_image(I);
    UINT H = hauteur_image(I);
    Point pixel_init = {0, 0};
    while ((h <= H) && (pixel_init.x == 0)){
        while((l<=L) && (pixel_init.x==0)){
            if (get_pixel_image(I, l, h)){
                pixel_init.x = l;
                pixel_init.y = h;
            }
            l++;
        }
        l = 1;
        h++;
    }
    if(pixel_init.x==0){
        printf("Pas de pixel initial de contour trouvé\n");
    }
    return pixel_init;
}

void calcul_contour(Image I,Point pixel_init){
    Point pos_init = set_point(pixel_init.x-1, pixel_init.y-1);
    Point position = pos_init;
    Orientation orientation = Est;
    int fin = 0;
    while (!fin)
    {
        memoriser_position(position);
        position = avancer(position, orientation);
        orientation = nouvelle_orientation(I,position, orientation);
        if (position.x==pos_init.x&&position.y==pos_init.y&&orientation==Est){
            fin = 1;
        }
    }
    memoriser_position(position);
}

void memoriser_position(Point position){
    printf("Un point du contour est (%lf;%lf)\n", position.x, position.y);
}

Point avancer(Point position, Orientation orientation)
{
    switch (orientation){
        case Nord:
            position.y--;
            break;
        case Est:
            position.x++;
            break;
        case Sud:
            position.y++;
            break;
        case Ouest:
            position.x--;
            break;
    }
    return position;
}

Orientation nouvelle_orientation(Image I,Point position, Orientation orientation){
    Pixel pD;
    Pixel pG;
    switch (orientation){
        case Nord:
            pD = get_pixel_image(I, position.x + 1, position.y);
            pG = get_pixel_image(I, position.x, position.y);
            break;
        case Est:
            pD = get_pixel_image(I, position.x + 1, position.y + 1);
            pG = get_pixel_image(I, position.x + 1, position.y);
            break;
        case Sud:
            pD = get_pixel_image(I, position.x, position.y + 1);
            pG = get_pixel_image(I, position.x + 1, position.y + 1);
            break;
        case Ouest:
            pD = get_pixel_image(I, position.x, position.y);
            pG = get_pixel_image(I, position.x, position.y + 1);
            break;
    }
    if (pG){
        orientation = (orientation + 3) % 4;
    }
    else{  
        if(!pD){
            orientation = (orientation + 1) % 4;
        }
    }
    return orientation;
}
