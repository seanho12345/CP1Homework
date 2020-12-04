#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "deter.h"
int32_t deter3(int32_t arr[3][3]){
    return arr[0][0]*(arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2]) -
           arr[0][1]*(arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]) +
           arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);
}
int32_t deter(int32_t matrix[4][4]){
    int32_t arr1[3][3] = {{matrix[1][1],matrix[1][2],matrix[1][3]},
                          {matrix[2][1],matrix[2][2],matrix[2][3]},
                          {matrix[3][1],matrix[3][2],matrix[3][3]}};
    int32_t arr2[3][3] = {{matrix[1][0],matrix[1][2],matrix[1][3]},
                          {matrix[2][0],matrix[2][2],matrix[2][3]},
                          {matrix[3][0],matrix[3][2],matrix[3][3]}};
    int32_t arr3[3][3] = {{matrix[1][0],matrix[1][1],matrix[1][3]},
                          {matrix[2][0],matrix[2][1],matrix[2][3]},
                          {matrix[3][0],matrix[3][1],matrix[3][3]}};
    int32_t arr4[3][3] = {{matrix[1][0],matrix[1][1],matrix[1][2]},
                          {matrix[2][0],matrix[2][1],matrix[2][2]},
                          {matrix[3][0],matrix[3][1],matrix[3][2]}};
    return matrix[0][0]*deter3(arr1) - matrix[0][1]*deter3(arr2) +
           matrix[0][2]*deter3(arr3) - matrix[0][3]*deter3(arr4);
}
