#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hanoi.h"

int main(){
    int32_t disk,valid = 1;
    printf("Please enter the disk number (2-20):");
    valid = scanf("%d",&disk);
    if(disk > 20 || disk < 2){
        valid = 0;
    }
    if(valid == 0){
        printf("Invalid Input. Terminating...\n");
        return 0;
    }
    hanoiloop(disk,1,2,3);
    return 0;
}
