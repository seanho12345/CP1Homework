#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "reun.h"

int main(){
    int input = 1;
    while(input != 0){
        printf("input: ");
        scanf("%d", &input);
        actionpush(input);
    }
    printf("Result: ");
    printaction();
    printf("\n");
    return 0;
}
