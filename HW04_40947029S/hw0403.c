#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "taylor.h"

int main(){
    int32_t k,valid=1;
    double ans;
    printf("k-th order Taylor polynomial for e\n");
    printf("Please enter k:");
    valid = scanf("%d",&k);
    if(k<1){
        valid = 0;
    }
    if(valid == 0){
        printf("Invalid Input. Terminating...\n");
        return 0;
    }
    ans = taylor(k);
    printf("%lf\n",ans);
    return 0;
}
