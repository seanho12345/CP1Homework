#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "test.h"
#include "iseven.h"
#define DEBUG 0
int main(){
    int32_t odd[array_size], even[array_size];
    int32_t odd_rear = 0, even_rear = 0;
    printf("Before:\n");
    for(int32_t i=0; i<array_size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    for(int32_t i=0; i<array_size; i++){
        if(iseven(array[i])){
            even[even_rear] = array[i];
            even_rear++;
        }else{
            odd[odd_rear] = array[i];
            odd_rear++;
        }
    }
    if(DEBUG == 1){
        for(int32_t i=0; i<odd_rear; i++){
            printf("%d ",odd[i]);
        }
        for(int32_t i=0; i<even_rear; i++){
            printf("%d ",even[i]);
        }
        printf("\n");
    }
    for(int32_t i=0; i<odd_rear-1; i++){
        for(int32_t j=0;j<odd_rear-1; j++){
            if(odd[j]>odd[j+1]){
                int32_t tmp = odd[j];
                odd[j] = odd[j+1];
                odd[j+1] = tmp;
            }
        }
    }
    for(int32_t i=0; i<even_rear-1; i++){
        for(int32_t j=0;j<even_rear-1; j++){
            if(even[j]<even[j+1]){
                int32_t tmp = even[j];
                even[j] = even[j+1];
                even[j+1] = tmp;
            }
        }
    }
    printf("After:\n");
    for(int32_t i=0; i<odd_rear; i++){
        printf("%d ",odd[i]);
    }
    for(int32_t i=0; i<even_rear; i++){
        printf("%d ",even[i]);
    }
    printf("\n");
    return 0;
}
