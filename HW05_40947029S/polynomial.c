#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "polynomial.h"

#define DEBUG 0

void printpoly(int32_t poly[],int32_t size){
    int32_t first = 1,iszero = 1;
    for(int32_t i=size; i>=0; i--){
        if(poly[i] == 0){
            continue;
        }else{
            iszero = 0;
            if(poly[i] > 1){
                if(first == 1){
                    printf("%d",poly[i]);
                }else{
                    printf("+ %d",poly[i]);
                }
            }else if(poly[i]<-1){
                if(first == 1){
                    printf("- %d",abs(poly[i]));
                }else{
                    printf("- %d",abs(poly[i]));
                }
            }
        }
        if(poly[i] == 1 && i != 0 && first == 0){
            printf("+ x^%d ",i);
        }else if(poly[i] == -1 && i != 0){
            printf("- x^%d ",i);
        }else if(poly[i] == 1 && i == 0){
            printf("+ 1 ");
        }else if(poly[i] == -1 && i == 0){
            printf("- 1 ");
        }else if(i != 0){
            printf("x^%d ",i);
        }
        first = 0;
    }
    if(iszero == 1){
        printf("0");
    }
    printf("\n");
}

void pluspoly(int32_t l1[],int32_t l1deg,int32_t l2[],int32_t l2deg,int32_t cmp){
    if(cmp == 1 || cmp == 2){
        int32_t plus[l1deg+1],plussize = l1deg;
        for(int32_t i=l1deg; i>=0; i--){
            if(i > l2deg){
                plus[i] = l1[i];
            }else{
                plus[i] = l1[i] + l2[i];
            }
        }
        printpoly(plus,plussize);
    }else if(cmp == 3){
        int32_t plus[l2deg+1],plussize = l2deg;
        for(int32_t i=l2deg; i>=0; i--){
            if(i > l1deg){
                plus[i] = l2[i];
            }else{
                plus[i] = l1[i] + l2[i];
            }
        }
        printpoly(plus,plussize);
    }
}

void minuspoly(int32_t l1[],int32_t l1deg,int32_t l2[],int32_t l2deg,int32_t cmp){
    if(cmp == 1 || cmp == 2){
        int32_t plus[l1deg+1],plussize = l1deg;
        for(int32_t i=l1deg; i>=0; i--){
            if(i > l2deg){
                plus[i] = l1[i];
            }else{
                plus[i] = l1[i] - l2[i];
            }
        }
        printpoly(plus,plussize);
    }else if(cmp == 3){
        int32_t plus[l2deg+1],plussize = l2deg;
        for(int32_t i=l2deg; i>=0; i--){
            if(i > l1deg){
                plus[i] = l2[i];
            }else{
                plus[i] = l1[i] - l2[i];
            }
        }
        printpoly(plus,plussize);
    }
}

void multipoly(int32_t l1[],int32_t l1deg,int32_t l2[],int32_t l2deg,int32_t cmp){
    int32_t multi[l1deg+l2deg+1],multisize = l1deg+l2deg;
    for(int32_t i=0;i<l1deg+l2deg+1;i++){
        multi[i] = 0;
    }
    for(int32_t i=l1deg; i>=0; i--){
        for(int32_t j=l2deg; j>=0 ;j--){
            multi[i+j] += l1[i] * l2[j];
        }
    }
    if(DEBUG == 1){
        for(int32_t i=multisize;i>=0;i--){
            printf("%d ",multi[i]);
        }
        printf("\n");
    }

    printpoly(multi,multisize);
}
