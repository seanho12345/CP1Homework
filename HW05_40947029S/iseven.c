#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "iseven.h"

int32_t iseven(int32_t num){
    if(num%2 == 0){
        return 1;
    }else{
        return 0;
    }
}
