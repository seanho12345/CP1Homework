#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "rotate.h"

void rotate(double *x,double *y,double theta){
    double postx,posty;
    theta = M_PI*-theta/180;
    postx = cos(theta)* *x + sin(theta)*(-1)* *y;
    posty = sin(theta)* *x + cos(theta)* *y;
    *x = postx;
    *y = posty;
}
