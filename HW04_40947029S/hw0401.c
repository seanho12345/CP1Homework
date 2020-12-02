#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "romannum.h"
int main(){
    int32_t input,valid=1;
    printf("Please enter an integer (1-3000):");
    valid = scanf("%d",&input);
    if(input<1 || input>3000)
        valid = 0;
    if(valid!=1){
        printf("Invalid Input. Terminating...\n");
    }else{
        printf("%d:",input);
        romannum(input);
        printf("\n");
    }
    return 0;
}
