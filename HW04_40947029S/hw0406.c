#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    int32_t printre,scanre,input;
    printre = printf("This length of this sentence is 55 (including newline)\n");
    printf("printf return value:%d\n",printre);
    printf("Enter an integer:");
    scanre = scanf("%d",&input);
    printf("scanf return value:%d\n",scanre);
    printf("Enter an non-integer:");
    scanre = scanf("%d",&input);
    printf("scanf return value:%d\n",scanre);
    return 0;
}
