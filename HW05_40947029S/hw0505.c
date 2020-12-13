#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "minesweeper.h"

#define DEBUG 0
#define ANSI_RED "\033[1;31m"
#define ANSI_RESET "\033[0m"
#define ANSI_GREEN "\033[1;32m"

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
    int32_t data[h][w],mine[h][w],mask[h][w],fmask[h][w];
    for(int32_t i=0; i<h; i++){
        for(int32_t j=0; j<w; j++){
            fmask[i][j] = 0;
            mask[i][j] = 1;
            data[i][j] = 0;
            mine[i][j] = 0;
        }
    }
    generatemine(minenum,w,h,(int32_t *)data,(int32_t *)mine);
    if(DEBUG == 1){
        for(int32_t i=0;i<w;i++){
            for(int32_t j=0;j<h;j++){
                printf("%d ",data[i][j]);
            }
            printf("\n");
        }
    }
    //printmap(w,h,(int32_t *)data,(int32_t *)fmask,(int32_t *)fmask);
    printmap(w,h,(int32_t *)data,(int32_t *)mask,(int32_t *)fmask);
    while(over == 0){
        while(valid == 0){
            printf("Your Option (1:Open, 2: Flag): ");
            valid = scanf("%d", &option);
            valid = checkvalid(valid,option,1,2);
        }
        valid = 0;
        while(valid == 0){
            printf("Position (row,column): ");
            valid = scanf("%d %d",&ypos,&xpos);
            valid = checkvalid(valid,xpos,0,w-1);
            if(valid == 0){
                continue;
            }
            valid = checkvalid(valid,ypos,0,h-1);
        }
        valid = 0;
        if(option == 2){
            if(fmask[ypos][xpos] == 1){
                fmask[ypos][xpos] = 0;
            }else{
                fmask[ypos][xpos] = 1;
            }
            over = checkflag(w,h,(int32_t *)fmask,(int32_t *)mine);
        }else if(option == 1){
            int32_t checked[h][w];
            for(int32_t i=0;i<h;i++){
                for(int32_t j=0;j<w;j++){
                    checked[i][j] = 0;
                }
            }
            over = mapopen(xpos,ypos,w,h,(int32_t *)data,(int32_t *)mask,(int32_t *)checked);
        }
        if(over == 0){
            printmap(w,h,(int32_t *)data,(int32_t *)mask,(int32_t *)fmask);
        }

    }
    for(int32_t i=0; i<w; i++){
        for(int32_t j=0; j<h; j++){
            mask[i][j] = 0;
            fmask[i][j] = 0;
        }
    }
    printmap(w,h,(int32_t *)data,(int32_t *)mask,(int32_t *)fmask);
    if(over == 1){
        printf(ANSI_RED "-----------------------\n" ANSI_RESET);
        printf(ANSI_RED "| GAME OVER,You Lose! |\n" ANSI_RESET);
        printf(ANSI_RED "-----------------------\n" ANSI_RESET);
    }else if(over == 2){
        printf(ANSI_GREEN "-----------------------\n" ANSI_RESET);
        printf(ANSI_GREEN "| GAME OVER,You WIN!  |\n" ANSI_RESET);
        printf(ANSI_GREEN "-----------------------\n" ANSI_RESET);
    }
    return 0;
}
