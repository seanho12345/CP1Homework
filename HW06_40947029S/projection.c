#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projection.h"

void project( double *x, double *y, double *z, int32_t a, int32_t b, int32_t c, int32_t d ){
    double t = (-(*x*a+*y*b+*z*c)-d)/(a*a+b*b+c*c);
    *x = *x + a*t;
    *y = *y + b*t;
    *z = *z + c*t;
}
