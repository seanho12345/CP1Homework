#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "minesweeper.h"

#define DEBUG 0

int main(){
    int32_t w,h,minenum,option,xpos,ypos,over=0;
    int32_t valid = 0;
    while(valid == 0){
        printf("Please enter the width       (10-16): ");
        valid = scanf("%d", &w);
        valid = checkvalid(valid,w,10,16);
    }
    valid = 0;
    while(valid == 0){
        printf("Please enter the height      (10-16): ");
        valid = scanf("%d", &h);
        valid = checkvalid(valid,h,10,16);
    }
    valid = 0;
    while(valid == 0){
        printf("Please enter the mine number (30-90): ");
        valid = scanf("%d", &minenum);
        valid = checkvalid(valid,minenum,30,90);
    }
    valid = 0;
    int32_t data[w][h],mask[w][h];
    for(int32_t i=0; i<w; i++){
        for(int32_t j=0; j<h; j++){
            mask[i][j] = 1;
            data[i][j] = 0;
        }
    }
    generatemine(minenum,w,h,(int32_t *)data);
    if(DEBUG == 1){
        for(int32_t i=0;i<w;i++){
            for(int32_t j=0;j<h;j++){
                printf("%d ",data[i][j]);
            }
            printf("\n");
        }
    }
    printmap(w,h,(int32_t *)data,(int32_t *)mask);
    while(over != 1){
        while(valid == 0){
            printf("Your Option (1:Open, 2: Flag): ");
            valid = scanf("%d", &option);
            valid = checkvalid(valid,option,1,2);
        }
        valid = 0;
        while(valid == 0){
            printf("Position (row,column): ");
            valid = scanf("%d %d",&xpos,&ypos);
            valid = checkvalid(valid,xpos,0,w-1);
            if(valid == 0){
                continue;
            }
            valid = checkvalid(valid,ypos,0,h-1);
        }
        valid = 0;
        if(option == 2){
            mask[xpos][ypos] = 2;
        }else if(option == 1){
            mapopen(xpos,ypos,w,h,(int32_t *)data,(int32_t *)mask);
        }
        printmap(w,h,(int32_t *)data,(int32_t *)mask);
    }

    return 0;
}

/*
Please enter the width (10-16): 10
Please enter the height (10-16): 10
Please enter the mine number (30-90): 10
   00 01 02 03 04 05 06 07 08 09
---------------------------------
00| * * * * * * * * * *
01| * * * * * * * * * *
02| * * * * * * * * * *
03| * * * * * * * * * *
04| * * * * * * * * * *
05| * * * * * * * * * *
06| * * * * * * * * * *
07| * * * * * * * * * *
08| * * * * * * * * * *
09| * * * * * * * * * *
Your Option (1:Open, 2: Flag): 1
Position (row,column): 0 1
*/
