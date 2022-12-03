#include <stdio.h>

int main(){
    int x;
    double y, result;
    scanf("%d %lf",&x,&y);
    result = x * (1 +y/100) * (1 +y/100) * (1 +y/100);
    printf("%.2f\n", result);
}
