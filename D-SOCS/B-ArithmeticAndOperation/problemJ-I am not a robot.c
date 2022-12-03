#include <stdio.h>

int main(){
    float x,y;
    scanf("%f %f", &x,&y);
    float result = y/x*100;
    printf("%.4f%%\n",result);
    return 0;
}