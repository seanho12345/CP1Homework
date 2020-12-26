#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "test.h"
#include "card.h"
int32_t func01(int32_t a,int32_t b){
    a%=13;
    b%=13;
    if(a==0){
        a = 13;
    }
    if(b==0){
        b = 13;
    }
    return a < b;
}
int32_t func02(int32_t a,int32_t b){
    a%=13;
    b%=13;
    if(a==0){
        a = 13;
    }
    if(b==0){
        b = 13;
    }
    return a < b || b == 2;
}
int32_t func03(int32_t a,int32_t b){
    int32_t asuit,avalue,bsuit,bvalue;
    asuit = a/13;
    avalue = a%13;
    bsuit = b/13;
    bvalue = b%13;
    if(avalue == 0){
        avalue = 13;
        asuit--;
    }
    if(bvalue == 0){
        bvalue = 13;
        bsuit--;
    }
    if(bsuit<asuit){
        return 1;
    }else if(bvalue>avalue && bsuit==asuit){
        return 1;
    }else if(bvalue==1 && bsuit==asuit){
        return 1;
    }
    return 0;
}
int main(){
    printf("Before:\n");
    print_card(player1);
    print_card(player2);
    print_card(player3);
    print_card(player4);
    printf("Type 01:\n");
    sort_card(player1, func01);
    sort_card(player2, func01);
    sort_card(player3, func01);
    sort_card(player4, func01);
    print_card(player1);
    print_card(player2);
    print_card(player3);
    print_card(player4);
    printf("Type 02:\n");
    sort_card(player1, func02);
    sort_card(player2, func02);
    sort_card(player3, func02);
    sort_card(player4, func02);
    print_card(player1);
    print_card(player2);
    print_card(player3);
    print_card(player4);
    printf("Type 03:\n");
    sort_card(player1, func03);
    sort_card(player2, func03);
    sort_card(player3, func03);
    sort_card(player4, func03);
    print_card(player1);
    print_card(player2);
    print_card(player3);
    print_card(player4);
    return 0;
}
