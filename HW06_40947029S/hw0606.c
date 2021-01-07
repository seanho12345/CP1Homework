#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    int32_t count=0;
    int32_t a[3][3]={0};
    int32_t *b[3];
    for(int32_t i=0;i<3;i++){
        for(int32_t j=0;j<3;j++){
            a[i][j] = count;
            count++;
        }
    }
    for(int32_t i=0;i<3;i++){
        for(int32_t j=0;j<3;j++){
            printf("%d ",a[i][j]);
            printf("%p",&a[i][j]);
            printf("\n");
        }
    }
    count = 0;
    for(int32_t i=0;i<3;i++){
        b[i] = malloc(sizeof(int32_t) * 3);
        for(int32_t j=0;j<3;j++){
            b[i][j] = count;
            count++;
        }
    }
    for(int32_t i=0;i<3;i++){
        for(int32_t j=0;j<3;j++){
            printf("%d ",b[i][j]);
            printf("%p",&b[i][j]);
            printf("\n");
        }
    }
    for(int32_t i=0;i<3;i++){
        free(b[i]);
    }
    return 0;
}