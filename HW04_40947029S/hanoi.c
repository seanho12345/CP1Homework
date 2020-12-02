#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "hanoi.h"

void hanoire(int32_t d,int32_t from,int32_t to,int32_t aux){
    if(d == 1){
        printf("move disk 1 to rod %d\n",to);
        return;
    }
    hanoire(d-1, from, aux, to);
    printf("move disk %d to rod %d\n",d,to);
    hanoire(d-1, aux, to, from);
}

void hanoiloop(int32_t d,int32_t from,int32_t to,int32_t aux){
    if(d%2 == 0){
        int32_t tmp = to;
        to = aux;
        aux = tmp;
    }
    int32_t from_pole[d],from_rear = d;
    int32_t to_pole[d],to_rear=-0;
    int32_t aux_pole[d],aux_rear=0;
    for(int32_t i=d-1; i>=0; i--){
        from_pole[i] = d-i;
    }
    for(int32_t i=1; i<=pow(2,d)-1; i++){
        if(i%3 == 2){
            if(from_pole[from_rear-1]<aux_pole[aux_rear-1] || aux_rear == 0){
                printf("move disk %d to rod %d\n",from_pole[from_rear-1],aux);
                aux_pole[aux_rear] = from_pole[from_rear-1];
                aux_rear++;
                from_pole[from_rear-1] = 0;
                from_rear--;
            }else if(aux_pole[aux_rear-1]<from_pole[from_rear-1] ||from_rear == 0){
                printf("move disk %d to rod %d\n",aux_pole[aux_rear-1],from);
                from_pole[from_rear] = aux_pole[aux_rear-1];
                from_rear++;
                aux_pole[aux_rear-1] = 0;
                aux_rear--;
            }

        }else if(i%3 == 1){
            if(from_pole[from_rear-1]<to_pole[to_rear-1] || to_rear == 0){
                printf("move disk %d to rod %d\n",from_pole[from_rear-1],to);
                to_pole[to_rear] = from_pole[from_rear-1];
                to_rear++;
                from_pole[from_rear-1] = 0;
                from_rear--;
            }else if(to_pole[to_rear-1]<from_pole[from_rear-1] || from_rear == 0){
                printf("move disk %d to rod %d\n",to_pole[to_rear-1],from);
                from_pole[from_rear] = to_pole[aux_rear-1];
                from_rear++;
                to_pole[to_rear-1] = 0;
                to_rear--;
            }
        }else if(i%3 == 0){
            if(aux_pole[aux_rear-1]<to_pole[from_rear-1] || to_rear == 0){
                printf("move disk %d to rod %d\n",aux_pole[aux_rear-1],to);
                to_pole[to_rear] = aux_pole[aux_rear-1];
                to_rear++;
                aux_pole[aux_rear-1] = 0;
                aux_rear--;
            }else if(to_pole[to_rear-1]<aux_pole[aux_rear-1] || aux_rear == 0){
                printf("move disk %d to rod %d\n",to_pole[to_rear-1],aux);
                aux_pole[aux_rear] = to_pole[to_rear-1];
                aux_rear++;
                to_pole[to_rear-1] = 0;
                to_rear--;
            }

        }
    }
}
