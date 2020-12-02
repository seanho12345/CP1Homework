#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "taylor.h"

double taylor(int32_t k){
    double result=1,factorial = 1;
    if(k==1){
        return 2;
    }
    for(int32_t i=1; i<=k; i++){
        factorial *= i;
    }
    result /= factorial;
    return result + taylor(k-1);
}
