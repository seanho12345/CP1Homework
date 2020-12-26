#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "projection.h"

int main(){
    int32_t a,b,c,d;
    printf("Please enter the plane: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("The plane is: ");
    if(a>0){
        printf("%dx ",a);
    }else if(a<0){
        printf("- %dx ",abs(a));
    }
    if(b>0 && a==0){
        printf("%dy ",b);
    }else if(b>0){
        printf("+ %dy ",b);
    }else if(b<0){
        printf("- %dy ",abs(b));
    }
    if(c>0 && a==0 && b==0){
        printf("%dz ",c);
    }else if(c>0){
        printf("+ %dz ",c);
    }else if(c<0){
        printf("- %dz ",abs(c));
    }
    if(d>0){
        printf("+ %d ",d);
    }else if(d<0){
        printf("- %d ",abs(d));
    }
    printf("= 0\n");
    double x,y,z;
    printf("Please enter the point: ");
    scanf("%lf %lf %lf",&x,&y,&z);
    project(&x,&y,&z,a,b,c,d);
    printf("The projection is (%lf,%lf,%lf)\n",x,y,z);
    return 0;
}
