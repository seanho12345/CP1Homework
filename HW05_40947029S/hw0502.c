#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "deter.h"
#include "test2.h"
int main(){
    printf("The matrix is:\n");
    for(int32_t i=0; i<4; i++){
        for(int32_t j=0; j<4; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    int32_t ans = deter(matrix);
    printf("The determinant is %d\n",ans );
}
