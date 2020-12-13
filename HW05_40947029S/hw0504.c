#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linearreg.h"

int main(){
    int32_t input;
    printf("Please enter the point number: ");
    scanf("%d", &input);
    double points[input][2];
    for(int32_t i=0;i<input;i++){
        printf("Please enter Point %d: ",i+1);
        scanf("%lf %lf",&points[i][0],&points[i][1]);
    }
    reg(points,input);
    return 0;
}
