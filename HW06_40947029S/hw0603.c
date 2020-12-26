#include <stdio.h>
#include <stdint.h>
#include "rotate.h"

int main(){
    double x,y,theta;
    printf("Please enter a point: ");
    scanf("%lf %lf",&x,&y);
    printf("Please enter theta (0-360): ");
    scanf("%lf",&theta);
    rotate(&x,&y,theta);
    printf("%lf %lf\n",x,y);
    return 0;
}
