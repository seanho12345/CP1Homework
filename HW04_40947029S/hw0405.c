#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "BAC.h"

#define ANSI_TITLE "\033[7;32m"
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_ERROR "\033[7;31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_CYAN "\033[35m"
#define DEBUG 0

int main(){
    srand(time(NULL));
    int32_t validinput = 1,valid = 1,guessnum,ans[4]={-1},k=0;

    printf("\033[7;32mBulls and Cows Game\n" ANSI_RESET);

    //Get 4 digits answer
    while(k!=4){
        int32_t gendigit = rand()%10;
        int32_t duplicate=0;
        for(int32_t i=0; i<4; i++){
            if(ans[i] == gendigit){
                duplicate = 1;
                break;
            }else{
                duplicate = 0;
            }
        }
        if(duplicate == 0){
            ans[k] = gendigit;
            k++;
        }
    }
    if(DEBUG == 1){
        for(int32_t i=0; i<4; i++){
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    int32_t round = 1,correct = 0;
    while(correct!=1){
        printf("Round %d " ANSI_RED ">>>\n" ANSI_RESET,round);
        printf(ANSI_CYAN "    Your Guess: " ANSI_RESET);
        validinput = scanf("%d", &guessnum);
        printf(ANSI_CYAN "    Response: " ANSI_RESET);
        valid = checknum(guessnum);
        if(valid == 0 || validinput == 0){
            printf(ANSI_ERROR "Invalid Guess\n" ANSI_RESET);
            while(getchar() != '\n'); //Clean input buffer
        }else{
            correct = checkans(ans,guessnum);
        }

        round++;
    }
    printf(ANSI_GREEN "Bingo! Congratulations.\n" ANSI_RESET);
    return 0;

}
