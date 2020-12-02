#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "taylor.h"

int main(){
    for(int32_t i=1;i<=20;i++){
        printf("k=%d e=%.20lf\n",i,taylor(i));
    }
    return 0;
}
