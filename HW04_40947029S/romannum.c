#include <stdio.h>
#include <stdlib.h>
#include "romannum.h"
void romannum(int32_t num){
    int32_t numbers[4]={0};
    for(int32_t i=0;i<4;i++){
        numbers[i] = num%10;
        num /= 10;
    }
    if(numbers[3]!=0){
        if(numbers[3]==1)
            printf("M");
        else if(numbers[3]==2)
            printf("MM");
        else if(numbers[3]==3)
            printf("MMM");
    }
    if(numbers[2]!=0){
        if(numbers[2]==1){
            printf("C");
        }else if(numbers[2]==2){
            printf("CC");
        }else if(numbers[2]==3){
            printf("CCC");
        }else if(numbers[2]==4){
            printf("CD");
        }else if(numbers[2]==5){
            printf("CC");
        }else if(numbers[2]==6){
            printf("CC");
        }else if(numbers[2]==7){
            printf("DC");
        }else if(numbers[2]==8){
            printf("DCCC");
        }else if(numbers[2]==9){
            printf("CM");
        }
    }
    if(numbers[1]!=0){
        if(numbers[1]==1){
            printf("X");
        }else if(numbers[1]==2){
            printf("XX");
        }else if(numbers[1]==3){
            printf("XXX");
        }else if(numbers[1]==4){
            printf("XL");
        }else if(numbers[1]==5){
            printf("L");
        }else if(numbers[1]==6){
            printf("LX");
        }else if(numbers[1]==7){
            printf("LXX");
        }else if(numbers[1]==8){
            printf("LXXX");
        }else if(numbers[1]==9){
            printf("XC");
        }
    }
    if(numbers[0]!=0){
        if(numbers[0]==1){
            printf("I");
        }else if(numbers[0]==2){
            printf("II");
        }else if(numbers[0]==3){
            printf("III");
        }else if(numbers[0]==4){
            printf("IV");
        }else if(numbers[0]==5){
            printf("V");
        }else if(numbers[0]==6){
            printf("VI");
        }else if(numbers[0]==7){
            printf("VII");
        }else if(numbers[0]==8){
            printf("VIII");
        }else if(numbers[0]==9){
            printf("IX");
        }
    }
}
