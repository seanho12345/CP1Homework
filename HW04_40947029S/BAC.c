#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "BAC.h"

#define DEBUG 0
//Check if the input number is valid
int32_t checknum(int32_t num){
    int32_t digits[4]={0};
    if(num>=10000 || num<=100){
        return 0;
    }else{
        for(int32_t i=0; i<4; i++){
            digits[i] = num%10;
            num/=10;
        }
        for(int32_t i=0; i<4; i++){
            for(int32_t j=0; j<4; j++){
                if(i!=j){
                    if(digits[i]==digits[j]){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}
//Check if the guess number is correct
int32_t checkans(int32_t *ans,int32_t num){
    int32_t digits[4]={0},correct = 0;
    for(int32_t i=3; i>=0; i--){
        digits[i] = num%10;
        num/=10;
    }
    int32_t a=0,b=0;
    if (DEBUG == 1){
        for(int32_t i=0; i<4; i++){
            printf("%d", digits[i]);
        }
        printf("\n");
        printf("%p: %d\n",ans,*ans);
    }
    for(int32_t i=0; i<4; i++){
        if(*ans == digits[i]){
            a++;
        }
        if(a == 4){
            correct = 1;
        }
        ans++;
    }
    if (DEBUG == 1){
        printf("%p: %d\n",ans,*ans);
    }
    ans -= 4;
    if (DEBUG == 1){
        printf("%p: %d\n",ans,*ans);
    }
    for(int32_t i=0; i<4; i++){
        for(int32_t j=0; j<4; j++){
            if(i!=j){
                if(*ans == digits[j]){
                    b++;
                }
            }
        }
        ans++;
    }
    if(a >= 0 && a < 4){
        printf("%d A ",a);
    }
    if(b >= 0 && b <= 4 && a != 4){
        printf("%d B",b);
    }
    if(correct != 1){
        printf("\n");
    }
    return correct;
}
