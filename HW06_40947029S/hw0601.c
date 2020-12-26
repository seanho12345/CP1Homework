#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    int64_t data;
    int32_t pos;
    int8_t change;
    uint8_t *ptr = (uint8_t *) &data;
    printf("Please input an integer: ");
    scanf("%ld",&data);
    while(pos!=0){
        printf("The integer: %ld\n",data);
        for(int32_t i=0;i<8;i++){
            printf("(%d) 0x%02X ",i+1,*(ptr+i));
        }
        printf("\nPlease enter the position (1-8, 0: End): ");
        scanf("%d", &pos);
        if(pos == 0){
            break;
        }
        printf("Please enter the new value (0-255): ");
        scanf("%hhi", &change);
        *(ptr+(pos-1)) = change;
    }
    return 0;
}
