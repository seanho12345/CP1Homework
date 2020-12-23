#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "reun.h"

int32_t data[10]={0},last=0,rear=0;
void isfull(){
    if(rear == 10){
        for(int32_t i=0;i<8;i++){
            data[i] = data[i+1];
        }
        rear--;
    }
}
void actionpush(int32_t input){
    if(input == 0){
        return;
    }else if(input == -1 && rear > 0){
        rear--;
    }else if(input == -2 && last != 0){
        isfull();
        data[rear] = last;
        rear++;
    }else{
        isfull();
        data[rear] = input;
        last = input;
        rear++;
    }
}

void printaction(){
    for(int32_t i=0; i<rear; i++){
        printf("%d ",data[i]);
    }
}
