#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point_2d{
    double x;
    double y;
};

struct point_2d point_2d_create(float x, float y){
    struct point_2d output;
    output.x = x;
    output.y = y;
    return output;
}

void point_2d_fill(struct point_2d * p, float x, float y) 
{
    p->x = x;
    p->y = y;
}



int point_2d_are_equal(struct point_2d * p1, struct point_2d * p2, float epsilon) 
{
    if (fabs(p1->x-p2->x)<epsilon && fabs(p1->y-p2->y)<epsilon){
        return 1;        
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 5){
        printf("Usage : 5 arguments \n");
        return 0;
    }
    double x1 = atof(argv[1]);
    double y1 = atof(argv[2]);
    double x2 = atof(argv[3]);
    double y2 = atof(argv[4]);
       
    struct point_2d point1 = point_2d_create(x1, y1);
    struct point_2d point2;
    point_2d_fill(&point2, x2, y2);

    if (point_2d_are_equal(&point1, &point2, 0.01)){
        printf("p1=(%lf,%lf) et p2=(%lf,%lf) sont egaux \n", point1.x, point1.y, point2.x, point2.y);
        }
    else
        printf("p1=(%lf,%lf) et p2=(%lf,%lf) ne sont pas egaux \n", point1.x, point1.y, point2.x, point2.y);    
    return 0;
}
