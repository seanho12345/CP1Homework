#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "linearreg.h"

void reg(double points[][2],int32_t point){
    double xbar=0.0, ybar=0.0;
    double sxy=0.0, sxx=0.0;
    for(int32_t i=0;i<point;i++){
        xbar += points[i][0];
        ybar += points[i][1];
    }
    xbar /= point;
    ybar /= point;
    for(int32_t i=0;i<point;i++){
        sxy += (points[i][0]-xbar)*(points[i][1]-ybar);
        sxx += pow((points[i][0]-xbar),2);
    }
    double b = sxy/sxx;
    double a = -b * xbar + ybar;
    printf("y = %lf x",b);
    if(a > 0){
        printf(" + %lf",a);
    }else if(a < 0){
        printf(" - %lf",fabs(a));
    }
}
