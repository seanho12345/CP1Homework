#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "polynomial.h"
int main(){
    int32_t l1deg, l2deg,cmp;
    printf("Please enter p1 degree: ");
    scanf("%d",&l1deg);
    int32_t l1[l1deg+1];
    printf("Please enter p1 coefficients: ");
    for(int32_t i=l1deg; i>=0; i--){
        scanf("%d",&l1[i]);
    }
    printf("Please enter p2 degree: ");
    scanf("%d",&l2deg);
    int32_t l2[l2deg+1];
    printf("Please enter p2 coefficients: ");
    for(int32_t i=l2deg; i>=0; i--){
        scanf("%d",&l2[i]);
    }
    printf("p1: ");
    printpoly(l1,l1deg);
    printf("p2: ");
    printpoly(l2,l2deg);
    if(l1deg > l2deg){
        cmp = 1;
    }else if(l1deg == l2deg){
        cmp = 2;
    }else{
        cmp = 3;
    }
    printf("p1 + p2: ");
    pluspoly(l1,l1deg,l2,l2deg,cmp);
    printf("p1 - p2: ");
    minuspoly(l1,l1deg,l2,l2deg,cmp);
    printf("p1 * p2: ");
    multipoly(l1,l1deg,l2,l2deg,cmp);
    return 0;
}
