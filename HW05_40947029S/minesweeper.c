#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "minesweeper.h"

#define ANSI_TITLE "\033[7;32m"
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[1;31m"
#define ANSI_ERROR "\033[7;31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_CYAN_BACK "\033[7;35m"
#define ANSI_YELLOW "\033[0;33m"
#define DEBUG 0

int32_t checkvalid(int32_t valid,int32_t input,int32_t min,int32_t max){
    if(input > max || input < min){
        valid = 0;
    }
    if(valid == 0){
        printf(ANSI_ERROR "Input Invalid. Please re-input.\n" ANSI_RESET);
    }
    return valid;
}
void ptrplus(int32_t *ptr, int32_t minew, int32_t mineh, int32_t w,int32_t h){
    *((ptr + mineh*w) + minew) = *((ptr + mineh*w) + minew)+1;
} //pointer value++

int32_t ptrvalue(int32_t *ptr, int32_t minew, int32_t mineh, int32_t w,int32_t h){
    return *((ptr + mineh*w) + minew);
} //return value in data array using x,y cordinate

void generatemine(int32_t num,int32_t w,int32_t h,int32_t *target_ptr){
    srand(time(NULL));
    for(int32_t n=0; n<num; n++){
        int32_t minew = rand()%w, mineh = rand()%h;
        if(ptrvalue(target_ptr,minew,mineh,w,h) == -1){
            n--;
            continue;
        }else{
            *((target_ptr + mineh*w) + minew) = -1;
            if(minew-1 >= 0){       //Check if upper,upper-left,upper-right is oob or bomb inside
                if(mineh-1 >= 0){                                                   //upper-left
                    if(ptrvalue(target_ptr,minew-1,mineh-1,w,h) != -1){
                        ptrplus(target_ptr,minew-1,mineh-1,w,h);
                    }

                }
                if(mineh+1 < w){                                                    //upper-right
                    if(ptrvalue(target_ptr,minew-1,mineh+1,w,h) != -1){
                        ptrplus(target_ptr,minew-1,mineh+1,w,h);
                    }
                }
                if(ptrvalue(target_ptr,minew-1,mineh,w,h) != -1){                   //upper
                    ptrplus(target_ptr,minew-1,mineh,w,h);
                }
            }
            if(minew+1 < h){        //Check if lower,lower-left,lower-right is oob or bomb inside
                if(mineh-1 >= 0){                                                   //lower-left
                    if(ptrvalue(target_ptr,minew+1,mineh-1,w,h) != -1){
                        ptrplus(target_ptr,minew+1,mineh-1,w,h);
                    }
                }
                if(mineh+1 < w){                                                    //lower-right
                    if(ptrvalue(target_ptr,minew+1,mineh+1,w,h) != -1){
                        ptrplus(target_ptr,minew+1,mineh+1,w,h);
                    }
                }
                if(ptrvalue(target_ptr,minew+1,mineh,w,h) != -1){                   //lower
                    ptrplus(target_ptr,minew+1,mineh,w,h);
                }

            }
            if(mineh-1 >= 0){                                                       //middle-left
                if(ptrvalue(target_ptr,minew,mineh-1,w,h) != -1){
                    ptrplus(target_ptr,minew,mineh-1,w,h);
                }
            }
            if(mineh+1 < w){                                                        //middle-right
                if(ptrvalue(target_ptr,minew,mineh+1,w,h) != -1){
                    ptrplus(target_ptr,minew,mineh+1,w,h);
                }
            }
        }
    }
}

void printmap(int32_t w,int32_t h,int32_t *data_ptr,int32_t *mask_ptr){
    printf("    ");
    for(int32_t i=0;i<w;i++){
        printf(ANSI_YELLOW "%02d  " ANSI_RESET  , i);
    }
    printf(ANSI_YELLOW "\n-------------------------------------------" ANSI_RESET);
    for(int32_t i=w-10;i>0;i--){
        printf("----");
    }
    printf("\n");
    for(int32_t j=0;j<h;j++){
        printf(ANSI_YELLOW "%02d| " ANSI_RESET, j);
        for(int32_t i=0;i<w;i++){
            if(ptrvalue(mask_ptr,i,j,w,h) == 0){
                if(ptrvalue(data_ptr,i,j,w,h) == -1){
                    printf(ANSI_RED " M  " ANSI_RESET);
                }else{
                    printf(" %d  ",ptrvalue(data_ptr,i,j,w,h));
                }
            }else if(ptrvalue(mask_ptr,i,j,w,h) == 2){
                printf(ANSI_CYAN_BACK " F " ANSI_RESET);
                printf(" ");
            }else{
                printf(" *  ");
            }
        }
        printf("\n");
    }
}

void mapopen(int32_t xpos,int32_t ypos,int32_t w,int32_t h,int32_t *data_ptr, int32_t *mask_ptr){
    if(ptrvalue(data_ptr,xpos,ypos,w,h) > 0){
        *((mask_ptr + ypos*w) + xpos) = 0;
    }
}
