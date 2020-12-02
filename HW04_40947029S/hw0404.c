#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "resistance.h"
int main(){
    int32_t r,n,valid=1;
    double ans;
    printf("Please enter the resistance (1-100):");
    valid = scanf("%d",&r);
    if(r>100 || r<1){
        valid = 0;
    }
    if(valid == 0){
        printf("Invalid Input. Terminating...\n");
        return 0;
    }
    printf("Please enter n (1-100):");
    valid = scanf("%d", &n);
    if(n<1 || n>100){
        valid = 0;
    }
    if(valid == 0){
        printf("Invalid Input. Terminating...\n");
        return 0;
    }
    ans = rcacu(r,n);
    printf("Ans:%lf\n",ans);
    return 0;
}
