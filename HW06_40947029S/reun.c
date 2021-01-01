#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "reun.h"

int32_t data[10]={0},undo[10]={0},undotime=0,rear=0;
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
        undo[undotime] = data[rear-1];
        rear--;
        undotime++;
    }else if(input == -2 && undotime != 0){
        isfull();
        data[rear] = undo[undotime-1];
        rear++;
        undotime--;
    }else if(input != -1 && input != -2){
        isfull();
        if(undotime>0){
            for(int32_t i=0;i<10;i++){
                undo[i] = 0;
                undotime = 0;
            }
        }
        data[rear] = input;
        rear++;
    }
}

void printaction(){
    for(int32_t i=0; i<rear; i++){
        printf("%d ",data[i]);
    }
}
