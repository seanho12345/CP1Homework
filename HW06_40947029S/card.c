#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "card.h"

void print_card(const uint8_t cards[13]){
    int32_t invalid = 0;
    for(int32_t i=0;i<13;i++){
        for(int32_t j=0;j<13;j++){
            if(cards[i] == cards[j] && i!=j){
                invalid = 1;
            }
        }
    }
    if(invalid == 1){
        printf("ERROR!\n");
        return;
    }
    for(int32_t i=0;i<13;i++){
        printf("%d ",cards[i]);
    }
    printf("\n");
}
void sort_card( uint8_t cards[13], int32_t (*compare)( int32_t,int32_t) ){
    for(int32_t t=0;t<13;t++){
        for(int32_t i=0;i<13;i++){
            for(int32_t j=i;j<13;j++){
                if(compare(cards[i],cards[j])){
                    uint8_t tmp = cards[j];
                    cards[j] = cards[i];
                    cards[i] = tmp;
                }
            }
        }
    }

}
