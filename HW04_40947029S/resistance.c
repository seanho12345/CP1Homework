#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "resistance.h"

double rcacu(int32_t r, int32_t n){
    double ans;
    if(n == 1){
        ans = r+r;
    }else{
        ans = r+(r*rcacu(r,n-1))/(r+rcacu(r,n-1));
    }
    return ans;
}
