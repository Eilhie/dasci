#include <stdio.h>

int main(){

    double x,y;
    scanf("%lf %lf",&x,&y);
    double result = 100-((y-x)/y * 100);
    printf("%.2f%%\n", result);

    return 0;
}